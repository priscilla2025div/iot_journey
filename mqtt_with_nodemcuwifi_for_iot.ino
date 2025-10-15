//mqtt and nodemcu
#include<ESP8266WiFi.h>
#include<PubSubClient.h>

const char* ssid ="Pris";
const char* password ="priscilla123";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espclient;
PubSubClient client (espclient);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

WiFi.begin(ssid,password);
Serial.println("connecting to wifi");
if(WiFi.status()!=WL_CONNECTED){
  Serial.println(". ");
  delay(500);
}

client.setServer(mqtt_server,1883);
}

void loop() {
  // put your main code here, to run repeatedly:
if(!client.connected()){
  //not connected true
  client.connect("ESP8266Client");
}
client.publish("home/room/temperature","25.5");
delay(2000);
}
