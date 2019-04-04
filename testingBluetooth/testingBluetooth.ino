#include <math.h>
#include <Wire.h>
#include <SoftwareSerial.h>
/*Pulse sensor */
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

/* Bluetooth: HC-06 */
SoftwareSerial BTSerial(4, 3); //Connect HC-06 using the (TX, RX) pins

/*Pulse sensor */
int PulseSensorPin = 0;
int signal;
int threshold = 550;
PulseSensorPlayground pulseSensor;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Wire.begin();
  BTSerial.begin(9600);  // set the data rate for the BT port
    /*Configure pulse sensor*/
  pulseSensor.analogInput(PulseSensorPin);
  pulseSensor.setThreshold(threshold);
  if(pulseSensor.begin()) {
    Serial.println("We created a pulseSensor object!");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
   int BPM = pulseSensor.getBeatsPerMinute();

  if(pulseSensor.sawStartOfBeat()) {
    Serial.println("BPM: ");
    Serial.println(BPM);
    //BTSerial.println("h");
    BTSerial.write(BPM);
    //BTSerial.write(BPM);
  }

}
