float runtime;
float randomNumber;
float randomLED;
int i=0;
unsigned long scoreLedOn;
unsigned long scoreLedButton;
unsigned long scoreLedResult;
unsigned long scoreFinal;

int LedRed = 8;
int LedGreen = 9;
int buttonRed = 11;
int buttonGreen = 12;

bool stateRed;
bool stateGreen;
bool stateLedRed;
bool stateLedGreen;

bool gateBool;

unsigned long scoreTime() {
  return (millis());
}

void setup() {
  Serial.begin(9600);
pinMode (LedRed, OUTPUT);
pinMode (LedGreen, OUTPUT);
pinMode (buttonRed, INPUT_PULLUP);
pinMode (buttonGreen, INPUT_PULLUP);

randomSeed(analogRead(0));
}

void loop() {
 while(i<1){
  if (digitalRead(buttonRed) == LOW) {
    stateRed = 1;
    } else if (digitalRead(buttonRed) == HIGH) {
    stateRed = 0;  
    }

  if (digitalRead(buttonGreen) == LOW) {
    stateGreen = 1;
    } else if (digitalRead(buttonGreen) == HIGH) {
    stateGreen = 0;  
    }
    
  //stateRed == digitalRead(buttonRed);
  //stateGreen == digitalRead(buttonGreen);
  randomNumber = random(5);
  randomLED = random(400);
  float ledOn = stateLedRed+stateLedGreen;
if (ledOn < 1) {
  delay(randomNumber*1000);
  scoreLedOn = scoreTime();
  if (randomLED > 200) {
    stateLedRed=1;
    }
    else {
    stateLedGreen=1;
    } 
  }
  while (digitalRead(buttonRed) == LOW) {
    stateLedRed = 0;
 //Serial.println("WHILE BUTTON RED");  
    }

  if (digitalRead(buttonRed) == LOW && stateLedRed==1){
      scoreLedButton = scoreTime();
//Serial.println("IF BUTTON RED");
      /*
      gateBool=0;
      } else {scoreLedButton=scoreLedButton;
      */
      }

   while (digitalRead(buttonGreen) == LOW) {
    stateLedGreen = 0;
    //Serial.println("WHILE BUTTON GREEN");
    }

  if (digitalRead(buttonGreen) == LOW && stateLedGreen==1){
      scoreLedButton = scoreTime();
//Serial.println("IF BUTTON GREEN");
      /*
      gateBool=0;
      } else {scoreLedButton=scoreLedButton;
      */
      }

    /*
    if (stateLedGreen=1) {
    scoreLedButton = scoreTime();
    }
    */


scoreLedResult = scoreLedButton-scoreLedOn; 
Serial.print(scoreLedButton);
Serial.print(" ");
Serial.println(scoreLedOn);

/*
Serial.print(digitalRead(buttonGreen));
Serial.print(digitalRead(buttonRed));
Serial.print(stateLedGreen);
Serial.println(stateLedRed);
*/


//if ((digitalRead(buttonGreen) == LOW && stateLedGreen==1) || (digitalRead(buttonRed) == LOW && stateLedRed==1)) {
  scoreFinal=scoreLedResult;
Serial.println(scoreLedResult);
delay(2000);
   //}
   
  //Serial.println(digitalRead(buttonGreen));
  

/*
  if (gateBool=0) {
    Serial.println(scoreFinal);
    delay(10);
   gateBool=1;
    }
*/
    
  
  
 

digitalWrite(LedRed, stateLedRed);
digitalWrite(LedGreen, stateLedGreen);
}
i++;
}
