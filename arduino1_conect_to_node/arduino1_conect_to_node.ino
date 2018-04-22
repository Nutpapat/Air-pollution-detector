#include <SoftwareSerial.h>
SoftwareSerial ArduinoSerial(0,1); // RX | TX

void setup()  {

  Serial.begin(9600);
  ArduinoSerial.begin(57600);
}

 

void loop() {
  while(ArduinoSerial.available() > 0){
    float mq135 = ArduinoSerial.parseFloat(); 

    if(ArduinoSerial.read() == '\n'){
        Serial.println(mq135);  
    }
  }
  delay(1000);
}
