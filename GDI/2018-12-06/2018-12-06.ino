/*
 * Gruppe 3
 * Richard Renziehausen 4514896
 * Zhida Chen 4515140
 * Benedikt Staudacher 4514770
 * Milad Aydin 4526000
 * Nicola Stache 4509823
 * 
 * Wir haben uns aus gegen Unterstriche entschieden, da diese ein zählen der Buchstaben nicht ermöglichen würden.
 * Als erhöhter Schwierigkeitsgrad wird auch auf Groß- und Kleinschreibung geachtet, insbesondere da das Wörterbuch vorgegeben ist.
 */

 //Wörterbuch aus Vorgabedatei

const int dict_size_column = 23; // Maximale Anzahl an Wörtern
const int max_word_size    = 30; // Maximale Anzahl an Buchstaben pro Wort

char dict[dict_size_column][max_word_size] = {
  "Bremen",
  "Blumen",
  "Garten",
  "Socken",
  "Regenjacke",
  "Automobil",
  "Kaufmannsladen",
  "Universalindikatorpapier",
  "Immatrikulationsbescheinigung",
  "Hausboot",
  "Zweitor",
  "Maschenstromanalyse",
  "Quarkstube",
  "Viertel",
  "Weser",
  "Bananenbrot",
  "Blumenkohl",
  "Bauschaum",
  "Pendel",
  "Oszilloskop",
  "Widerstand",
  "Hausbesetzer",
  "Baumhaus"
};

//int test = random(0, dict_size_column + 1);

int randNumber() {    //Zufallszahl zur Wortauswahl
  return random(0, dict_size_column);
}

/*
  char selected(){
  int index = randNumber();
  return dict[index];
  }
*/

struct derBauer {     //Struct um die Variablen zu speichern, einfach weil's schöner ist
  int index;
  char wordOut[30];
  int wordLength;
  char input;
  bool correct;
  int health;
  int correctCharIndex;
  char line[30];
} bauer;

void debugDrawRandom() {        //DEBUGANZEIGE FÜR ZUFALLSZAHL
  Serial.println(randNumber());
}
void debugDrawWord() {          //WICHTIG, WORTWAHL, NICHT MEHR ANGEZEIGT
  bauer.index = randNumber();
  char empty = "";
  bauer.wordLength = 0;
  for (int i = 0; i < (max_word_size); i++) {
    bauer.wordOut[i] = dict[bauer.index][i];
    if (bauer.wordOut[i] != NULL) {     //ZÄHLUNG FÜR BUCHSTABEN
      bauer.wordLength ++;
    }
  }

  //Serial.println(bauer.wordOut);      //Debuganzeigen für Wort und Wortlänge
  //Serial.println(bauer.wordLength);
  for (int i = 0; i < bauer.wordLength; i++) {
    bauer.line[i] = '.';          //Punkte sind besser geeignet als Unterstriche
  }
  Serial.print(bauer.line);
  Serial.println("");
}

void getInput() {
  char in = NULL;       //leerung des chars
  if (Serial.available() > 0) {     //Nur bei input über Serial abarbeiten
    in = Serial.read();
    if ((in >= 'A' && in <= 'Z') || (in >= 'a' && in <= 'z')) {
      for (int i; i < bauer.wordLength; i++) {      //wort durchprüfen ob richtiger buchstabe

        if (bauer.wordOut[i] == in) {         //bestimmung ob richtig geraten (funktionierte nicht immer, daher unten erneut)
          bauer.correct = 1;
          bauer.correctCharIndex = i;
        } else {
          bauer.correct = 0;
          //bauer.health --;
        }
      }
      int dau = 0;
      for (int i; i < bauer.wordLength; i++) {      //bestimmung ob richtig geraten
        if (bauer.wordOut[i] == in) {
          bauer.line[i] = bauer.wordOut[i];
          dau=0;
          bauer.correct = 1;
        } else {
          dau=1;
          //bauer.line[i] = bauer.line[i];
        }
      }

        bauer.health -= 1-bauer.correct;      //leben abziehen
        dau=0;

      delay(500);

      if (in != NULL) {       //Print von werten
        //Serial.println("");
        Serial.print("EINGABE: ");
        Serial.println(in);
        //Serial.println("");
        //Serial.println(bauer.correct);
        if (bauer.correct){
          Serial.println("RICHTIG GERATEN");
        } else {
          Serial.println("FALSCH GERATEN");
        }
        Serial.println(bauer.line);
        Serial.print("LEBEN: ");
        Serial.println(bauer.health);
      }
    }
  }
  bauer.correct = 0;      //reset von variable
}

void setup() {
  bauer.health = 10;    //health zurücksetzen
  randomSeed(analogRead(0));    //besserer zufall
  Serial.begin(9600);
}

void loop() {
  debugDrawWord();    //Funktion zur Wortwahl
  int angela = 0;     //Int um gewinn zu bestimmen
  while (bauer.health != 0) {
    getInput();     //funktion für inputverarbeitung
    delay(100);     //kleines delay
    for (int i=0; i < bauer.wordLength; i++) {    //bestimmung ob gewonnen wurde, prüfung jedes zeichens
      if ((bauer.line[i] == bauer.wordOut[i]) && i==0) {
        angela ++;
      } else {
        //angela --;
      }
      if ((bauer.line[i] == bauer.wordOut[i]) && i>0) {
        angela ++;
      } else {
        angela --;
      }
    }
    if (angela > bauer.wordLength-1) {    //gewinntext
      Serial.println("JA SAPPERLOT, WIE HABEN SIE DENN DAFÜR GEMOGELT?! SIE HABEN GEWONNEN!");
      while(1){}
      }
  }
  while (bauer.health == 0) {     //verliertext
    Serial.println("JA MEI, WO KAM DAS DENN HER? SIE HABEN VERLOREN!");
    Serial.println("DAS RICHTIGE WORT WAR: ");      //Lösung anzeigen
    Serial.print(bauer.wordOut);
    while(1){}            //Spielende erzwingen
  }
}
