#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Servo.h>

//Required time (in milliseconds) for the servo to reach the position.
#define DELAY_TIME 15 

//Creates servo object to control a servo.
Servo sg90;
//Defines here the variable that will hold the data coming from the Bluetooth.
String data;
//RX, TX
SoftwareSerial BTserial(2, 3);

void setup()
{
  //Starts software serial at 9600 Baudrate.
  BTserial.begin(9600);
  //Attaches the servo on pin 9 to the servo object.
  sg90.attach(9);
}

void loop()
{
  //Resets the value in it every time loop starts.
  data = "";
  
  while(BTserial.available()>0)
  {
    data +=BTserial.readString();

    //Tells servo to go to position in variable 'data'.
    sg90.write(data.toInt());
    delay(DELAY_TIME);
  }
}