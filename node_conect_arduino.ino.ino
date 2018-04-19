#include <ESP8266WiFi.h>

#include <SoftwareSerial.h>
#include "FirebaseArduino.h"
#define WIFI_SSID "HUAWEI P8 lite"
#define WIFI_PASSWORD "0864057600"
#define FIREBASE_HOST "compro-e7881.firebaseio.com"
#define FIREBASE_AUTH "HzOjOuN2ExO7mXtbMlz6fPMBpfu0xBQrOnsA5kvD"
SoftwareSerial NodeSerial(D2,D3); // RX | TX

void setup() {

  pinMode(D2, INPUT); 

  pinMode(D3, OUTPUT); 

  Serial.begin(9600);

  NodeSerial.begin(57600);

  Serial.println();

  Serial.println();

  Serial.println("NodeMCU/ESP8266 Run");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(500);}
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt("MQ-135", 0);
  Firebase.setInt("MQ-7", 0);

 }

void loop() {

  while (NodeSerial.available() > 0) 

  {

    int mq7= NodeSerial.parseInt();
    float mq135 = NodeSerial.parseFloat(); 
   

    if (NodeSerial.read() == '\n') 

    {

          Serial.print("mq135 "); Serial.print(" : "); 
          Serial.println(mq135);
          //Firebase.pushFloat("MQ-135", mq135);

          Serial.print("mq7 "); Serial.print(" : "); 
          Serial.println(mq7);
          //Firebase.pushInt("MQ-7", mq7);
         
          StaticJsonBuffer<200> jsonBuffer;
          JsonObject& root = jsonBuffer.createObject();
          root["MQ-135"] = mq135;
          root["MQ-7"] = mq7;
          root["time"] = "1 minute";
          
          // append a new value to /logDHT
          String name = Firebase.push("logDHT", root);

    }

  }

  delay(1000);

} 
