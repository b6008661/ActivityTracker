#include <SoftwareSerial.h>
SoftwareSerial BT(3,2);

void setup() {
  Serial.begin(9600); //open the serial port
  BT.begin(9600); // open the bluetooth serial port
}

void loop() {
  if(BT.available()){
    Serial.println(BT.readString()); // send from serial to bluetooth
  }
  if(Serial.available()){
    BT.println(Serial.readString()); // send from bluetooth to serial
  }
}
