/*MQ-135 Sensitive for benzene, alcohol, smoke
  MQ-7 Carbon Monoxide (CO) sensor  */
  
#define SensorValue_MQ7 A1
#define SensorValue_MQ135 A0
float mq7,mq135;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(900000);            // wait 15 minute for stable value
}

void loop() {
  // put your main code here, to run repeatedly:
  mq7 = 0;
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
    }
    else if(mq135<=20 || mq7<=20){
      Serial.println("Air quality is good");
      }
    else{
      Serial.println("Air quality is normal");
      }
  Serial.print("MQ-7 ");
  Serial.println(mq7);
  Serial.print("MQ-135 ");
  Serial.println(mq135);
  delay(10000);
   
}
