
/************PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD************/
        //Shield  ESP8266//
#define EXP_PIN_2     0
#define EXP_PIN_3     4
#define EXP_PIN_4     5
#define EXP_PIN_5     12
#define EXP_PIN_6     13
#define EXP_PIN_7     15
/************PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD************/

void toggleLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(EXP_PIN_3, !digitalRead(EXP_PIN_3));
    delay(250);
    digitalWrite(EXP_PIN_3, !digitalRead(EXP_PIN_3));
    delay(250);
  }
}

void fadeLED(int times) {
  for (int i = 0; i < times; i++) {
    for (int j = 0; j < 256; j++) {
      analogWrite(EXP_PIN_3, j);
      delay(1);
    }
    for (int j = 255; j >= 0; j--) {
      analogWrite(EXP_PIN_3, j);
      delay(1);
    }
  }
}

void setup() {
  pinMode(EXP_PIN_3, OUTPUT);
  digitalWrite(EXP_PIN_3, HIGH);
}

void loop() {
  toggleLED(4);
  delay(1000);
  fadeLED(4);
  delay(1000);
}
