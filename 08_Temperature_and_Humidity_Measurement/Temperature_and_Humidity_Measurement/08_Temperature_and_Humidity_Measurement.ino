#include <DHT.h>
/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------
        I/O         ORIGINAL
        Expansion     PIN
        Shield      ESP8266
--------------------------------------------------------------------------*/
#define EXP_PIN_2     0
#define EXP_PIN_3     4  
#define EXP_PIN_4     5
#define EXP_PIN_5     12  //TEMP & RH SENSOR 
#define EXP_PIN_6     13
#define EXP_PIN_7     15  
/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------*/

#define DHTTYPE DHT22   // DHT22  (AM2302)
DHT dht(EXP_PIN_5, DHTTYPE);
float h, t;             // Variable for Humidity and Temperature

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%");
  Serial.print(" ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("°C");
  delay(1000);
}
