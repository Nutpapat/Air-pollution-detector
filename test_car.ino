#include <NewPing.h>
#include <SoftwareSerial.h>
SoftwareSerial ArduinoSerial(0,1); // RX | TX

//motor pin A
int wheel1PinA = 3;
int wheel2PinA = 2;
int speedPinA = 6;
//motor pin B
int wheel1PinB = 4;
int wheel2PinB = 7;
int speedPinB = 5;
int SPEED = 100;  // speed car
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
NewPing sonar_right(12, 13,100);
NewPing sonar_left(8,9,100);

void setup() {
  Serial.begin(9600);
  ArduinoSerial.begin(57600);
  pinMode(wheel1PinA,OUTPUT);
  pinMode(wheel2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(wheel1PinB,OUTPUT);
  pinMode(wheel2PinB,OUTPUT);
  pinMode(speedPinB,OUTPUT);
}

void loop() {
  Serial.println(sonar_left.ping_cm());
  Serial.println(sonar_right.ping_cm());
  // left
    while(ArduinoSerial.available() > 0){
        float mq135 = ArduinoSerial.parseFloat(); 

        if(ArduinoSerial.read() == '\n'){
           Serial.println(mq135);
           if(mq135 > 10){
            analogWrite(speedPinA, 0);
            digitalWrite(wheel1PinA, LOW);
            digitalWrite(wheel2PinA, LOW);
            analogWrite(speedPinB, 0);
            digitalWrite(wheel1PinB, LOW);
            digitalWrite(wheel2PinB, LOW);
            delay(500);
    }
        }
  }
  if((sonar_left.ping_cm()<15 && sonar_left.ping_cm()!=0)|| (sonar_right.ping_cm()<15 && sonar_right.ping_cm()!=0)){
      analogWrite(speedPinA, SPEED);
      digitalWrite(wheel1PinA, HIGH);
      digitalWrite(wheel2PinA, LOW);
      analogWrite(speedPinB, SPEED);
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
}
