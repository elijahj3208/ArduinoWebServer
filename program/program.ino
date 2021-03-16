#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include "WiFiConnection.h"
#include "PinModel.h"

int serialBaudRate = 9600;

char* ssid = "*****";
char* password = "*****";
char* deviceName = "Arduino_WiFi_Device";

IPAddress staticIP(192,168,86,40);
IPAddress gatewayIPAddress(192,168,86,1);
IPAddress subnetM(255,255,255,0);

ESP8266WebServer server (80);

void setup() 
{
  Serial.begin(serialBaudRate);
  
  WiFiConnection wifi(serialBaudRate, ssid, password, deviceName, staticIP, gatewayIPAddress, subnetM);
  wifi.connectToInternet(); 

  startMyServer(); 

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

}

void loop() 
{
  server.handleClient();  
}
