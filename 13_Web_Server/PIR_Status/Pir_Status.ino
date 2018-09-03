/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------
        I/O         ORIGINAL
        Expansion     PIN
        Shield      ESP8266
  --------------------------------------------------------------------------*/
#define EXP_PIN_2     0
#define EXP_PIN_3     4
#define EXP_PIN_4     5   //LED Built in ESP8266
#define EXP_PIN_5     12
#define EXP_PIN_6     13
#define EXP_PIN_7     15
#define EXP_PIN_ADC   A0
/*------------PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD------------*/


#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "user_interface.h"             // Needed for timer

// Define time function for periodic read in of digital input
os_timer_t myTimer;                     // Variable declaration for timer
#define TIMER_UPDATE 100

// Bolean variable for digital input reads
bool inp = 0;
String data;

// WiFi parameter
const char* ssid     = "Your SSID";
const char* password = "Your Password";

// Webserver parameter
ESP8266WebServer server(80);
String webpage_head, webpage_trail;

// Setup routine
void setup() {

  pinMode(EXP_PIN_3, INPUT); // Configure pin EXP_PIN_3 as input
  Serial.begin(9600);        // Configure serial port
  delay(10);
  connect_wifi();            // Connect to WiFi
  start_httpd();             // Start webserver

  // Configure timer
  os_timer_setfn(&myTimer, timerCallback, NULL);        // Define a function to be called when the timer setup
  os_timer_arm(&myTimer, TIMER_UPDATE, true);           // Arm : Fires when timer reach zero, 0 for execute once and 1 for Repeating execution
}

// the loop function runs over and over again forever
void loop() {
  server.handleClient();
}

// Timer-controlled read in of digital input
void timerCallback(void *pArg) {
  inp = digitalRead(EXP_PIN_3);
  if (inp == 1) {
    data = "Motion Detected";
    Serial.print("Read digital input: ");
    Serial.println(data);
  } else {
    data = "No Motion Detected";
    Serial.print("Read digital input: ");
    Serial.println(data);
  }

}

// Conecting to WiFi network
void connect_wifi() {
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.print(" ");

  WiFi.mode(WIFI_STA);          // Explicitly set the ESP8266 to be a WiFi-client
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());
  Serial.println();
}
// Setup the webserver
void start_httpd() {
  webpage_head += "<html><head>";
  webpage_head += "<title>ESP8266 Webserver </title>";
  webpage_head += "<meta http-equiv=\"refresh\" content=\"5\" >";       //Refresh Time for Web Server in 5 Second
  webpage_head += "</head><body>";
  webpage_head += "<h1>ESP8266 Webserver</h1>";
  webpage_head += "<p>Welcome to the website of ESP8266!</p>";
  webpage_head += "<p>PIR Sensor Status: ";

  webpage_trail += "</p>";
  webpage_trail += "</body></html>";

  server.on("/", []() {
    Serial.println("HTTP request");
    server.send(200, "text/html", webpage_head + data + webpage_trail);
  });
  server.begin();
  Serial.println("HTTP server started");
}
