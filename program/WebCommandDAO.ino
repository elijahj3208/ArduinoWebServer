
void checkWiFiConnection()
{
  if(WiFiConnection::isConnectedToInternet())
    {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN, LOW);
      delay(1000);
    }
}

void blinkLed()
{
  for(int i = 0; i < 10; i++)
  {
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  } 
}

void setPinFromJson()
{
  PinModel newPin;
  String data = server.arg("plain");
  StaticJsonDocument<200> jDocument;
  DeserializationError err = deserializeJson(jDocument, data);
  String pinNum = jDocument["pin"];
  String level = jDocument["level"];
  
  newPin.setPinNum(pinNum.toInt());
  newPin.setLevelState(level.toInt());  
  togglePin(newPin);
}

void togglePin(PinModel pin)
{
  pinMode(pin.getPin(), OUTPUT);
  digitalWrite(pin.getPin(), pin.getLevel());
}
