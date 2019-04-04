char Incoming_value = 0;   
#include <SoftwareSerial.h>


/* Bluetooth */
SoftwareSerial BTSerial(2, 3); //Connect HC-06 using the (TX, RX) pins

void setup() 
{
  BTSerial.begin(9600);

}
void loop()
{
  BTSerial.print("hello");
  delay(500);                           
 
} 
