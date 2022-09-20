#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "WifiMamalona";
const char* password = "1234";



IPAddress ip(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);

WebServer server(80);

String answer = "<!DOCTYPE html>\n<html lang=\"en\">\n  <head>\n    <meta charset=\"UTF-8\" />\n    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\" />\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />\n    <title>Document</title>\n    <style type=\"text/css\">\n      body {\n        display: flex;\n        flex-direction: column;\n        justify-content: center;\n        align-items: center;\n      }\n      .content {\n        display: flex;\n        flex-direction: row;\n        justify-content: center;\n        align-items: center;\n        background: #d9d9d9;\n        height: 220px;\n        width: 888px;\n      }\n      .content-title {\n        display: flex;\n        justify-content: center;\n      }\n      .button-content {\n        display: flex;\n        flex-direction: column;\n        justify-content: center;\n        align-items: center;\n        width: 296px;\n      }\n      .button-circle-content {\n        display: flex;\n        flex-direction: row;\n        justify-content: center;\n        align-items: center;\n        width: 296px;\n        justify-content: space-evenly;\n        padding: 20px;\n      }\n      .useless-button-content {\n        display: flex;\n        flex-direction: row;\n        align-items: flex-end;\n        width: 296px;\n        height: 220px;\n        justify-content: space-evenly;\n        padding: 40px;\n      }\n      .title {\n        font-size: 78px;\n      }\n      .arrow-button {\n        background: #000;\n        height: 50px;\n        width: 50px;\n        border-radius: 6px;\n        margin: -3px;\n        cursor: pointer;\n      }\n      .arrow-color {\n        font: #e42424;\n      }\n      .circle-button {\n        border-radius: 50px;\n        height: 50px;\n        width: 50px;\n        border: 0;\n        background-color: #ff0404;\n        font-size: 26px;\n        color: #fff;\n        display: flex;\n        justify-content: center;\n        text-decoration: none;  \n      }\n      .not-useless-button{\n        border-radius: 20px;\n        height: 30px;\n        width: 80px;\n        border: 0;\n        background-color: #514E4E;\n        color: #fff;\n        display: flex;\n        justify-content: center;\n        text-decoration: none;\n        cursor: pointer;\n      }\n      .btn{\n        display: flex;\n        flex-direction: row;\n      }\n    </style>\n  </head>\n  <body>\n    <div class=\"content-title\">\n      <p class=\"title\">Reto M&T</p>\n    </div>\n    <div class=\"content\">\n      <div class=\"button-content\">\n        <a class=\"arrow-button\"><i class=\"fa-solid fa-arrow-up\"></i></i></a>\n        <div class=\"btn\">\n          <a class=\"arrow-button\"><i class=\"fa-solid fa-up\"></i></a>\n          <a class=\"arrow-button\"><i class=\"fa-solid fa-up\"></i></a>\n          <a class=\"arrow-button\"><i class=\"fa-solid fa-up\"></i></a>\n        </div>\n        <a class=\"arrow-button\"><i class=\"fa-solid fa-up\"></i></a>\n      </div>\n      <div class=\"useless-button-content\">\n        <a class=\"not-useless-button\">STOP</a>\n        <a class=\"not-useless-button\">ARRÊT</a>\n      </div>\n      <div class=\"button-circle-content\">\n        <a class=\"circle-button\">B</a>\n        <a class=\"circle-button\">A</a>\n      </div>\n    </div>\n    <script\n      src=\"https://kit.fontawesome.com/4381238124.js\"\n      crossorigin=\"anonymous\"\n    ></script>\n  </body>\n</html>\n";



void handleConnectionRoot()
{
  server.send(200, "text/html",answer);
}

void handleAdelante()
{

}


void handleAtras()
{

}


void setup()
{
Serial.begin(115200);

 WiFi.softAP(ssid, password);
 WiFi.softAPConfig(ip, gateway, subnet);

 Serial.print("Nombr: ");
 Serial.println(ssid);
 server.on("/",handleConnectionRoot);
 server.on("/adelante",handleAdelante);
 server.on("/atras",handleAtras);

 server.begin();
 Serial.println("Se prendio esta mierda");
 delay(150);
 
      
}

void loop()
{
  server.handleClient();
}




