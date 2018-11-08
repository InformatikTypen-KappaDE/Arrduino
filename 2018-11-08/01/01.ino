float runtime;
int LedRed = 8;
int LedGreen = 9;
int buttonRed = 11;
int buttonGreen = 12;


void setup() {
  Serial.begin(9600);
pinMode (LedRed, OUTPUT);
pinMode (LedGreen, OUTPUT);
pinMode (buttonRed, INPUT_PULLUP);
pinMode (buttonGreen, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

}
