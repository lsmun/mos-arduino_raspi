// For W5100 based ethernet modules
#include <SPI.h>     
#include <Ethernet2.h>

// For ENC28J60 based ethernet modules
//#include <UIPEthernet.h>
//#include <UIPServer.h>
//#include <UIPClient.h>

#include <EasyWebServer.h> // Must be included AFTER the ethernet libraries. See comment in EasyWebServer.h.

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 1, 141);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

const int fanPin = 13;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) { ; } // wait for serial port to connect. Needed for native USB port only

  // Start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());

  // Set pin 2-8 as digital input pins.
  for (int digitalPin = 2; digitalPin < 8; digitalPin++)
    pinMode(digitalPin,INPUT);
  
  pinMode(fanPin,OUTPUT);
}

void loop() {
  // Listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("New client!");
    EasyWebServer w(client);                    // Read and parse the HTTP Request
    w.serveUrl("/",rootPage);                   // Root page/turn fans off
    w.serveUrl("/turnon",turnOn);               // Turn fans on
  }  
}

void rootPage(EasyWebServer &w){
  w.client.println(F("<!DOCTYPE HTML>"));
  w.client.println(F("<html><head><title>Fan Control: OFF</title></head><body>"));
  w.client.println(F("<p>Fans are currently off.</p>"));
  w.client.println(F("<p><a href='/turnon'>Click here to turn the fans on</a></p>"));
  w.client.println(F("</body></html>"));

  digitalWrite(fanPin, LOW);
}

void turnOn(EasyWebServer &w){
  w.client.println(F("<!DOCTYPE HTML>"));
  w.client.println(F("<html><head><title>Fan Control: ON</title></head><body>"));

  digitalWrite(fanPin, HIGH);

  w.client.print(F("Fans have been turned on."));
  w.client.println(F("<br />"));
  w.client.println(F("<p><a href='/'>Click here to turn the fans off.</a></body></html>"));
}
