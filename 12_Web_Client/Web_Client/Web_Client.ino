
#include <ESP8266WiFi.h>

// Change the SSID according to your network
char ssid[] = "Your SSID";
// Change the Password according to your network
char pass[] = "Your Password";

char server[] = "arduino.cc";
int status = WL_IDLE_STATUS;

WiFiClient client;

void pageRequest() {
  if (client.connect(server, 80)) {
    Serial.println("connected to server");
    client.println("GET /asciilogo.txt HTTP/1.1");
    client.println("Host: arduino.cc");
    client.println("Connection: close");
    client.println();
  }
  else {
    Serial.println("connection failed");
  }
}

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  delay(1000);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  pageRequest();
}

void loop() {

if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting from server.");
    client.stop();
    //while (true);
  }  
}
