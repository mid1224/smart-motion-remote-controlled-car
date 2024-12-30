//Include required libraries
#include <esp_now.h>
#include <WiFi.h>

// Address of the ESP32 on the car that we got earlier
uint8_t receiverAddress[] = {0x14, 0x2b, 0x2f, 0xc6, 0x2b, 0x40};

//This holds information of the receiver
esp_now_peer_info_t receiverInfo;

//A string that will hold the message we want to send
char message[32];

void setup() 
{
  //Set WiFi mode to Station
  WiFi.mode(WIFI_STA);

  //Initialize ESP-NOW
  esp_now_init();

  //Copy the address we got earlier to the receiverInfo's address
  memcpy(receiverInfo.peer_addr, receiverAddress, 6);

  //Establish connection to the receiver
  esp_now_add_peer(&receiverInfo);
}

void loop() 
{
  //Set data to send
  strcpy(message, "Hello There!");

  //Send the data
  esp_now_send(receiverAddress, (uint8_t *) &message, sizeof(message));

  delay(1000); //Add a delay of 1 seconds to prevent overloading
}