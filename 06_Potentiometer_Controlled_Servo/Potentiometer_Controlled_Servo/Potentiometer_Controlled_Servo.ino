/************PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD************/
        //Shield  ESP8266//
#define EXP_PIN_2     0
#define EXP_PIN_3     4  
#define EXP_PIN_4     5
#define EXP_PIN_5     12
#define EXP_PIN_6     13  
#define EXP_PIN_7     15 //SERVO
/************PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD************/

#include <Servo.h>
#define ROTATION_SENSOR A0

Servo sg90;

void setup() {
  sg90.attach(EXP_PIN_7);
}

void loop() {
  int rotationData = analogRead(A0);
  rotationData = map(rotationData, 0, 1023, 0, 180);
  sg90.write(rotationData);
}
