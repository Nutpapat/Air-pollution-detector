#include <SoftwareSerial.h>
SoftwareSerial ArduinoSerial(0,1); // RX | TX

void setup()  {

  Serial.begin(9600);
  ArduinoSerial.begin(57600);
}

 

void loop() {
  while(ArduinoSerial.available() > 0){
    int mq7= ArduinoSerial.parseInt();
    float mq135 = ArduinoSerial.parseFloat(); 

    if(ArduinoSerial.read() == '\n'){
        Serial.println(mq7);
        Serial.println(mq135);  
    }
  }
  delay(1000);
}
