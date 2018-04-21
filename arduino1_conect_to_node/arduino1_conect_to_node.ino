#include <SoftwareSerial.h>

SoftwareSerial chat(0, 1); // RX, TX


void setup()  {

  Serial.begin(9600);

  chat.begin(4800);

}

 

void loop() {

  Serial.println(chat.readString());

}
