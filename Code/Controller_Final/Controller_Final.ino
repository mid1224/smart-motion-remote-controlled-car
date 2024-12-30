#include <esp_now.h> //Libraries needed to use ESP_NOW
#include <WiFi.h> //Libraries needed to use ESP_NOW
#include <Wire.h> //Allow to communicate with I2C devices
#include <Adafruit_Sensor.h> //Adafruit sensor library
#include <Adafruit_ADXL345_U.h> //ADXL345 library

//Address of the receiver
uint8_t receiverAddress[] = {0x14, 0x2b, 0x2f, 0xc6, 0x2b, 0x40};

// Create ADXL345 Object named 'adxl'
Adafruit_ADXL345_Unified adxl = Adafruit_ADXL345_Unified();

// Struct for type of data to send
typedef struct struct_message 
{
  float x, y; //We want to send the measurement of acceleration in X and Y axis
} struct_message;

//Create 'sendingData' to store the data we want to send
struct_message sendingData;

//Defining a variable 'receiverInfo' of type esp_now_peer_info_t
//It holds information of the peer device (receiver) that we are communicating with
esp_now_peer_info_t receiverInfo;

void setup() 
{
  //Initialize Wi-Fi in Station mode
  WiFi.mode(WIFI_STA);

  //Initializes communication with the ADXL345
  adxl.begin();

  //Initialize ESP-NOW
  esp_now_init();

  //Copy the Receiver ESP32 address to the receiverInfo's address
  memcpy(receiverInfo.peer_addr, receiverAddress, 6);

  //Establish connection with the receiver
  esp_now_add_peer(&receiverInfo);
}

void loop() 
{
  sensors_event_t event; //This will store our sensor data
  adxl.getEvent(&event); //Get data from ADXL345 then put it into 'event'

  //Prepare data to send (Assign data from the sensor to the sending message)
  sendingData.x = event.acceleration.x; //Measurement of x axis acceleration
  sendingData.y = event.acceleration.y; //Measurement of y axis acceleration

  //Send data using ESP-NOW
  esp_now_send(receiverAddress, (uint8_t *) &sendingData, sizeof(sendingData));

  delay(500); //Send data every 0.5s to avoid overloading
}