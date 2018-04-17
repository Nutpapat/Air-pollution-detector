#include <NewPing.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define WIFI_SSID "SSID ของ WIFI "
#define WIFI_PASSWORD "Password ของ WIFI "
#define FIREBASE_HOST "URL ของ Database"
#define FIREBASE_AUTH "Secret key ของ Database"
int i,j =0;
//buzzer
const int buzzer = 10;
// tempperature
int pintemp = 11;
//motor pin A
int wheel1PinA = 3;
int wheel2PinA = 2;
int speedPinA = 6;
//motor pin B
int wheel1PinB = 4;
int wheel2PinB = 7;
int speedPinB = 5;
int SPEED = 191;  // speed car
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
NewPing sonar_right(12, 13,100);
NewPing sonar_left(8,9,100);

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(500);}
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  pinMode(buzzer,OUTPUT); // pin buzzer
  pinMode(wheel1PinA,OUTPUT);
  pinMode(wheel2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(wheel1PinB,OUTPUT);
  pinMode(wheel2PinB,OUTPUT);
  pinMode(speedPinB,OUTPUT);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  int sensorMQ7 = analogRead(A0);
  Serial.println(sensorMQ7);
  int value = analogRead(pintemp);
  float tempC = value* 0.48828125;
  Serial.println(tempC);
  Serial.println(sonar_left.ping_cm());
  Serial.println(sonar_right.ping_cm());
  // left
  if((sonar_left.ping_cm()<15 && sonar_left.ping_cm()!=0)|| (sonar_right.ping_cm()<15 && sonar_right.ping_cm()!=0)){
      analogWrite(speedPinA, 0);
      digitalWrite(wheel1PinA, HIGH);
      digitalWrite(wheel2PinA, LOW);
      analogWrite(speedPinB, 0);
      digitalWrite(wheel1PinB, LOW);
      digitalWrite(wheel2PinB, HIGH);
      Serial.println("turn left");
      delay(550);
    }
    //ระดับแรกถ้าควันสูงกว่าปกตินิดนึง เสียงจะเป็นแบบ สูงขึ้นเรื่อยๆ2รอบ
    else if(sensorMQ7 == 1000){               //1000 คือ ค่าที่เรากำหนด
      analogWrite(speedPinA, 0);
      digitalWrite(wheel1PinA, LOW);
      digitalWrite(wheel2PinA, LOW);
      analogWrite(speedPinB, 0);
      digitalWrite(wheel1PinB, LOW);
      digitalWrite(wheel2PinB, LOW);
      delay(1000);
      //for(i;i<2;i++){
      //for(j;j<1000;j++){
        //tone(buzzer,j);
      //}
     //}
    }
    //ระดับที่มากเกินผิดปกติส่งเสียงดังยาวๆ
    else if(sensorMQ7 > 1000){ //1000 คือ ค่าที่เรากำหนด
         analogWrite(speedPinA, 0);
      digitalWrite(wheel1PinA, LOW);
      digitalWrite(wheel2PinA, LOW);
      analogWrite(speedPinB, 0);
      digitalWrite(wheel1PinB, LOW);
      digitalWrite(wheel2PinB, LOW);
      delay(1000);
       // tone(10,1000);
    }
    //ถ้าอยู่ในอุณหภูมิที่มากกว่า100องศา
      else if(tempC == 100){
       //เสียงเตือน แบบกระพริบ
       //for(i;i<3;i++){
        //tone(10,1000); 
        //delay(1000);
        //noTone(10);
        //delay(1000);
        // )
        //back
      analogWrite(speedPinA, 0);
      digitalWrite(wheel1PinA, LOW);
      digitalWrite(wheel2PinA, HIGH);
      analogWrite(speedPinB, 0);
      digitalWrite(wheel1PinB, LOW);
      digitalWrite(wheel2PinB, HIGH);
      delay(550);
        //left
      analogWrite(speedPinA, 0);
      digitalWrite(wheel1PinA, HIGH);
      digitalWrite(wheel2PinA, LOW);
      analogWrite(speedPinB, 0);
      digitalWrite(wheel1PinB, LOW);
      digitalWrite(wheel2PinB, HIGH);
      Serial.println("turn left");
      delay(550);
      }

    //forward
   else{
      analogWrite(speedPinA, SPEED);
      digitalWrite(wheel1PinA, HIGH);
      digitalWrite(wheel2PinA, LOW);
      analogWrite(speedPinB, SPEED);
      digitalWrite(wheel1PinB, HIGH);
      digitalWrite(wheel2PinB, LOW);
      Serial.println("forward");
    }
    Firebase.setInt("temperature", tempC);
    Firebase.setInt("CO", sensorMQ7);
}
