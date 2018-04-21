
int mq7;
float mq135;

#include <SoftwareSerial.h>

SoftwareSerial NanoSerial(11, 10); // RX | TX

void setup()

{  

  pinMode(11,INPUT);

  pinMode(10,OUTPUT);

  Serial.begin(9600);

  NanoSerial.begin(57600);           

}

void loop() {
  mq7 = analogRead(A1);
  mq135 = analogRead(A0);
  Serial.println(mq135);
  Serial.println(mq7);

  NanoSerial.print(mq7);NanoSerial.print(" ");
  NanoSerial.print(mq135);
  NanoSerial.print("\n");
  delay(1000);

}

 

 
