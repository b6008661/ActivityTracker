# ActivityTracker
A device that tracks steps, calories and heart rate using an Arduino Uno, accelorometer, and pulse sensor. This data is sent through a bluetooth module, connected to the Arduino board, to an Android app. 

## Motivation
This project has been created as part of a final year software engineering module. 

## Build Status 

## Code Style 

## Screenshots 

## Technologies and Frameworks Used
- Arduino IDE
- Android Studio 
- MIT App Inventor 
- PulseSensor library 
- AcceleroMMA7361 library 

## Features
Displays:
*Heart rate
*Calories
*Steps taken
*Distance travelled

## Installation 
Ensure Arduino IDE is installed on your computer. 
Download the calories.ino file from this repositary. 
Download the MIT App Inventor app from the App Store or Google Play. 
Go to http://ai2.appinventor.mit.edu/?locale=en#5679425132298240 
In the menu go to connect then select AI Companion. 
Scan the QR Code in the MIT App Inventor app. 
The app should now appear on the your phone.

## How To Use
Once installed, upload the calories.ino file onto the Arduino Uno.
On the app, click the "Select device" button.
Choose the bluetooth module (eg HC-06).
The label below the button will show you if it has connected or not. 
Apply pressure to the pulse sensor to view your heart rate. 
Walk around holding the device to see the steps you take. 
View the estimated number of calories burned and the distance tou travel too. 
Be careful, watch out for hour heart rate to display in red. It should sit between 60 and 100 beats per minute!


## Credits

## License 
