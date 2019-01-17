/*
   Gruppe 2
   Richard Renziehausen 4514896
   Zhida Chen 4515140
   Benedikt Staudacher 4514770
   Milad Aydin 4526000
   Nicola Stache 4509823

   Wir haben alle Floatvariablen durch Integers ersetzt, da dies Speicher spart. Somit konnten wir die Messwertanzahl verdoppeln ohne mehr Speicher zu verbrauchen.
*/
#include <dht.h>
const int DHT11_PIN = 7;
const int data_capacity = 20;
dht DHT;

const int LDR_PIN = A2;
int bbbb;

const int BUTTON_PIN = 8;

struct data_s {
  int humidity;
  int temp;
  int brightness;
};

//kommen nur ganze Zahlen raus deswegen int anstatt float
int value2lux(int value) {
  if (value > 400) {
    return 0.0;
  } else if (value > 350) {
    return (int)map(value, 350, 400, 40, 0);
  } else if (value > 340) {
    return (int)map(value, 340, 350, 60, 40);
  } else if (value > 220) {
    return (int)map(value, 220, 340, 115, 60);
  } else if (value > 120) {
    return (int)map(value, 120, 220, 260, 115);
  } else if (value > 60) {
    return (int)map(value, 60, 120, 530, 260);
  } else if (value > 40) {
    return (int)map(value, 40, 60, 1000, 530);
  } else {
    return 1000;
  }
}

/* Einlesen der Daten zu einem bestimmten Zeitpunkt.
    Beachten Sie "Call-By-Reference" für die Sruktur.
*/
void readSensorData(struct data_s* data) {
  // Das Auslesen von Temperature oder Liftfeuchtigkeit benötigt etwa
  // 250 Millisekunden! Die ausgelesenen Werte können bis zu 2
  // Sekunden alt sein (es ist ein sehr langsamer Sensor).
  int chk = DHT.read11(DHT11_PIN);
  if (DHTLIB_OK == chk) {
    data->temp = DHT.temperature;  // in Grad Celsius
    data->humidity = DHT.humidity; // in % relative Luftfeuchtigkeit.
  } else {
    data->temp = 0;
    data->humidity = 0;
  };
  data->brightness = value2lux(analogRead(LDR_PIN)); // in Lux
}

/* Wir haben in maximal Platz für 120 Byte. In unserem Fall für 10
   Datensätze. Diese werden in data_memory gespeichert.
*/
struct data_s data_memory[data_capacity];

/* Damit wir nicht so lange warten müssen, lesen wir hier
   die Daten im Abstand von einer Sekunde ein und nicht
   im Abstand von einer Minute.
*/
const int reading_interval = 1000; // in ms, eine konstante, wozu unsigned long
unsigned long nextreadingtime = 0;

int lastButtonState;

/* Ausgabe eines(!) Datensatzes.
*/

void print_all_data_of_index(int index) {
  Serial.print("Temperatur = ");
  Serial.println(data_memory[index].temp);
  Serial.print("Feuchtigkeit = ");
  Serial.println(data_memory[index].humidity);
  Serial.print("Helligkeit = ");
  Serial.println(data_memory[index].brightness);
}

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  nextreadingtime = millis();
  lastButtonState = digitalRead(BUTTON_PIN);
  bbbb = 1;
}


int data_num = 0;
bool maxLimit = false;

void loop()
{
  int buttonState = digitalRead(BUTTON_PIN);
  // Falls der Button losgelassen wird, wird alles ausgegeben und der Speicher geleert
  if (buttonState != lastButtonState && buttonState == HIGH) {
    Serial.println("====================");
    Serial.println("=    Alle Daten    =");
    Serial.println("====================");
    if (maxLimit) {                           //sobald insgesamt mehr als 20 Werte gemessen wurden werden immer die letzten 20 ausgegeben
      for (int i = 0; i < data_capacity; i++) {
        Serial.println("--------------------");
        Serial.print(  "-    Eintrag ");
        Serial.print(i);
        Serial.print(" - ");
        Serial.print(bbbb);       //Anzeigen wie oft überschrieben wurde
        Serial.println(" -");
        Serial.println("--------------------");
        print_all_data_of_index(i);
      }
    } else {
      for (int i = 0; i < data_num; i++) {
        Serial.println("--------------------");
        Serial.print(  "-    Eintrag ");
        Serial.print(i);
        Serial.println("     -");
        Serial.println("--------------------");
        print_all_data_of_index(i);
      }
    }
    data_num = 0; // löschen
    maxLimit = false;  //Reset
    bbbb = 1; //Reset
  }
  // Falls die Zeit abgelaufen ist, wird ein neuer Datensatz eingelesen.
  if (millis() >= nextreadingtime) {
    nextreadingtime += reading_interval;
    // Nur einlesen, wenn wir noch Speicher frei haben
    if (data_num < data_capacity) {
      readSensorData(&data_memory[data_num]);
      data_num++;
    } else {
      data_num = 0;   //reset sobald maximale speichermenge überschritten
      maxLimit = true;
      bbbb += 1; //Zählung der Durchläufe
    }
  }
  lastButtonState = buttonState;
  delay(10);
}
