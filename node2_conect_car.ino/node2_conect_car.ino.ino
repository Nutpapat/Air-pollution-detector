#include <ESP8266WiFi.h>

#include <SoftwareSerial.h>
#include "FirebaseArduino.h"
#define WIFI_SSID "HUAWEI P8 lite"
#define WIFI_PASSWORD "0864057600"
#define FIREBASE_HOST "compro-e7881.firebaseio.com"
#define FIREBASE_AUTH "HzOjOuN2ExO7mXtbMlz6fPMBpfu0xBQrOnsA5kvD"
SoftwareSerial NodeSerial(D2,D3); // RX | TX

void setup() {
  // put your setup code here, to run once:
  pinMode(D2, INPUT); 

  pinMode(D3, OUTPUT);
   
  Serial.begin(9600);

  NodeSerial.begin(57600); 


  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(500);}
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(Firebase.getInt("detect"));
  NodeSerial.print(Firebase.getFloat("detect"));
  NodeSerial.print('\n');
}
