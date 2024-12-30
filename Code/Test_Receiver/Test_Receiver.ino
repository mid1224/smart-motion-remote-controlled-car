//Include required libraries
#include <esp_now.h>
#include <WiFi.h>

//Must be the same data type as in the receiver
char message[32];

void OnDataReceived(const uint8_t * mac, const uint8_t *incomingData, int len) 
{
  //Copy the received data
  memcpy(&message, incomingData, sizeof(message));
}

void setup() 
{
  //Initializes the serial communication 
  //at a baud rate of 9600 to print data to the Serial Monitor.
  Serial.begin(9600);

  //Set WiFi mode to Station
  WiFi.mode(WIFI_STA);

  //Initialize ESP-NOW
  esp_now_init();

  //Register a callback function that will be executed 
  //whenever data is received by the ESP32
  esp_now_register_recv_cb(OnDataReceived);
}

void loop()
{
  Serial.println(message); //Print the received message
  delay(500); //Every 0.5s
}