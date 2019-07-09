#include <iostream>
#include <WString.h>
#include <HardwareSerial.h>
#include <set>
#include <array>
#include <vector>
#include <string>
#include <numeric>
#include <deque>
#include <algorithm>
#include <StreamString.h>
#define PRINT(s, v) { Serial.print(F(s)); Serial.print(v); }








class UselessHelper {
    
    public : 
        String outerHTML;   
        UselessHelper(){
            //outerHTML = BuildHTMLStr(pArray);
        }
        String BuildHTMLStr(String* arrPar)    {
            String ptr = "";
            	ptr += "<!DOCTYPE html>\n";
                ptr += "<html lang=\"en\">\n";
                ptr += "  <head>\n";
                ptr += "    <meta charset=\"utf-8\">\n";
                ptr += "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n";
                ptr += "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
                ptr += "    <meta name=\"description\" content=\"\">\n";
                ptr += "    <meta name=\"author\" content=\"\">\n";
                ptr += "    <title>CENTRUM DOWODZENIA";
                ptr += "    </title>\n";
                ptr += "    <link href=\"/external/assets/bootstrap.min.css\" rel=\"stylesheet\">\n";
		        ptr += "    <link href=\"/external/assets/styles.css\" rel=\"stylesheet\">";
                ptr += "    <link rel=\"stylesheet\" href=\"/external/assets/gauges-ss.css\">\n";
                ptr += "</head>\n";
                ptr += "<body>\n";
                ptr += "<div id=\"hiddenInputs\">\n";
                ptr += "<form name=\"hiddenInputParams\">\n";
                String append = "";
                int numElements = sizeof(arrPar);
                for(int elements = 0; elements<numElements-1; elements++){
                    if(arrPar[elements]!= "" && arrPar[elements]!= "\r" && arrPar[elements]!= "\n" && arrPar[elements]!= "\0"){
                        append += ("<input type=\"hidden\" id=\"hidInptValNum"+String(elements)+"\" value=\""+arrPar[elements]+"\">\n");
                    }
                }
                ptr += append;
                ptr += "</form>\n";
                ptr += "</div>\n";
                ptr += "<div id=\"loader\" class=\"loaderVisible\" ><svg class=\"lds-gear-set\" width=\"55%\"  height=\"55%\"  xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" viewBox=\"0 0 100 100\" preserveAspectRatio=\"xMidYMid\" style=\"background: none;\"><g transform=\"translate(50 50)\"> <g transform=\"translate(-17 -17) scale(0.5)\"> <g transform=\"rotate(17.8409)\">%0A<animateTransform attributeName=\"transform\" type=\"rotate\" values=\"0;360\" keyTimes=\"0;1\" dur=\"1s\" begin=\"0s\" repeatCount=\"indefinite\"></animateTransform><path d=\"M37.3496987939662 -7 L47.3496987939662 -7 L47.3496987939662 7 L37.3496987939662 7 A38 38 0 0 1 31.359972760794346 21.46047782418268 L31.359972760794346 21.46047782418268 L38.431040572659825 28.531545636048154 L28.531545636048154 38.431040572659825 L21.46047782418268 31.359972760794346 A38 38 0 0 1 7.0000000000000036 37.3496987939662 L7.0000000000000036 37.3496987939662 L7.000000000000004 47.3496987939662 L-6.999999999999999 47.3496987939662 L-7 37.3496987939662 A38 38 0 0 1 -21.46047782418268 31.35997276079435 L-21.46047782418268 31.35997276079435 L-28.531545636048154 38.431040572659825 L-38.43104057265982 28.531545636048158 L-31.359972760794346 21.460477824182682 A38 38 0 0 1 -37.3496987939662 7.000000000000007 L-37.3496987939662 7.000000000000007 L-47.3496987939662 7.000000000000008 L-47.3496987939662 -6.9999999999999964 L-37.3496987939662 -6.999999999999997 A38 38 0 0 1 -31.35997276079435 -21.460477824182675 L-31.35997276079435 -21.460477824182675 L-38.431040572659825 -28.531545636048147 L-28.53154563604818 -38.4310405726598 L-21.4604778241827 -31.35997276079433 A38 38 0 0 1 -6.999999999999992 -37.3496987939662 L-6.999999999999992 -37.3496987939662 L-6.999999999999994 -47.3496987939662 L6.999999999999977 -47.3496987939662 L6.999999999999979 -37.3496987939662 A38 38 0 0 1 21.460477824182686 -31.359972760794342 L21.460477824182686 -31.359972760794342 L28.531545636048158 -38.43104057265982 L38.4310405726598 -28.53154563604818 L31.35997276079433 -21.4604778241827 A38 38 0 0 1 37.3496987939662 -6.999999999999995 M0 -23A23 23 0 1 0 0 23 A23 23 0 1 0 0 -23\" fill=\"#ec1c24\"></path></g></g> <g transform=\"translate(0 22) scale(0.4)\"> <g transform=\"rotate(319.659)\">%0A<animateTransform attributeName=\"transform\" type=\"rotate\" values=\"360;0\" keyTimes=\"0;1\" dur=\"1s\" begin=\"-0.0625s\" repeatCount=\"indefinite\"></animateTransform><path d=\"M37.3496987939662 -7 L47.3496987939662 -7 L47.3496987939662 7 L37.3496987939662 7 A38 38 0 0 1 31.359972760794346 21.46047782418268 L31.359972760794346 21.46047782418268 L38.431040572659825 28.531545636048154 L28.531545636048154 38.431040572659825 L21.46047782418268 31.359972760794346 A38 38 0 0 1 7.0000000000000036 37.3496987939662 L7.0000000000000036 37.3496987939662 L7.000000000000004 47.3496987939662 L-6.999999999999999 47.3496987939662 L-7 37.3496987939662 A38 38 0 0 1 -21.46047782418268 31.35997276079435 L-21.46047782418268 31.35997276079435 L-28.531545636048154 38.431040572659825 L-38.43104057265982 28.531545636048158 L-31.359972760794346 21.460477824182682 A38 38 0 0 1 -37.3496987939662 7.000000000000007 L-37.3496987939662 7.000000000000007 L-47.3496987939662 7.000000000000008 L-47.3496987939662 -6.9999999999999964 L-37.3496987939662 -6.999999999999997 A38 38 0 0 1 -31.35997276079435 -21.460477824182675 L-31.35997276079435 -21.460477824182675 L-38.431040572659825 -28.531545636048147 L-28.53154563604818 -38.4310405726598 L-21.4604778241827 -31.35997276079433 A38 38 0 0 1 -6.999999999999992 -37.3496987939662 L-6.999999999999992 -37.3496987939662 L-6.999999999999994 -47.3496987939662 L6.999999999999977 -47.3496987939662 L6.999999999999979 -37.3496987939662 A38 38 0 0 1 21.460477824182686 -31.359972760794342 L21.460477824182686 -31.359972760794342 L28.531545636048158 -38.43104057265982 L38.4310405726598 -28.53154563604818 L31.35997276079433 -21.4604778241827 A38 38 0 0 1 37.3496987939662 -6.999999999999995 M0 -23A23 23 0 1 0 0 23 A23 23 0 1 0 0 -23\" fill=\"#fdbd10\"></path></g></g> <g transform=\"translate(28 4) scale(0.3)\"> <g transform=\"rotate(40.3409)\">%0A<animateTransform attributeName=\"transform\" type=\"rotate\" values=\"0;360\" keyTimes=\"0;1\" dur=\"1s\" begin=\"-0.0625s\" repeatCount=\"indefinite\"></animateTransform><path d=\"M37.3496987939662 -7 L47.3496987939662 -7 L47.3496987939662 7 L37.3496987939662 7 A38 38 0 0 1 31.359972760794346 21.46047782418268 L31.359972760794346 21.46047782418268 L38.431040572659825 28.531545636048154 L28.531545636048154 38.431040572659825 L21.46047782418268 31.359972760794346 A38 38 0 0 1 7.0000000000000036 37.3496987939662 L7.0000000000000036 37.3496987939662 L7.000000000000004 47.3496987939662 L-6.999999999999999 47.3496987939662 L-7 37.3496987939662 A38 38 0 0 1 -21.46047782418268 31.35997276079435 L-21.46047782418268 31.35997276079435 L-28.531545636048154 38.431040572659825 L-38.43104057265982 28.531545636048158 L-31.359972760794346 21.460477824182682 A38 38 0 0 1 -37.3496987939662 7.000000000000007 L-37.3496987939662 7.000000000000007 L-47.3496987939662 7.000000000000008 L-47.3496987939662 -6.9999999999999964 L-37.3496987939662 -6.999999999999997 A38 38 0 0 1 -31.35997276079435 -21.460477824182675 L-31.35997276079435 -21.460477824182675 L-38.431040572659825 -28.531545636048147 L-28.53154563604818 -38.4310405726598 L-21.4604778241827 -31.35997276079433 A38 38 0 0 1 -6.999999999999992 -37.3496987939662 L-6.999999999999992 -37.3496987939662 L-6.999999999999994 -47.3496987939662 L6.999999999999977 -47.3496987939662 L6.999999999999979 -37.3496987939662 A38 38 0 0 1 21.460477824182686 -31.359972760794342 L21.460477824182686 -31.359972760794342 L28.531545636048158 -38.43104057265982 L38.4310405726598 -28.53154563604818 L31.35997276079433 -21.4604778241827 A38 38 0 0 1 37.3496987939662 -6.999999999999995 M0 -23A23 23 0 1 0 0 23 A23 23 0 1 0 0 -23\" fill=\"#0066b2\"></path></g></g></g></svg>\n";
                ptr +="</div>\n";
                ptr += "<div class=\"containerHidden\">\n";
                ptr += "  <div class=\"row\">\n";
                ptr += "    <canvas id=\"canvas_led\" width=\"25\" height=\"25\"></canvas>&nbsp;&nbsp;&nbsp;\n";
                ptr += "    <canvas id=\"canvas_status\" width=\"550\" height=\"25\"></canvas>&nbsp;&nbsp;\n";
                ptr += "    <canvas id=\"canvas_timer\" width=\"70\" height=\"25\"></canvas>\n";
                ptr += "  </div>\n";
                ptr += "  <div class=\"row\">\n";
                ptr += "    <div class=\"gauge\">\n";
                ptr += "        <canvas id=\"canvas_temp\" class=\"gaugeSizeStd\"></canvas>\n";
                ptr += "    </div>\n";
                ptr += "    <div class=\"gauge\">\n";
                ptr += "        <canvas id=\"canvas_baro\" class=\"gaugeSizeStd\"></canvas>\n";
                ptr += "    </div>\n";
                ptr += "    <div class=\"gauge\">\n";
                ptr += "        <canvas id=\"canvas_hum\" class=\"gaugeSizeStd\"></canvas>\n";
                ptr += "    </div>\n";
                ptr += "  </div>\n";
                ptr += "</div>\n";
                ptr += "    <script\n";
                ptr += "  src=\"https://code.jquery.com/jquery-3.4.1.js\"\n";
                ptr += "  integrity=\"sha256-WpOohJOqMqqyKL9FccASB9O0KwACQJpFTUBLTYOVvVU=\"\n";
                ptr += "  crossorigin=\"anonymous\"></script>\n";
                ptr += "  <script src=\"/external/assets/kendo.all.min.js\"></script>\n";
                ptr += "  <script src=\"/external/assets/language.min.js\"></script>\n";
                ptr += "  <script src=\"/external/assets/steelseries_tween.min.js\"></script>\n";
                ptr += "  <script src=\"/external/assets/RGraph.rose.min.js\"></script>\n";
                ptr += "  <script src=\"/external/assets/gauges.js\"></script>  \n";

                ptr +="<script src=\"/external/assets/bootstrap.min.js\"></script>\n";
		        ptr +="<script src=\"/external/assets/customscript.js\"></script>\n";
		        ptr +="<script src=\"/external/assets/ie10-viewport-bug-workaround.js\"></script>\n";
                ptr +="</body></html>";
 
                return ptr; 
        }

        static const char* convertStringToCharArray(String inputStr) 
        { 
            char* charBuf = new char[inputStr.length()]; 
            inputStr.toCharArray(charBuf, inputStr.length(),0);
            return charBuf;    
        };

        static char* convertStringToCharArray2(String inputStr) 
        { 
            char* charBuf = new char[inputStr.length()]; 
            inputStr.toCharArray(charBuf, inputStr.length(),0);
            return charBuf;    
        };

        static const char* convertBasicStringToCharArray(std::string inputStr) 
        { 
            char* charBuff = new char[sizeof(inputStr)]; 
            strcpy(charBuff,inputStr.c_str());
            return charBuff;    
        } ;

        double Radom(double fMin, double fMax)
        {
            double f = (double)rand() / RAND_MAX;
            return fMin + f * (fMax - f);
        }

        static String BuildWeatherStationDataTxt(double temp, double tempfh, double humid, double press, double prevtemp, double prevhum, double prevpress){
            String pstr = String("");
                pstr += "{\"date\":\"15:41\",\n";
                pstr += "\"temp\":\"";
                pstr += String(temp,2);
                pstr += "\",\n";
                pstr += "\"tempTL\":\"";
                pstr += String(temp,2);
                pstr += "\",\n";
                pstr += "\"tempTH\":\"";
                pstr += String(temp,2);
                pstr += "\",\n";
                pstr += "\"intemp\":\"63.8\",\n";
                pstr += "\"dew\":\"32.6\",\n";
                pstr += "\"dewpointTL\":\"30.7\",\n";
                pstr += "\"dewpointTH\":\"32.8\",\n";
                pstr += "\"apptemp\":\"";
                pstr += String(tempfh,2);
                pstr += "\",\n";
                pstr += "\"apptempTL\":\"";
                pstr += String(tempfh,2);
                pstr += "\",\n";
                pstr += "\"apptempTH\":\"";
                pstr += String(tempfh,2);
                pstr += "\",\n";
                pstr += "\"wchill\":\"30.8\",\n";
                pstr += "\"wchillTL\":\"27.4\",\n";
                pstr += "\"heatindex\":\"35.2\",\n";
                pstr += "\"heatindexTH\":\"35.4\",\n";
                pstr += "\"humidex\":\"31.5\",\n";
                pstr += "\"wlatest\":\"6.0\",\n";
                pstr += "\"wspeed\":\"5.0\",\n";
                pstr += "\"wgust\":\"8.0\",\n";
                pstr += "\"wgustTM\":\"14.0\",\n";
                pstr += "\"bearing\":\"9\",\n";
                pstr += "\"avgbearing\":\"9\",\n";
                pstr += "\"press\":\"";
                pstr += String(press,2);
                pstr += "\",\n";
                pstr += "\"pressTL\":\"";
                pstr += String(press,2);
                pstr += "\",\n";
                pstr += "\"pressTH\":\"";
                pstr += String(press,2);
                pstr += "\",\n";
                pstr += "\"pressL\":\"";
                pstr += String(press,2);
                pstr += "\",\n";
                pstr += "\"pressH\":\"";
                pstr += String(press,2);
                pstr += "\",\n";
                pstr += "\"rfall\":\"0.27\",\n";
                pstr += "\"rrate\":\"0.04\",\n";
                pstr += "\"rrateTM\":\"0.11\",\n";
                pstr += "\"hum\":\"";
                pstr += String(humid,2);
                pstr += "\",\n";
                pstr += "\"humTL\":\"";
                pstr += String(humid,2);
                pstr += "\",\n";
                pstr += "\"humTH\":\"";
                pstr += String(humid,2);
                pstr += "\",\n";
                pstr += "\"inhum\":\"";                
                pstr += getTrenValStr(humid, prevhum);
                pstr += "\",\n";
                pstr += "\"SensorContactLost\":\"0\",\n";
                pstr += "\"forecast\":\"Zimno w chuj\",\n";
                pstr += "\"tempunit\":\"C\",\n";
                pstr += "\"windunit\":\"mph\",\n";
                pstr += "\"pressunit\":\"hPa\",\n";
                pstr += "\"rainunit\":\"in\",\n";
                pstr += "\"temptrend\":\"";                
                pstr += getTrenValStr(temp, prevtemp);
                pstr += "\",\n";
                pstr += "\"TtempTL\":\"05:52\",\n";
                pstr += "\"TtempTH\":\"13:39\",\n";
                pstr += "\"TdewpointTL\":\"05:52\",\n";
                pstr += "\"TdewpointTH\":\"13:09\",\n";
                pstr += "\"TapptempTL\":\"00:04\",\n";
                pstr += "\"TapptempTH\":\"13:39\",\n";
                pstr += "\"TwchillTL\":\"00:04\",\n";
                pstr += "\"TheatindexTH\":\"13:39\",\n";
                pstr += "\"TrrateTM\":\"12:21\",\n";
                pstr += "\"ThourlyrainTH\":\"14:17\",\n";
                pstr += "\"LastRainTipISO\":\"2017-04-01 15:26\",\n";
                pstr += "\"hourlyrainTH\":\"0.09\",\n";
                pstr += "\"ThumTL\":\"14:29\",\n";
                pstr += "\"ThumTH\":\"00:00\",\n";
                pstr += "\"TpressTL\":\"00:00\",\n";
                pstr += "\"TpressTH\":\"10:18\",\n";
                pstr += "\"presstrendval\":\"";                
                pstr += getTrenValStr(press, prevpress);
                pstr += "\",\n";
                pstr += "\"Tbeaufort\":\"F3\",\n";
                pstr += "\"TwgustTM\":\"01:23\",\n";
                pstr += "\"windTM\":\"9.0\",\n";
                pstr += "\"bearingTM\":\"48\",\n";
                pstr += "\"timeUTC\":\"2017,4,1,21,41,16\",\n";
                pstr += "\"BearingRangeFrom10\":\"000\",\n";
                pstr += "\"BearingRangeTo10\":\"020\",\n";
                pstr += "\"UV\":\"0.0\",\n";
                pstr += "\"UVTH\":\"0.0\",\n";
                pstr += "\"SolarRad\":\"0\",\n";
                pstr += "\"SolarTM\":\"0\",\n";
                pstr += "\"CurrentSolarMax\":\"646\",\n";
                pstr += "\"domwinddir\":\"NNE\",\n";
                pstr += "\"WindRoseData\":[1377.0,1873.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],\n";
                pstr += "\"windrun\":\"49.9\",\n";
                pstr += "\"cloudbasevalue\":\"599\",\n";
                pstr += "\"cloudbaseunit\":\"ft\",\n";
                pstr += "\"version\":\"3.0.0\",\n";
                pstr += "\"build\":\"3043\",\n";
                pstr += "\"ver\":\"12\"}";
            return pstr;
        };

    static String getTrenValStr(double curr, double prev){
        double diff = 0.00;
        diff = prev - curr;
        if(diff < 0){
            return ("+" + String((-diff),2));
        }
        else{
            return ("-" + String(diff,2));
        }
    };

    String BuildNiezajetyHTMLStr()    {
            String ptr = "";
            	ptr += "<!DOCTYPE html>\n";
                ptr += "<html lang=\"en\">\n";
                ptr += "  <head>\n";
                ptr += "    <meta charset=\"utf-8\">\n";
                ptr += "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n";
                ptr += "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
                ptr += "    <meta name=\"description\" content=\"\">\n";
                ptr += "    <meta name=\"author\" content=\"\">\n";
                ptr += "    <title>CENTRUM DOWODZENIA";
                ptr += "    </title>\n";
                ptr += "    <link href=\"/external/assets/bootstrap.min.css\" rel=\"stylesheet\">\n";
		        ptr += "    <link href=\"/external/assets/styles2.css\" rel=\"stylesheet\">\n";
                ptr += "    <link href=\"/external/assets/kendo.bootstrap.min.css\" rel=\"stylesheet\">\n";
         	    ptr += "    <link href=\"/external/assets/kendo.common.min.css\" rel=\"stylesheet\">\n";
                ptr += "</head>\n";
                ptr += "<body>\n";
                ptr += "<div id=\"loader\" class=\"loaderVisible\" ><svg class=\"lds-gear-set\" width=\"55%\"  height=\"55%\"  xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" viewBox=\"0 0 100 100\" preserveAspectRatio=\"xMidYMid\" style=\"background: none;\"><g transform=\"translate(50 50)\"> <g transform=\"translate(-17 -17) scale(0.5)\"> <g transform=\"rotate(17.8409)\">%0A<animateTransform attributeName=\"transform\" type=\"rotate\" values=\"0;360\" keyTimes=\"0;1\" dur=\"1s\" begin=\"0s\" repeatCount=\"indefinite\"></animateTransform><path d=\"M37.3496987939662 -7 L47.3496987939662 -7 L47.3496987939662 7 L37.3496987939662 7 A38 38 0 0 1 31.359972760794346 21.46047782418268 L31.359972760794346 21.46047782418268 L38.431040572659825 28.531545636048154 L28.531545636048154 38.431040572659825 L21.46047782418268 31.359972760794346 A38 38 0 0 1 7.0000000000000036 37.3496987939662 L7.0000000000000036 37.3496987939662 L7.000000000000004 47.3496987939662 L-6.999999999999999 47.3496987939662 L-7 37.3496987939662 A38 38 0 0 1 -21.46047782418268 31.35997276079435 L-21.46047782418268 31.35997276079435 L-28.531545636048154 38.431040572659825 L-38.43104057265982 28.531545636048158 L-31.359972760794346 21.460477824182682 A38 38 0 0 1 -37.3496987939662 7.000000000000007 L-37.3496987939662 7.000000000000007 L-47.3496987939662 7.000000000000008 L-47.3496987939662 -6.9999999999999964 L-37.3496987939662 -6.999999999999997 A38 38 0 0 1 -31.35997276079435 -21.460477824182675 L-31.35997276079435 -21.460477824182675 L-38.431040572659825 -28.531545636048147 L-28.53154563604818 -38.4310405726598 L-21.4604778241827 -31.35997276079433 A38 38 0 0 1 -6.999999999999992 -37.3496987939662 L-6.999999999999992 -37.3496987939662 L-6.999999999999994 -47.3496987939662 L6.999999999999977 -47.3496987939662 L6.999999999999979 -37.3496987939662 A38 38 0 0 1 21.460477824182686 -31.359972760794342 L21.460477824182686 -31.359972760794342 L28.531545636048158 -38.43104057265982 L38.4310405726598 -28.53154563604818 L31.35997276079433 -21.4604778241827 A38 38 0 0 1 37.3496987939662 -6.999999999999995 M0 -23A23 23 0 1 0 0 23 A23 23 0 1 0 0 -23\" fill=\"#ec1c24\"></path></g></g> <g transform=\"translate(0 22) scale(0.4)\"> <g transform=\"rotate(319.659)\">%0A<animateTransform attributeName=\"transform\" type=\"rotate\" values=\"360;0\" keyTimes=\"0;1\" dur=\"1s\" begin=\"-0.0625s\" repeatCount=\"indefinite\"></animateTransform><path d=\"M37.3496987939662 -7 L47.3496987939662 -7 L47.3496987939662 7 L37.3496987939662 7 A38 38 0 0 1 31.359972760794346 21.46047782418268 L31.359972760794346 21.46047782418268 L38.431040572659825 28.531545636048154 L28.531545636048154 38.431040572659825 L21.46047782418268 31.359972760794346 A38 38 0 0 1 7.0000000000000036 37.3496987939662 L7.0000000000000036 37.3496987939662 L7.000000000000004 47.3496987939662 L-6.999999999999999 47.3496987939662 L-7 37.3496987939662 A38 38 0 0 1 -21.46047782418268 31.35997276079435 L-21.46047782418268 31.35997276079435 L-28.531545636048154 38.431040572659825 L-38.43104057265982 28.531545636048158 L-31.359972760794346 21.460477824182682 A38 38 0 0 1 -37.3496987939662 7.000000000000007 L-37.3496987939662 7.000000000000007 L-47.3496987939662 7.000000000000008 L-47.3496987939662 -6.9999999999999964 L-37.3496987939662 -6.999999999999997 A38 38 0 0 1 -31.35997276079435 -21.460477824182675 L-31.35997276079435 -21.460477824182675 L-38.431040572659825 -28.531545636048147 L-28.53154563604818 -38.4310405726598 L-21.4604778241827 -31.35997276079433 A38 38 0 0 1 -6.999999999999992 -37.3496987939662 L-6.999999999999992 -37.3496987939662 L-6.999999999999994 -47.3496987939662 L6.999999999999977 -47.3496987939662 L6.999999999999979 -37.3496987939662 A38 38 0 0 1 21.460477824182686 -31.359972760794342 L21.460477824182686 -31.359972760794342 L28.531545636048158 -38.43104057265982 L38.4310405726598 -28.53154563604818 L31.35997276079433 -21.4604778241827 A38 38 0 0 1 37.3496987939662 -6.999999999999995 M0 -23A23 23 0 1 0 0 23 A23 23 0 1 0 0 -23\" fill=\"#fdbd10\"></path></g></g> <g transform=\"translate(28 4) scale(0.3)\"> <g transform=\"rotate(40.3409)\">%0A<animateTransform attributeName=\"transform\" type=\"rotate\" values=\"0;360\" keyTimes=\"0;1\" dur=\"1s\" begin=\"-0.0625s\" repeatCount=\"indefinite\"></animateTransform><path d=\"M37.3496987939662 -7 L47.3496987939662 -7 L47.3496987939662 7 L37.3496987939662 7 A38 38 0 0 1 31.359972760794346 21.46047782418268 L31.359972760794346 21.46047782418268 L38.431040572659825 28.531545636048154 L28.531545636048154 38.431040572659825 L21.46047782418268 31.359972760794346 A38 38 0 0 1 7.0000000000000036 37.3496987939662 L7.0000000000000036 37.3496987939662 L7.000000000000004 47.3496987939662 L-6.999999999999999 47.3496987939662 L-7 37.3496987939662 A38 38 0 0 1 -21.46047782418268 31.35997276079435 L-21.46047782418268 31.35997276079435 L-28.531545636048154 38.431040572659825 L-38.43104057265982 28.531545636048158 L-31.359972760794346 21.460477824182682 A38 38 0 0 1 -37.3496987939662 7.000000000000007 L-37.3496987939662 7.000000000000007 L-47.3496987939662 7.000000000000008 L-47.3496987939662 -6.9999999999999964 L-37.3496987939662 -6.999999999999997 A38 38 0 0 1 -31.35997276079435 -21.460477824182675 L-31.35997276079435 -21.460477824182675 L-38.431040572659825 -28.531545636048147 L-28.53154563604818 -38.4310405726598 L-21.4604778241827 -31.35997276079433 A38 38 0 0 1 -6.999999999999992 -37.3496987939662 L-6.999999999999992 -37.3496987939662 L-6.999999999999994 -47.3496987939662 L6.999999999999977 -47.3496987939662 L6.999999999999979 -37.3496987939662 A38 38 0 0 1 21.460477824182686 -31.359972760794342 L21.460477824182686 -31.359972760794342 L28.531545636048158 -38.43104057265982 L38.4310405726598 -28.53154563604818 L31.35997276079433 -21.4604778241827 A38 38 0 0 1 37.3496987939662 -6.999999999999995 M0 -23A23 23 0 1 0 0 23 A23 23 0 1 0 0 -23\" fill=\"#0066b2\"></path></g></g></g></svg>\n";
                ptr +="</div>\n";
                ptr += "<div class=\"containerHidden\">\n";
                ptr += "<div class=\"nzDivHidden\"><label>Tekst NIEZAJETEGO: </label><input type=\"text\" id=\"setText\" ><button type=\"button\" class=\"btn btn-warning\" onclick=\"nakurwiaj();\"> USTAW  </button><br /><br /><button type=\"button\" class=\"btn btn-success\" onclick=\"wolny();\">  WOLNY  </button> <button type=\"button\" class=\"btn btn-danger\" onclick=\"zajety();\">  ZAJETY  </button> </div>\n";
                ptr += "</div>\n";
                ptr += "    <script\n";
                ptr += "  src=\"https://code.jquery.com/jquery-3.4.1.js\"\n";
                ptr += "  integrity=\"sha256-WpOohJOqMqqyKL9FccASB9O0KwACQJpFTUBLTYOVvVU=\"\n";
                ptr += "  crossorigin=\"anonymous\"></script>\n";
                ptr += "  <script src=\"/external/assets/kendo.all.min.js\"></script>\n";
                ptr +="<script src=\"/external/assets/bootstrap.min.js\"></script>\n";
		        ptr +="<script src=\"/external/assets/customscript2.js\"></script>\n";
		        ptr +="<script src=\"/external/assets/ie10-viewport-bug-workaround.js\"></script>\n";
                ptr +="</body></html>";
 
                return ptr; 
        };

    

static String buildOTAUpdateStr(void) {
    String serverIndex = "";
    serverIndex += "<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script><form method='POST' action='#' enctype='multipart/form-data' id='upload_form'><input type='file' name='update' id='file' onchange='sub(this)' style=display:none><label id='file-input' for='file'>   Choose file...</label><input type='submit' class=btn value='Update'><br><br><div id='prg'></div><br><div id='prgbar'><div id='bar'></div></div><br></form><script>function sub(obj){var fileName = obj.value.split('\\\\');document.getElementById('file-input').innerHTML = '   '+ fileName[fileName.length-1];};$('form').submit(function(e){e.preventDefault();var form = $('#upload_form')[0];var data = new FormData(form);$.ajax({url: '/',type: 'POST',data: data,contentType: false,processData:false,xhr: function() {var xhr = new window.XMLHttpRequest();xhr.upload.addEventListener('progress', function(evt) {if (evt.lengthComputable) {var per = evt.loaded / evt.total;$('#prg').html('progress: ' + Math.round(per*100) + '%');$('#bar').css('width',Math.round(per*100) + '%');}}, false);return xhr;},success:function(d, s) {console.log('success!') },error: function (a, b, c) {}});});</script><style>#file-input,input{width:100%;height:44px;border-radius:4px;margin:10px auto;font-size:15px}input{background:#f1f1f1;border:0;padding:0 15px}body{background:#3498db;font-family:sans-serif;font-size:14px;color:#777}#file-input{padding:0;border:1px solid #ddd;line-height:44px;text-align:left;display:block;cursor:pointer}#bar,#prgbar{background-color:#f1f1f1;border-radius:10px}#bar{background-color:#3498db;width:0%;height:10px}form{background:#fff;max-width:258px;margin:75px auto;padding:30px;border-radius:5px;text-align:center}.btn{background:#3498db;color:#fff;cursor:pointer}</style>";
    return serverIndex;
};

static String buildFaviconStr(void){
    return String("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"16\" height=\"16\" viewBox=\"0 0 81 81\"><defs><linearGradient id=\"a\" x1=\"50.001%\" x2=\"50.001%\" y1=\"1.631%\" y2=\"98.545%\"><stop stop-color=\"#FF1B2D\" offset=\"30%\"/><stop stop-color=\"#FA1A2C\" offset=\"43.8%\"/><stop stop-color=\"#ED1528\" offset=\"59.4%\"/><stop stop-color=\"#D60E21\" offset=\"75.8%\"/><stop stop-color=\"#B70519\" offset=\"92.7%\"/><stop stop-color=\"#A70014\" offset=\"100%\"/></linearGradient><linearGradient id=\"b\" x1=\"49.996%\" x2=\"49.996%\" y1=\".853%\" y2=\"99.607%\"><stop stop-color=\"#9C0000\" offset=\"0%\"/><stop stop-color=\"#FF4B4B\" offset=\"70%\"/></linearGradient></defs><path fill=\"url(#a)\" d=\"M26.967 62.853c-4.444-5.246-7.323-13.003-7.52-21.707v-1.894c.196-8.704 3.075-16.46 7.52-21.707 5.766-7.49 14.34-12.237 23.912-12.237 5.886 0 11.396 1.798 16.11 4.925C59.913 3.903 50.582.04 40.35.003L40.2 0C17.997 0 0 17.998 0 40.2c0 21.557 16.972 39.15 38.285 40.15.635.03 1.273.048 1.915.048 10.292 0 19.678-3.87 26.79-10.23-4.712 3.125-10.22 4.923-16.11 4.923-9.573 0-18.146-4.746-23.913-12.235z\"/><path fill=\"url(#b)\" d=\"M26.967 17.546c3.688-4.354 8.454-6.98 13.66-6.98 11.7 0 21.188 13.268 21.188 29.634s-9.486 29.634-21.19 29.634c-5.204 0-9.97-2.626-13.657-6.98 5.767 7.49 14.34 12.237 23.913 12.237 5.89 0 11.4-1.795 16.11-4.92C75.22 62.81 80.4 52.11 80.4 40.2c0-11.908-5.18-22.605-13.406-29.966C62.28 7.107 56.77 5.308 50.88 5.308c-9.573 0-18.146 4.75-23.913 12.238z\"/></svg>");
};
  
static String buildOTAUpdateStr2(void){
     

StreamString sb = StreamString();

sb.println("<!DOCTYPE html>");
sb.println("<html lang=\"en\">");
sb.println("  <head>");
sb.println("    <meta charset=\"utf-8\" />");
sb.println("    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\" />");
sb.println("    <meta name=\"viewport\" content=\"width=device-width,initial-scale=1.0\" />");
sb.println("    <meta name=\"referrer\" content=\"no-referrer\" />");
sb.println("    <title>#ESP OTA</title>");
sb.println("	 <link rel=\"stylesheet\" href=\"http://gbulawa.nazwa.pl/CDN/ajot/NIEZAJETY/assets/ota.css\">");
sb.println("  </head>");
sb.println("  <body>");
sb.println("    <noscript>");
sb.println("      <strong>Bez wlaczonych dzawaskryptow ni chuja nie zadziala!</strong>");
sb.println("    </noscript>");
sb.println("	<script type=\"text/javascript\" src=\"http://gbulawa.nazwa.pl/CDN/ajot/NIEZAJETY/assets/ota.js\"></script>");
sb.println("    <div id=\"app\" class=\"section\">");
sb.println("      <div class=\"container\">");
sb.println("        <br />");
sb.println("        <br />");
sb.println("        <div class=\"columns is-mobile is-centered\">");
sb.println("          <h1>#RARYTAJ #JEDYNYTAKI #BIALYKRUK");
sb.println("          <br />ESP32/ESP8266 OTA Firmware Updater</h1>");
sb.println("          <br />");
sb.println("        </div>");
sb.println("        <br />");
sb.println("        <br />");
sb.println("        <div class=\"columns is-mobile is-centered has-text-centered\">");
sb.println("          <div class=\"column is-12-mobile is-8-tablet is-6-desktop\">");
sb.println("            <div class=\"card\">");
sb.println("              <div class=\"card-content\">");
sb.println("                <div class=\"section\">");
sb.println("                  <div class=\"columns is-mobile is-centered\">");
sb.println("                    <div class=\"columns is-6\">");
sb.println("                      <div class=\"file has-name\">");
sb.println("                        <label class=\"file-label\">");
sb.println("                        <input type=\"file\" name=\"resume\" class=\"file-input\" />");
sb.println("                        <span class=\"file-cta\"> ");
sb.println("                        <span class=\"file-label\">Wskaz plik</span></span> ");
sb.println("                        <span class=\"file-name\">");
sb.println("                          <span>Wskaz plik</span>");
sb.println("                        </span></label>");
sb.println("                      </div>");
sb.println("                    </div>");
sb.println("                  </div>");
sb.println("                </div>");
sb.println("              </div>");
sb.println("              <div class=\"columns is-mobile is-centered has-text-centered\">");
sb.println("                <div class=\"column is-6-mobile is-8-tablet is-6-desktop\">");
sb.println("                  <button class=\"button is-fullwidth is-info\">Nakurwiaj</button>");
sb.println("                </div>");
sb.println("              </div>");
sb.println("              <br />");
sb.println("            </div>");
sb.println("          </div>");
sb.println("        </div>");
sb.println("      </div>");
sb.println("    </div>");
sb.println("  </body>");
sb.println("</html>\";\"<!DOCTYPE html>");
sb.println("<html lang=\"en\">");
sb.println("  <head>");
sb.println("    <meta charset=\"utf-8\" />");
sb.println("    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\" />");
sb.println("    <meta name=\"viewport\" content=\"width=device-width,initial-scale=1.0\" />");
sb.println("    <meta name=\"referrer\" content=\"no-referrer\" />");
sb.println("    <title>#ESP OTA</title>");
sb.println("	 <link rel=\"stylesheet\" href=\"http://gbulawa.nazwa.pl/CDN/ajot/NIEZAJETY/assets/ota.css\">");
sb.println("  </head>");
sb.println("  <body>");
sb.println("    <noscript>");
sb.println("      <strong>Bez wlaczonych dzawaskryptow ni chuja nie zadziala!</strong>");
sb.println("    </noscript>");
sb.println("	<script type=\"text/javascript\" src=\"http://gbulawa.nazwa.pl/CDN/ajot/NIEZAJETY/assets/ota.js\"></script>");
sb.println("    <div id=\"app\" class=\"section\">");
sb.println("      <div class=\"container\">");
sb.println("        <br />");
sb.println("        <br />");
sb.println("        <div class=\"columns is-mobile is-centered\" id=\"titlediv\">");
sb.println("  ");
sb.println("        </div>");
sb.println("        <br />");
sb.println("        <br />");
sb.println("        <div class=\"columns is-mobile is-centered has-text-centered\">");
sb.println("          <div class=\"column is-12-mobile is-8-tablet is-6-desktop\">");
sb.println("            <div class=\"card\">");
sb.println("              <div class=\"card-content\">");
sb.println("                <div class=\"section\">");
sb.println("                  <div class=\"columns is-mobile is-centered\">");
sb.println("                    <div class=\"columns is-6\">");
sb.println("                      <div class=\"file has-name\">");
sb.println("                        <label class=\"file-label\">");
sb.println("                        <input type=\"file\" name=\"resume\" class=\"file-input\" />");
sb.println("                        <span class=\"file-cta\"> ");
sb.println("                        <span class=\"file-label\">Wskaz plik</span></span> ");
sb.println("                        <span class=\"file-name\">");
sb.println("                          <span>Wskaz plik</span>");
sb.println("                        </span></label>");
sb.println("                      </div>");
sb.println("                    </div>");
sb.println("                  </div>");
sb.println("                </div>");
sb.println("              </div>");
sb.println("              <div class=\"columns is-mobile is-centered has-text-centered\">");
sb.println("                <div class=\"column is-6-mobile is-8-tablet is-6-desktop\">");
sb.println("                  <button class=\"button is-fullwidth is-info\">Nakurwiaj</button>");
sb.println("                </div>");
sb.println("              </div>");
sb.println("              <br />");
sb.println("            </div>");
sb.println("          </div>");
sb.println("        </div>");
sb.println("      </div>");
sb.println("    </div>");
sb.println("  </body>");
sb.println("</html>");


    return sb.readString();
};
//end of class
};


