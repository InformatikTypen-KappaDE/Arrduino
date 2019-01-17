#include <SoftwareSerial.h>

SoftwareSerial outputSerial(10, 11);
int pinB2 = 2;
int pinB3 = 3;
int pinB4 = 4;
int pinB5 = 5;
int pinB6 = 6;

bool b2;    //Fernsehen
bool b3;    //Putzen
bool b4;    //Hausverlassen
bool b5;    //Scharfes Hinsehen Gelbes und Rotes Licht
bool b6;    //Licht im Treppenhaus

bool prevB2;
bool prevB3;
bool prevB4;
bool prevB5;
bool prevB6;

void setup() {
  Serial.begin(9600);
  outputSerial.begin(9600);
  pinMode(pinB2, INPUT);
  pinMode(pinB3, INPUT);
  pinMode(pinB4, INPUT);
  pinMode(pinB5, INPUT);
  pinMode(pinB6, INPUT);
}

char sendByte[12];

void loop() {
  b2 = digitalRead(pinB2);
  b3 = digitalRead(pinB3);
  b4 = digitalRead(pinB4);
  b5 = digitalRead(pinB5);
  b6 = digitalRead(pinB6);

  if ((b2 != prevB2) || (b3 != prevB3) || (b4 != prevB4) || (b5 != prevB5) || (b6 != prevB6)) {
    sendByte[0] = '^';
    sendByte[1] = 'W';
    sendByte[2] = '0';
    sendByte[3] = '0';
    sendByte[4] = '0';
    if (b6 == HIGH) {
      sendByte[5] = '1';
    } else {
      sendByte[5] = '0';
    }
    if (b5 == HIGH) {
      sendByte[6] = '1';
    } else {
      sendByte[6] = '0';
    }
    if (b4 == HIGH) {
      sendByte[7] = '1';
    } else {
      sendByte[7] = '0';
    }
    if (b3 == HIGH) {
      sendByte[8] = '1';
    } else {
      sendByte[8] = '0';
    }
    if (b2 == HIGH) {
      sendByte[9] = '1';
    } else {
      sendByte[9] = '0';
    }
    sendByte[10] = '$';
    sendByte[11] = '\n';
    outputSerial.write(sendByte, 11);
    /*
    Serial.print(sendByte);
    Serial.println("");
    */
  }
  prevB2 = b2;
  prevB3 = b3;
  prevB4 = b4;
  prevB5 = b5;
  prevB6 = b6;


  delay(100);
}
