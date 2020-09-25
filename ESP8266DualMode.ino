//WifiDualMode for ESP8266



#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <ESP8266WebServer.h>

const char* APssid = "";                  //Enter SoftAP SSID
const char* APpassword = "";              //Set SoftAP Passphrase
const char* ssid = "";                    //Set Home Wifi Network SSID
const char* password = "";     //Set Home Wifi Passphrase

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  
 // SoftAP WiFi ----------------------------------------------------------
  Serial.println();
  Serial.print("Configuring access point...");
  
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP(APssid, APpassword);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
   }
  
  Serial.println("");
  Serial.println("WiFi connected");
   
 // Start the server -------------------------------------------------------
  server.begin();
  Serial.println("Server Started");
   
 // Print the IP address ---------------------------------------------------
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
