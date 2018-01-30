/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------
        I/O         ORIGINAL
        Expansion     PIN
        Shield      ESP8266
--------------------------------------------------------------------------*/
#define EXP_PIN_2     0
#define EXP_PIN_3     4		//LED MODULE
#define EXP_PIN_4     5
#define EXP_PIN_5     12	//PIR SENSOR
#define EXP_PIN_6     13  
#define EXP_PIN_7     15
/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------*/

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
  pinMode(EXP_PIN_5, INPUT);
}

void loop() {
  while (digitalRead(EXP_PIN_5)) {
    fadeLED(1);
  }
}

