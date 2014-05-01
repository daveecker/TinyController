
#include <CapacitiveSensor.h>

int driveSwitch = 0; //send a low signal to open disk drive
int sendPin = 4; //theres a 1M resistor between send and receive
int receivePin = 2; //this goes to the drive cover
int error = 1; //error led for problems

CapacitiveSensor sensor = CapacitiveSensor(sendPin, receivePin);


void setup()
{
  pinMode(driveSwitch, OUTPUT);
  digitalWrite(driveSwitch, HIGH);
  pinMode(error, OUTPUT);
}


void loop() {
  
  //this is for the disk drive:
  long value = sensor.capacitiveSensor(10);
  
  while(value == -2)
  {
    digitalWrite(error, HIGH);
    delay(500);
  }
  
  if(value > 4000)
  {
    digitalWrite(driveSwitch, LOW);
  }
  else
  {
    digitalWrite(driveSwitch, HIGH);
  } 
  
  delay(10);
}
