
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char *ssid =	"Bhaskara";		// cannot be longer than 32 characters!
const char *pass =	"complicated#$*";		//


WiFiClient wclient;
PubSubClient client(wclient, "data1.neewee.io", 1992);

#define BUFFER_SIZE 100
char JSONmessageBuffer[600];
void setup() {
  // Setup console
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  call_json();
}

void loop() {


  if (!client.connected()) {
    if (client.connect("arduinoClient")) {
      client.set_callback(callback);
      //	client.publish("outTopic", "hello world qos=0");	// Simple publish with qos=0
      
      client.subscribe("inTopic");
    }
  }

  if (client.connected())
    client.publish("Test", JSONmessageBuffer);
  delay(2000);
  client.loop();

}









//  client.publish(MQTT::Publish("outTopic", "hello world qos=1")
//           .set_qos(1));
//
//  client.publish(MQTT::Publish("outTopic", "hello world qos=2")
//           .set_qos(2));
