
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
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  } 
}
