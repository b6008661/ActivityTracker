
#include <AcceleroMMA7361.h>
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>
#include <SoftwareSerial.h>
#include<Wire.h>
const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

#include <AcceleroMMA7361.h>
AcceleroMMA7361 accelero;
int x;
int y;

//int x,y;
int count = 0;
float calories;
float distance;


/* Bluetooth: HC-06 */
SoftwareSerial BTSerial(4, 3); //Connect HC-06 using the (TX, RX) pins

/*Pulse sensor */
int PulseSensorPin = 0;
int signal;
int threshold = 550;
PulseSensorPlayground pulseSensor;


void setup() {
  // put your setup code here, to run once:
  BTSerial.begin(9600);
  Wire.begin();
  Serial.begin(9600);
  
  //set up the acceleromter 
  accelero.begin(13, 12, 11, 10, A0, A4, A5);
  accelero.setARefVoltage(5); //sets the AREF voltage to 3.3V
  accelero.setSensitivity(LOW); //sets the sensitivity to +/-6G
  accelero.calibrate();
  
  //set up the pulse sensor 
  pulseSensor.analogInput(PulseSensorPin);
  pulseSensor.setThreshold(threshold);
  if(pulseSensor.begin()) {
     Serial.println("We created a pulseSensor object!");
  }
}

void loop() {
  //get the BPM using the pulse sensor 
  sensor();

//get the x and y values from the acceleromter
 x = accelero.getXAccel();
 y = accelero.getYAccel();

  //if a step has been taken, add it to the count 
  if ( x <= 450 && y >= 390) 
  {
    count++;
    delay(200);
  }
  if ( x >= 460 && y <= 370)
  {
    count++;
    delay(200);
  }

  //calculate the steps, calories and distance 
  calories = count * 0.035;
  distance = count * 0.0006;

  //send through BT
  Serial.print("Calories: ");
  Serial.print(calories);
  Serial.print("\n");
  Serial.print("Count: ");
  Serial.print(count);
  
  delay(200);
  //steps
  BTSerial.write(count);
  //calories
  BTSerial.write(calories);
  //distance
  BTSerial.write(distance);
  delay(500); //make it readable
}

void sensor(){
  int BPM = pulseSensor.getBeatsPerMinute();

  if(pulseSensor.sawStartOfBeat()) {
    Serial.println("BPM: ");
    Serial.println(BPM);
    //BTSerial.println("h");
    BTSerial.write(BPM);
    //BTSerial.write(BPM);
  }
  
}
