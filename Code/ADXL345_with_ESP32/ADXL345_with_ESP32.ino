#include <Wire.h>
#include <Adafruit_Sensor.h> //Adafruit sensor library
#include <Adafruit_ADXL345_U.h> //ADXL345 library

//Create an ADXL345 Object
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

void setup() 
{
  //Initializes the serial communication 
  //to print data to the Serial Monitor.
  Serial.begin(9600);
}

void loop() 
{
 sensors_event_t event; //Variable to store the sensor event
 accel.getEvent(&event); //Get the sensor event

 //Print the data on the Serial Monitor
 Serial.print("X: ");
 Serial.print(event.acceleration.x); //x-axis measurement
 Serial.print("  ");
 Serial.print("Y: ");
 Serial.print(event.acceleration.y); //y-axis measurement
 Serial.print("  ");
 Serial.print("Z: ");
 Serial.print(event.acceleration.z); //z-axis measurement
 delay(500); //Update every 0.5 seconds
}