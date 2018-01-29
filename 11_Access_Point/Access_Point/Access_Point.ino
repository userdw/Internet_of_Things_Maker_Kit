#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "My ESP-8266 IoT ";

ESP8266WebServer server(80);

void webPage() {
  server.send(200,"text/html","<h1>You are connected</h1><p>Hello from ESP8266</p>");
}

void setup() {
  delay(1000);
  Serial.begin(9600);
  Serial.println();
  Serial.println("Configuring access point...");
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", webPage);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

