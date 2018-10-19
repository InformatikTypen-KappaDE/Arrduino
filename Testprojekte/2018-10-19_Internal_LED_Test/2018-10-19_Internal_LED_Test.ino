float waitTime;
float runtime;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  waitTime = 1000;
  Serial.begin(9600);
}

void loop() {
  runtime = millis()*0.0003;
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
