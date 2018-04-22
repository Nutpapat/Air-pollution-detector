#include <MQ135.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
#include <SoftwareSerial.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial NanoSerial(11, 10); // RX | TX
const int buzzer = 6;
float mq135;
void setup()
{  
  pinMode(buzzer, OUTPUT);
  lcd.begin();
  pinMode(11,INPUT);

  pinMode(10,OUTPUT);

  Serial.begin(9600);

  NanoSerial.begin(57600);           

}

void loop() {
  MQ135 gasSensor = MQ135(A0);
  mq135 = gasSensor.getPPM();
  Serial.println(mq135);

  if(mq135 > 40){
    tone(buzzer, 1000);
  }
  else{
    noTone(buzzer);
  }

  lcd.setCursor(0, 0);
  lcd.print("Air Quality ");
  lcd.setCursor(0, 1);
  lcd.print(mq135);
  lcd.print(" ppm");


  NanoSerial.print(mq135);
  NanoSerial.print("\n");
  delay(1000);

}

 

 
