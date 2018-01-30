/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------
        I/O         ORIGINAL
        Expansion     PIN
        Shield      ESP8266
--------------------------------------------------------------------------*/
#define EXP_PIN_2     0
#define EXP_PIN_3     4  //SOIL POWER PIN
#define EXP_PIN_4     5
#define EXP_PIN_5     12
#define EXP_PIN_6     13  
#define EXP_PIN_7     15
#define EXP_PIN_ADC   A0
/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------*/

int val = 0;                    //value for storing moisture value

void setup()
{
  Serial.begin(9600);           // open serial over USB
  pinMode(EXP_PIN_3, OUTPUT);   //Set EXP_PIN_3 as an OUTPUT
  digitalWrite(EXP_PIN_3, LOW); //Set to LOW so no power is flowing through the sensor
}

void loop()
{
  Serial.print("Soil Moisture = ");
  //get soil moisture value 
  Serial.println(readSoil());
  //take a reading every second
  delay(1000);            
}

int readSoil()
{

  digitalWrite(EXP_PIN_3, HIGH);    //turn Power "On"
  delay(10);                        //wait 10 milliseconds
  val = analogRead(EXP_PIN_ADC );   //Read the SIG value form sensor
  digitalWrite(EXP_PIN_3, LOW);     //turn Power "Off"
  return val;                       //send current moisture value
}
