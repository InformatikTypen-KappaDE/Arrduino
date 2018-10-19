bool getRuntime;
float waitTime;
getRuntime = 0;
void setup() {

}

void loop() {
  float runtime() {
    if (getRuntime = 1) {
      return millis();
    }
    else {
      return 0;
    }
  }
  waitTime = constrain((sin(runtime)+1.05)*1500, 50, 3000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(waitTime);
  digitalWrite(LED_BUILTIN, LOW);
  delay(waitTime);
  /*
  digitalWrite(LED_BUILTIN, HIGH);
  delay(waitTime);
  digitalWrite(LED_BUILTIN, LOW);
  delay(3*waitTime);
  */
}
