float runtime;
float randomNumber;
float randomLED;
float scoreLedOn;
float scoreLedButton;
float scoreLedResult;

int LedRed = 8;
int LedGreen = 9;
int buttonRed = 11;
int buttonGreen = 12;

bool stateRed;
bool stateGreen;
bool stateLedRed;
bool stateLedGreen;

int scoreTime() {
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
  stateRed = digitalRead(buttonRed);
  stateGreen = digitalRead(buttonGreen);
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

    scoreLedButton = scoreTime();
    }

   while (digitalRead(buttonGreen) == LOW) {
    stateLedGreen = 0;

    scoreLedButton = scoreTime();
    }
  
digitalWrite(LedRed, stateLedRed);
digitalWrite(LedGreen, stateLedGreen);
}
