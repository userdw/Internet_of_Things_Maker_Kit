#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/************PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD************/
        //Shield  ESP8266//
#define EXP_PIN_2     0
#define EXP_PIN_3     4  //Digital Push Button
#define EXP_PIN_4     5
#define EXP_PIN_5     12
#define EXP_PIN_6     13 
#define EXP_PIN_7     15
#define EXP_PIN_ADC   A0
/************PIN DECLARATION FOR ESP8266 I/O EXPANSION SHIELD************/

ESP8266WebServer server(80);

char ssid[] = "Your SSID";
char pass[] = "Your Password";
String webPage = "";

void setup(void) {
  webPage += "<h1>ESP8266 Web Server</h1><p>Switch 1 <a href=\"switch1ON\"><button>ON</button></a>&nbsp;<a href=\"switch1OFF\"><button>OFF</button></a></p>";

  pinMode(EXP_PIN_3, OUTPUT);
  digitalWrite(EXP_PIN_3, LOW);
  delay(1000);

  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", [](){
    server.send(200, "text/html", webPage);
  });
  server.on("/switch1ON", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(EXP_PIN_3, HIGH);
    delay(1000);
  });
  server.on("/switch1OFF", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(EXP_PIN_3, LOW);
    delay(1000);
  });
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
}

