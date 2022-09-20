#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "WifiMamalona";
const char* password = "1234";



IPAddress ip(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);

WebServer server(80);

String answer = "<!DOCTYPE html>\
<html>\
<body>\
<h1>Ese Dulcey si es put0 ve, ois ve champuss sexo</h1>\
</body>\
</html>";


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




