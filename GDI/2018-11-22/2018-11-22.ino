/*
 * Gruppe 3
 * Richard Renziehausen 4514896
 * Zhida Chen 4515140
 * Benedikt Staudacher 4514770
 * Milad Aydin 4526000
 * Rabih Alwan 3156351
 */

#include <LiquidCrystal.h>
String Eingabe; //Strings für Eingabe und Ausgabe
String Ausgabe;
String Check;
bool Button0;   //Button bool-Variablen
bool Button1;
bool ButtonEnter;
bool prevButton0; //vorherige Button-states
bool prevButton1;
bool prevButtonEnter;
int Vorgabe1;     //temporäre Variable
int scoreIndex;   //Index für Score Array
unsigned long randNumber; //zufäll. Vorgabentyp
int score[10];            //Score Array
unsigned long Vorgabe() { //Vorgabewert berechnen
  random(1, 8);
}
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  pinMode(5, INPUT);    //Pin Modus Setup
  pinMode(6, INPUT);
  pinMode(13, INPUT);
  lcd.begin(16, 2);
  randomSeed(analogRead(0));  //Zufallsverbesserung
  lcd.setCursor(0, 0);
  scoreIndex = 0;
}

void loop() {
  Button0 = digitalRead(5); //Buttons als Bool Variablen
  Button1 = digitalRead(6);
  ButtonEnter = digitalRead(13);
  int scoreSum = score[0] + score[1] + score[2] + score[3] + score[4] + score[5] + score[6] + score[7] + score[8] + score[9] + score[10]; //mangels arraySum in Arduino

  if (Button0 != prevButton0) {
    if (Button0 == 0) {
      Eingabe += "0";     //Button Eingabe für 0
      delay(200);
    }
  }

  if (Button1 != prevButton1) {
    if (Button1 == 0) {
      Eingabe += "1";   //Button Eingabe für 1
      delay(200);
    }
  }
  lcd.setCursor(0, 0);
  if (ButtonEnter != prevButtonEnter) {
    if (ButtonEnter = 1) {
      if (scoreIndex < 11) {
        scoreIndex ++;    //Score Index pro Runde erhöhen
        if (Eingabe == Ausgabe) {
          lcd.clear();
          Check = String("Richtig");
          score[scoreIndex] ++;
        }
        else {
          lcd.clear();
          Check = String("Falsch");
        }
      }
      else {
        lcd.clear();    //Array Reset, Ergebnisse und neues Spiel
        lcd.print("Score :");
        lcd.print(scoreSum);
        scoreIndex = 0;
        score[0] = 0;
        score[1] = 0;
        score[2] = 0;
        score[3] = 0;
        score[4] = 0;
        score[5] = 0;
        score[6] = 0;
        score[7] = 0;
        score[8] = 0;
        score[9] = 0;
        score[10] = 0;
      }
      lcd.clear();
      lcd.print(Check);

      delay(1000);
      lcd.clear();
      Eingabe = String("");
    }
    else if (ButtonEnter == 0) {
      randNumber = random(1,4);   //Neuen Vorgabewert bestimmen
      Vorgabe1 = Vorgabe();
      if (randNumber == 1) {
        Ausgabe = String(Vorgabe1, HEX);
      }
      else if (randNumber == 2) {
        Ausgabe = String(Vorgabe1, OCT);
      }
      else if (randNumber == 3) {
        Ausgabe = String(Vorgabe1, DEC);
      }
    }
  }

  lcd.clear();
  String Print = Ausgabe;
  lcd.print(Print);
  lcd.setCursor(0, 1);
  lcd.print(Eingabe);

  prevButton0 = Button0;
  prevButton1 = Button1;
  prevButtonEnter = ButtonEnter;

}
