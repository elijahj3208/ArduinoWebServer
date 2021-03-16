
void startMyServer()
{
  server.on("/", [](){server.send(200, "text/plain", "Hello World!");});
  server.on("/blink", blinkLed);
  server.on("/pin", setPinFromJson);
  server.begin();
}
