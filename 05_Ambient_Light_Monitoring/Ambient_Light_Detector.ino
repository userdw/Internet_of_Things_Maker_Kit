#define LED_MODULE 5
#define LDR_SENSOR A0

int lowBrightness = 500, highBrightness = 0;

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
  brightness = map(analogRead(LDR_SENSOR), lowBrightness, highBrightness, 0, 51);
  if (brightness < 0) {
    brightness = 0;
  }
  analogWrite(LED_MODULE, brightness);
}
