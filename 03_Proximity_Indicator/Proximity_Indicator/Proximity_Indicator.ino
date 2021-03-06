/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------
        I/O         ORIGINAL
        Expansion     PIN
        Shield      ESP8266
--------------------------------------------------------------------------*/
#define EXP_PIN_2     0
#define EXP_PIN_3     4  
#define EXP_PIN_4     5
#define EXP_PIN_5     12
#define EXP_PIN_6     13  
#define EXP_PIN_7     15	//LED MODULE
/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------*/

#define IR_SENSOR A0

int lowBrightness = 1023, highBrightness = 0;

void fadeLED(int times, int delayTime) {
  for (int i = 0; i < times; i++) {
    for (int j = 0; j < 255; j += 5) {
      analogWrite(EXP_PIN_7, j);
      delay(delayTime);
    }
    for (int j = 255; j >= 0; j -= 5) {
      analogWrite(EXP_PIN_7, j);
      delay(delayTime);
    }
  }
}

void calibrate(int times) {
  for (int i = 0; i < times; i++) {
    int brightness = analogRead(IR_SENSOR);
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
  pinMode(EXP_PIN_7, OUTPUT);
  //calibration will take about 300*10 ms once
  //once you turn on the Arduino 101, it will enter calibration mode for about 3 seconds
  //cover the IR Sensor with the desired object which will be tracked to determine the highest brightness, and uncover the IR Sensor to determine the lowest brightness
  calibrate(300);
}

void loop() {
  int distance;
  distance = map(analogRead(IR_SENSOR), lowBrightness, highBrightness, 30, 1);
  if (distance > 30) {
    distance = 30;
  }
  else if (distance < 1) {
    distance = 1;
  }
  fadeLED(1, distance);
}

