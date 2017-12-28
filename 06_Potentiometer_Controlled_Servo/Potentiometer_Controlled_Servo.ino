#include <Servo.h>
#define SERVO 4
#define ROTATION_SENSOR A0

Servo sg90;

void setup() {
  sg90.attach(SERVO);
  Serial.begin(9600);
}

void loop() {
  int rotationData = analogRead(A0);
  rotationData = map(rotationData, 0, 1023, 0, 255);
  sg90.write(rotationData);
  Serial.println(A0);
  Serial.print(rotationData);
}
