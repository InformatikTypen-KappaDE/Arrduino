float waitTime;
float runtime;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

}
void blinkA() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  delay(1000);
}

void longPause() {
  delay(4000);
}
void loop() {
blinkA();
blinkA();
longPause();
}
