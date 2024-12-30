//Include required libraries
#include <esp_now.h>
#include <WiFi.h>

//These pins control the 2 motors on the right side of the car
int rightMotorPin1 = 16; //Control going forward
int rightMotorPin2=17; //Control going backward

//These pins control the 2 motors on the left side of the car
int leftMotorPin1 = 18; //Control going forward
int leftMotorPin2 = 19; //Control going backward

//Same struct as transmitter's struct
typedef struct struct_message 
{
  float x, y;
} struct_message;

//Create 'receivedData' to store data received from the other ESP32
struct_message receivedData;

//Callback function that will be executed whenever data is received by the ESP32
void OnDataReceived(const uint8_t * mac, const uint8_t *incomingData, int len) 
{
  //Copy the received data to 'receivedData' variable
  memcpy(&receivedData, incomingData, sizeof(receivedData));
}

void setup() 
{ 
  //Set these pins to output mode to control the motor driver
  pinMode(rightMotorPin1, OUTPUT); 
  pinMode(rightMotorPin2, OUTPUT); 
  pinMode(leftMotorPin1, OUTPUT); 
  pinMode(leftMotorPin2, OUTPUT); 
  
  //Initialize Wi-Fi in Station mode
  WiFi.mode(WIFI_STA);

  //Initialize ESP-NOW
  esp_now_init();
  
  //Register a callback function that will be executed 
  //whenever data is received by the ESP32
  esp_now_register_recv_cb(OnDataReceived);
}

//Right Motors
void rightMotorsForward()
{
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);
}
void rightMotorsBackward()
{
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);
}
void rightMotorsStop()
{
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);     
}

//Left Motors
void leftMotorsForward()
{
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);
}
void leftMotorsBackward()
{
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);
}
void leftMotorsStop()
{
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);     
}

void loop()
{
  if (receivedData.x > 4) //Move Foward
  {
    rightMotorsForward();
    leftMotorsForward();
  }
  else if (receivedData.x < -4) //Move Backward
  {
    rightMotorsBackward();
    leftMotorsBackward();
  }
  else if (receivedData.y > 4) //Turn Right
  {
    rightMotorsBackward();
    leftMotorsForward();
  }
  else if (receivedData.y < -4) //Turn Left
  {
    rightMotorsForward();
    leftMotorsBackward();
  }
  else //Rested hand position, the car stops
  {
    rightMotorsStop();
    leftMotorsStop();
  }
}