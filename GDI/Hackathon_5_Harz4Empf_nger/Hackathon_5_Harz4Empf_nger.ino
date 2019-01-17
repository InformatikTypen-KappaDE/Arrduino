#include <SoftwareSerial.h>

SoftwareSerial inputSerial(10, 11);

int pinLed1R;
int pinLed2Y;
int pinLed3G;
int pinLed4R;
int pinLed5Y;

void setup() {
  Serial.begin(9600);
  inputSerial.begin(9600);
}

void loop() {
  Serial.println(inputSerial.read);

}
