/*MQ-135 Sensitive for benzene, alcohol, smoke
  MQ-7 Carbon Monoxide (CO) sensor  */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
  
#define SensorValue_MQ7 A1
#define SensorValue_MQ135 A0

float mq7,mq135;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  
  for(int i=15 ; i>0 ; i--){                            // wait 15 minute for stable value
    Serial.print("Please wait for ");
    Serial.print(i);
    Serial.println(" minute");

    lcd.setCursor(0, 0);
    lcd.print("Please wait for ");
    lcd.setCursor(0, 1);
    lcd.print(i);
    lcd.print(" minute");
    delay(60000);                                     // 1 m
  }


}

void loop() {
  mq7=0;
  mq135 = 0;
  for(int i=0;i<6;i++){                                    // wait 1m for average value
    mq7 += analogRead(SensorValue_MQ7);
    mq135 += analogRead(SensorValue_MQ135);
    delay(10000);                                          // 10 s
  }
    mq7 /= 6;
    mq135 /= 6;
    if(mq135>=42 || mq7>=131){
      Serial.println("Air quality is bad");
      
      lcd.setCursor(0, 0);
      lcd.print("Air quality");
      lcd.setCursor(0, 1);
      lcd.print("is bad    ");
    }
    else if(mq135<=20 && mq7<=60){
      Serial.println("Air quality is good");
      
      lcd.setCursor(0, 0);
      lcd.print("Air quality    ");
      lcd.setCursor(0, 1);
      lcd.print("is good   ");
    }
    else{
      Serial.println("Air quality is normal");
      
      lcd.setCursor(0, 0);
      lcd.print("Air quality");
      lcd.setCursor(0, 1);
      lcd.print("is normal   ");
   }
      Serial.print("MQ-7 ");
      Serial.println(mq7);
      Serial.print("MQ-135 ");
      Serial.println(mq135);
}
