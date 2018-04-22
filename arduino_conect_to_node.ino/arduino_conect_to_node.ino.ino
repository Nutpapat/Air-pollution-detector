
int mq7;
float mq135;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

#include <SoftwareSerial.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial NanoSerial(11, 10); // RX | TX

void setup()

{  
lcd.begin();
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
  
  lcd.setCursor(0, 0);  
  lcd.print("MQ-7   ");
  lcd.print((float)mq7);
  
  lcd.setCursor(0, 1);
  lcd.print("MQ-135 ");
  lcd.print(mq135);


  NanoSerial.print(mq7);NanoSerial.print(" ");
  NanoSerial.print(mq135);
  NanoSerial.print("\n");
  delay(1000);

}

 

 
