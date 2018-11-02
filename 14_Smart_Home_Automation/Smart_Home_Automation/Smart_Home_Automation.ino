#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266HTTPClient.h>
#include <Phant.h>
#include <SimpleTimer.h>
#include <DHT.h>

#define DHTTYPE DHT22
#define DHTPIN  4


DHT dht(DHTPIN, DHTTYPE);
float humidity, temp;  				      // Variable for saving valu from sensor
unsigned long previousMillis = 0;
const long interval = 15000;        // time interval for update value from sensor

// Blynk Authentication
char auth[] = "Your Authentication Token";
char ssid[] = "Your SSID";
char pass[] = "Your Password";


WidgetLED led1(V20);
SimpleTimer timer;

int val = 0;
void notifyUpTime() {

  boolean btnState = digitalRead(13);
  if (btnState != LOW) {
    Blynk.notify("The Door Is OPEN");
    led1.on();
  } else {
    led1.off();
  }
}
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);  // GPIO 5 used for output 1
  dht.begin();                    // GPIO 12 used for output 2
  pinMode(13, INPUT_PULLUP);      // GPIO 13 used for Magnetic Reed Switch
  pinMode(4, INPUT_PULLUP);       // GPIO 4 used for DHT22
  timer.setInterval(10L, notifyUpTime);
}

void gettemperature() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // Stored a last time value from the sensor reading
    previousMillis = currentMillis;

    // Read a humidity value is require time 250 milisecond
    // Read a temperature value require time 2 second 
    humidity = dht.readHumidity();         // read a humidity in percent (%)
    temp = dht.readTemperature(false);     // read a temperature in Celcius
    Blynk.virtualWrite(V0, temp);
    Blynk.virtualWrite(V1, humidity);

    // Check condition if the reading from sensor success or not
    if (isnan(humidity) || isnan(temp)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
  }
}

bool isFirstConnect = true;
BLYNK_CONNECTED() {
  if (isFirstConnect)
  {
    Blynk.syncAll();
    isFirstConnect = false;
  }
}

void loop()
{
  Blynk.run();
  timer.run();
  gettemperature();
}
