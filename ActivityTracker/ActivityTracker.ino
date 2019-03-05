#include <SoftwareSerial.h>
#include <Wire.h>
/*Bluetooth module*/
SoftwareSerial BT(3,2);

/*Accelerometer*/
#define MPU6050_I2C_ADDRESS 0x68

/*variables*/
#define SEND_TIME 1000
#define READ_TIME 50
unsigned long previousTime = 0;
unsigned lng currentTime = 0;

void setup() {
  Serial.begin(9600); //open the serial port
  Wire.begin();
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

/*Bluetooth connection */
void sendToApp() {
  
}

void retrieveFromApp() {
  
}
