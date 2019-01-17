#include <SoftwareSerial.h>
String signalsent
SoftwareSerial inputSerial(10, 11);
bool valid = 1;
int pinLed1R;
int pinLed2Y;
int pinLed3G;
int pinLed4R;
int pinLed5Y;
bool b2;
bool b3;
bool b4;
bool b5;
bool b6;
void setup() {
  Serial.begin(9600);
  inputSerial.begin(9600);
}

void loop() {
  Serial.println(inputSerial.readString());
  signalsent = inputSerial.readString();
  if (signalsent[0] = '^' && signalsent[1] = 'W' && signalsent[10] = '$' &&
                      signalsent[11] = '\n') {
    Sendbyte = inputSerial.readString().substring(2, 9);
    for (int i = 0; i < 8; i++) {
      if (valid && (Sendbyte[i] = 0 || Sendbyte[i] = 1)) {
Sendbyte[5] = b6;
  Sendbyte[6] = b5;
  Sendbyte[7] = b4;
  Sendbyte[8] = b3;
  Sendbyte[9] = b2;
      } else if (i = 0) {
        valid = 1;
      } else {
        valid = 0;
      }
    }
  }

}
}
