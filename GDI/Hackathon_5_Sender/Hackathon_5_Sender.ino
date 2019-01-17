#include <SoftwareSerial.h>

SoftwareSerial outputSerial(10, 11);
int pinB2;
int pinB3;
int pinB4;
int pinB5;
int pinB6;

bool b2;
bool b3;
bool b4;
bool b5;
bool b6;

void setup() {
  Serial.begin(9600);
  outputSerial.begin(9600);
}

char sendByte[12];

void loop() {
  b2 = digitalRead(pinB2);
  b3 = digitalRead(pinB3);
  b4 = digitalRead(pinB4);
  b5 = digitalRead(pinB5);
  b6 = digitalRead(pinB6);

  sendByte[0] = '^';
  sendByte[1] = 'W';
  sendByte[2] = '0';
  sendByte[3] = '0';
  sendByte[4] = '0';
  sendByte[5] = b6;
  sendByte[6] = b5;
  sendByte[7] = b4;
  sendByte[8] = b3;
  sendByte[9] = b2;
  sendByte[10] = '$';
  sendByte[11] = '\n';
  
  outputSerial.write(sendByte, 11);
}
