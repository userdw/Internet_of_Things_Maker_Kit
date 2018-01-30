/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------
        I/O         ORIGINAL
        Expansion     PIN
        Shield      ESP8266
--------------------------------------------------------------------------*/
#define EXP_PIN_2     0
#define EXP_PIN_3     4  
#define EXP_PIN_4     5	 //LED MODULE
#define EXP_PIN_5     12
#define EXP_PIN_6     13 
#define EXP_PIN_7     15
/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------*/

#define LDR_SENSOR A0

int lowBrightness = 1023, highBrightness = 0;

void calibrate(int times) {
  for (int i = 0; i < times; i++) {
    int brightness = analogRead(LDR_SENSOR);
    if (brightness <= lowBrightness) {
      lowBrightness = brightness;
    }
    if (brightness >= highBrightness) {
      highBrightness = brightness;
    }
    delay(10);
  }
}


void setup() {
  //calibration will take about 300*10 ms once
  //once you turn on the Arduino 101, it will enter calibration mode for about 3 seconds
  //cover the LDR Sensor with your finger to determine the lowest brightness, and uncover the LDR Sensor to determine the highest brightness
  //be careful of shadows
  calibrate(300);
}

void loop() {
  int brightness;
  brightness = map(analogRead(LDR_SENSOR), lowBrightness, highBrightness, 0, 255);
  if (brightness < 0) {
    brightness = 0;
  }
  analogWrite(EXP_PIN_5, brightness);
}
