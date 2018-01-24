/************PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD************/
        //Shield  ESP8266//
#define EXP_PIN_2     0
#define EXP_PIN_3     4  //DIGITAL PUSH BUTTON
#define EXP_PIN_4     5
#define EXP_PIN_5     12
#define EXP_PIN_6     13  //LED MODULE
#define EXP_PIN_7     15
/************PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD************/

#define DEBOUNCE_DELAY 80
#define TOGGLE_EXECUTE_DELAY 1500

unsigned long lastDebounceTime = 0;
unsigned long lastBlinkExecuteDelay = 0;
byte blinkTimes = 0;

void toggleLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(EXP_PIN_6, !digitalRead(EXP_PIN_6));
    delay(250);
    digitalWrite(EXP_PIN_6, !digitalRead(EXP_PIN_6));
    delay(250);
  }
}

void setup() {
  pinMode(EXP_PIN_6, OUTPUT);
  pinMode(EXP_PIN_3, INPUT);
}

void loop() {
  if (digitalRead(EXP_PIN_3) == LOW) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    lastDebounceTime = millis();
    lastBlinkExecuteDelay = millis();
    blinkTimes++;
    if (blinkTimes > 5) {
      blinkTimes = 5;
    }
  }

  if ((millis() - lastBlinkExecuteDelay) > TOGGLE_EXECUTE_DELAY) {
    toggleLED(blinkTimes);
    blinkTimes = 0;
    lastBlinkExecuteDelay = millis();
  }
}
