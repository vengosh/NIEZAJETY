#include <MD_MAX72xx.h>
#include <SPI.h>
#include <String.h>
#include <WiFi.h>
#include <HTTPServer.hpp>
#include <HTTPRequest.hpp>
#include <HTTPResponse.hpp>
#include <UselessHelper.cpp>
#include <util.hpp>
#include <Arduino_JSON.h>
#include <string.h>
#include <HTTPClient.h>
#include <StreamString.h>

#define USE_POT_CONTROL 1
#define PRINT_CALLBACK  0

#define PRINT(s, v) { Serial.print(F(s)); Serial.print(v); }
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 4

#define CLK_PIN   18  // or SCK
#define DATA_PIN  23  // or MOSI
#define CS_PIN    5  // or SS


MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// Scrolling parameters
#if USE_POT_CONTROL
#define SPEED_IN  A5
#else
#define SCROLL_DELAY  75  // in milliseconds
#endif // USE_POT_CONTROL

#define CHAR_SPACING  1 // pixels between characters

// Global message buffers shared by Serial and Scrolling functions
#define BUF_SIZE  75
char curMessage[BUF_SIZE];
char newMessage[BUF_SIZE];
bool newMessageAvailable = false;
String GLOBALMSG = " WOLNY !!! ";

bool GLOBALCHGFLAG = false;

double GLOBALTEMPERATURA = -1.00;
double GLOBALWILGOTNOSC = -1.00;
double GLOBALCISNIENIE = -1.00;
double GLOBALPREVTEMPERATURA = -1.00;
double GLOBALPREVWILGOTNOSC = -1.00;
double GLOBALPREVCISNIENIE = -1.00;
bool GLOBALTRYBAUTO = true;
int GLOBALOKNO = -1; 
UselessHelper uHelper;

uint16_t  scrollDelay;  // in milliseconds

void setGLOBALMSG(String newMsg){
    String replaced = newMsg;
    replaced.replace("%20"," ");
    replaced = (" #~~" + replaced + "~~# ");
    GLOBALMSG = replaced;
    GLOBALCHGFLAG = true;
}


void readSerial(void)
{
  static uint8_t  putIndex = 0;

  do{
    newMessage[putIndex] = (char)Serial.read();
    if ((newMessage[putIndex] == '\n') || (putIndex >= BUF_SIZE-3)) // end of message character or full buffer
    {
         // put in a message separator and end the string
      newMessage[putIndex++] = ' ';
      newMessage[putIndex] = '\0';
      // restart the index for next filling spree and flag we have a message waiting
      putIndex = 0;
      newMessageAvailable = true;
    }
    else if (newMessage[putIndex] != '\r')
      // Just save the next char in next location
      putIndex++;  
    
  }
  while (Serial.available());
}

void scrollDataSink(uint8_t dev, MD_MAX72XX::transformType_t t, uint8_t col)
// Callback function for data that is being scrolled off the display
{
#if PRINT_CALLBACK
  Serial.print("\n cb ");
  Serial.print(dev);
  Serial.print(' ');
  Serial.print(t);
  Serial.print(' ');
  Serial.println(col);
#endif
}

uint8_t scrollDataSource(uint8_t dev, MD_MAX72XX::transformType_t t)
// Callback function for data that is required for scrolling into the display
{
  static char   *p = curMessage;
  static uint8_t  state = 0;
  static uint8_t  curLen, showLen;
  static uint8_t  cBuf[8];
  uint8_t colData;

  // finite state machine to control what we do on the callback
  switch(state)
  {
    case 0: // Load the next character from the font table
      showLen = mx.getChar(*p++, sizeof(cBuf)/sizeof(cBuf[0]), cBuf);
      curLen = 0;
      state++;

      // if we reached end of message, reset the message pointer
      if (*p == '\0')
      {
        p = curMessage;     // reset the pointer to start of message
        if (newMessageAvailable)  // there is a new message waiting
        {
          //strcpy(curMessage, newMessage);	// copy it in
          strcpy(curMessage,  UselessHelper::convertStringToCharArray(GLOBALMSG));
          newMessageAvailable = false;
        }
      }
      // !! deliberately fall through to next state to start displaying

    case 1: // display the next part of the character
      colData = cBuf[curLen++];
      if (curLen == showLen)
      {
        showLen = CHAR_SPACING;
        curLen = 0;
        state = 2;
      }
      break;

    case 2: // display inter-character spacing (blank column)
      colData = 0;
      if (curLen == showLen)
        state = 0;
      curLen++;
      break;

    default:
      state = 0;
  }

  return(colData);
}

 void scrollText(void)
{
  static uint32_t	prevTime = 0;

  // Is it time to scroll the text?
  if (millis()-prevTime >= scrollDelay)
  {
    mx.transform(MD_MAX72XX::TSL);  // scroll along - the callback will load all the data
    prevTime = millis();      // starting point for next time
  }
}

uint16_t getScrollDelay(void)
{
#if USE_POT_CONTROL
  uint16_t  t;

  t = analogRead(SPEED_IN);
  t = map(t, 0, 1023, 25, 250);

  return(t);
#else
  return(SCROLL_DELAY);
#endif
}

#define WIFI_SSID "CzajnikBezprzewodowy"
#define WIFI_PSK  "bieda1234"

using namespace httpsserver;

HTTPServer insecureServer = HTTPServer(80);
void handleRoot(HTTPRequest * req, HTTPResponse * res);
void handleExternal(HTTPRequest * req, HTTPResponse * res);
void handle404(HTTPRequest * req, HTTPResponse * res);
void handleURLParam(HTTPRequest * req, HTTPResponse * res);
void handleNiezajety(HTTPRequest * req, HTTPResponse * res);
void handleGetJSON(HTTPRequest * req, HTTPResponse * res);
void handleGetWeatherStationData(HTTPRequest * req, HTTPResponse * res);
void middlewareLogging(HTTPRequest * req, HTTPResponse * res, std::function<void()> next);
void setup()
{
  mx.begin();
  mx.setShiftDataInCallback(scrollDataSource);
  mx.setShiftDataOutCallback(scrollDataSink);

  

#if USE_POT_CONTROL
  pinMode(SPEED_IN, INPUT);
#else
  scrollDelay = SCROLL_DELAY;
#endif

  
  Serial.begin(115200);
	// Connect to WiFi
	Serial.println("Setting up WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PSK);
	while (WiFi.status() != WL_CONNECTED) {
	  Serial.print(".");
	  delay(5000);
	}
	Serial.print("Connected. IP=");
	Serial.println(WiFi.localIP());
  setGLOBALMSG(WiFi.localIP().toString());
  //String s = WiFI->localIP().toString();
	Serial.println("Creating server task... ");  
  ResourceNode * nodeRoot    = new ResourceNode("/", "GET", &handleRoot);
  ResourceNode * nodeNiezajetyRoot    = new ResourceNode("/niezajety*", "GET", &handleRoot);
  ResourceNode * nodeExternal    = new ResourceNode("/external/*", "GET", &handleExternal);
	ResourceNode * node404     = new ResourceNode("", "GET", &handle404);
  ResourceNode * nodeURLParam = new ResourceNode("/set/*", "GET", &handleURLParam);
  ResourceNode * nodeNiezajety = new ResourceNode("/text/*", "GET", &handleNiezajety);
  ResourceNode * apiNode = new ResourceNode("/api/data", "GET", &handleGetJSON);
  ResourceNode * weatherStationDataNode = new ResourceNode("/api/weatherdata/realtimegauges.txt", "GET", &handleGetWeatherStationData);


	insecureServer.registerNode(nodeRoot);
  insecureServer.registerNode(nodeNiezajetyRoot);
  insecureServer.registerNode(nodeExternal);
  insecureServer.registerNode(nodeURLParam);
  insecureServer.setDefaultNode(node404);
  insecureServer.registerNode(nodeNiezajety);
  insecureServer.registerNode(apiNode);
  insecureServer.registerNode(weatherStationDataNode);
  insecureServer.addMiddleware(&middlewareLogging);
  
	Serial.println("Starting server...");
	insecureServer.start();
	if (insecureServer.isRunning()) {
		Serial.println("Server ready.");
		
	}  
  
}

void loop()
{
  scrollDelay = getScrollDelay();
  if(GLOBALCHGFLAG){
    strcpy(curMessage,  UselessHelper::convertStringToCharArray(GLOBALMSG));
    newMessage[0] = '\0';
    GLOBALCHGFLAG = false;
  }
  scrollText();
    insecureServer.loop();
}

void updatePreviousValues(void){
  GLOBALPREVTEMPERATURA = GLOBALTEMPERATURA;
  GLOBALPREVWILGOTNOSC = GLOBALWILGOTNOSC;
  GLOBALPREVCISNIENIE = GLOBALCISNIENIE;
}
void updateCurrentValues(void){
  uHelper = UselessHelper();
  updatePreviousValues();
  GLOBALTEMPERATURA = uHelper.Radom(10.00,40.00);
  GLOBALWILGOTNOSC = uHelper.Radom(10.00,80.00);
  GLOBALCISNIENIE = uHelper.Radom(900.00,1100.00);
  
}

String generateHTML2(void){
  updateCurrentValues();
  String arr[3] = { (GLOBALTRYBAUTO ? "true" : "false"),String(GLOBALOKNO),""};
  return uHelper.BuildHTMLStr(arr);
}


String generateHTMLnz(void){
  uHelper = UselessHelper();
  return uHelper.BuildNiezajetyHTMLStr();
}

void handleRoot(HTTPRequest * req, HTTPResponse * res) {
  res->setStatusCode(200);
	res->setStatusText("OK");
	res->setHeader("Content-Type","text/html");
  res->setHeader("Accept","*/*");
  res->setHeader("Access-Control-Allow-Origin","*"); 
  res->setHeader("Access-Control-Allow-Methods", "GET,POST,OPTIONS");
  res->setHeader("Referer", "http://gbulawa.nazwa.pl/CDN/ajot/NIEZAJETY/");
  res->setHeader("HOST", "gbulawa.nazwa.pl");
	std::string reqStr = req -> getRequestString();
  if(reqStr.find("niezajety")!=std::string::npos){
    res->print(generateHTMLnz());	
  }else{
    res->print(generateHTML2());
  }
  res -> finalize();
}
void handleExternal(HTTPRequest * req, HTTPResponse * res) {
 	 std::string reqUrl1 = "http://gbulawa.nazwa.pl/CDN/ajot/NIEZAJETY";
   reqUrl1 += req -> getRequestString();
   res -> setHeader("Location",reqUrl1);
   res -> setStatusCode(302);
   res -> finalize();
}

void handleURLParam(HTTPRequest * req, HTTPResponse * res) {
  std::string  reqStr =  req->getRequestString();
  if(reqStr.find("auto")!=std::string::npos){
	  res->println("\nPrzechodze na sterowanie automatyczne!");
    GLOBALTRYBAUTO = true;
  }else if(reqStr.find("manual")!=std::string::npos){
	  res->println("\nPrzechodze na sterowanie reczne!");
    GLOBALTRYBAUTO = false;
  }else if(reqStr.find("open")!=std::string::npos){
    res->println("\n\nTakie tam pierdolenie, otwieram uokno!");
    GLOBALTRYBAUTO = false;
    GLOBALOKNO = 1;
  }else if(reqStr.find("closed")!=std::string::npos){
    res->println("\n\nTakie tam pierdolenie, zamykam uokno!");
    GLOBALTRYBAUTO = false;
    GLOBALOKNO = -1;
  }
  res -> setHeader("Location","/");
  res -> setStatusCode(302);
  res -> finalize();
}
void handleNiezajety(HTTPRequest * req, HTTPResponse * res) {
	ResourceParameters * params = req->getParams();
  setGLOBALMSG((params->getUrlParameter(0)).c_str());
  res -> setHeader("Location","/niezajety");
  res -> setStatusCode(302);
  res -> finalize();
}
using namespace std;
void handle404(HTTPRequest * req, HTTPResponse * res) {
  req->discardRequestBody();
	res->setStatusCode(404);
	res->setStatusText("Nie weszles!");  
  res -> finalize();
}

void handleGetJSON(HTTPRequest * req, HTTPResponse * res) {
	//zainicjuj zmienne
  updateCurrentValues();
  //nakurwiaj JSONem
  JSONVar myArray;  
   myArray[0][0] = String("valTemperature");
   myArray[0][1] = GLOBALTEMPERATURA;
   myArray[1][0] = String("valHumidity");
   myArray[1][1] = GLOBALWILGOTNOSC;
   myArray[2][0] = String("valWindowState");
   myArray[2][1] = GLOBALOKNO;
   myArray[3][0] = String("valAutoMode");
   myArray[3][1] = GLOBALTRYBAUTO;
   myArray[4][0] = String("valPress");
   myArray[4][1] = GLOBALCISNIENIE;

  String jsonString = JSON.stringify(myArray);
  res->setStatusCode(200);
	res->setHeader("Content-Type", "application/json");
	res->print(jsonString);
}

void handleGetWeatherStationData(HTTPRequest * req, HTTPResponse * res) {
	//zainicjuj zmienne
  updateCurrentValues();
  double GTFahnrheits = (1.80*(GLOBALTEMPERATURA))+32.00;

  res->setStatusCode(200);
	res->setHeader("Content-Type", "text/plain");
  res->setHeader("Accept","*/*");
  res->setHeader("Access-Control-Allow-Origin","*"); 
  res->setHeader("Access-Control-Allow-Methods", "GET,POST,OPTIONS");
  res->setHeader("Referer", "http://gbulawa.nazwa.pl/CDN/ajot/NIEZAJETY/");
	res->print(uHelper.BuildWeatherStationDataTxt(GLOBALTEMPERATURA, GTFahnrheits, GLOBALWILGOTNOSC,GLOBALCISNIENIE,GLOBALPREVTEMPERATURA,GLOBALPREVWILGOTNOSC,GLOBALPREVCISNIENIE));//jsonString);
  res -> finalize();
}

void middlewareLogging(HTTPRequest * req, HTTPResponse * res, std::function<void()> next) {
	// We want to print the response status, so we need to call next() first.
	next();
	// After the call, the status is (hopefully) set by the handler function, so we can
	// access it for logging.
	Serial.printf("middlewareLogging(): %3d\t%s\t\t%s\n",
			// Status code (like: 200)
			res->getStatusCode(),
			// Method used for the request (like: GET)
			req->getMethod().c_str(),
			// Request string (like /index.html)
			req->getRequestString().c_str());
}
