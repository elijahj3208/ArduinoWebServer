#include <ESP8266WiFi.h>

class WiFiConnection
{
  public :
  
    WiFiConnection(int serialBaudRate, char* ssid, char* password, char* deviceName, IPAddress staticIP, IPAddress gateway, IPAddress subnet);
    void connectToInternet();
    static bool isConnectedToInternet();

  private :

    int _serialBaudRate;
  
    char* _ssid;
    char* _password;
    char* _deviceName;

    IPAddress _staticIP;
    IPAddress _gatewayIPAddress;
    IPAddress _subnetM;    
};

WiFiConnection::WiFiConnection(int serialBaudRate, char* ssid, char* password, char* deviceName, IPAddress staticIP, IPAddress gatewayIPAddress, IPAddress subnetM)
{
  _serialBaudRate = serialBaudRate;
  _ssid = ssid;
  _password = password;
  _deviceName = deviceName;
  _staticIP = staticIP;
  _gatewayIPAddress = gatewayIPAddress;
  _subnetM = subnetM;
}

void WiFiConnection::connectToInternet()
{
Serial.printf("Connecting to %s\n", _ssid);
WiFi.mode(WIFI_STA);
WiFi.config(_staticIP, _gatewayIPAddress, _subnetM);
WiFi.hostname(_deviceName);
WiFi.begin(_ssid, _password);
Serial.println();

while(WiFi.status() != WL_CONNECTED)
{
  Serial.print(".");
  delay(500);  
}

Serial.println();
Serial.printf("Connected successfully to %s\n", _ssid);
Serial.println();
}

bool WiFiConnection::isConnectedToInternet()
{
  bool output = false;

  if(WiFi.status() == WL_CONNECTED)
  {
    output = true;
  }

  return output;
}
