//Include required libraries
#include <WiFi.h>
#include <esp_wifi.h>

void readMacAddress()
{
  //Create a variable to store the MAC address
  uint8_t baseMac[6];

  //Get the ESP32 MAC address and put it in the baseMac
  esp_err_t ret = esp_wifi_get_mac(WIFI_IF_STA, baseMac);

  //Formats and prints the MAC address in the 
  //standard colon-separated hexadecimal format
  Serial.printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                baseMac[0], baseMac[1], baseMac[2],
                baseMac[3], baseMac[4], baseMac[5]);
}

void setup() //Run once
{
  //Initializes the serial communication 
  //to print data to the Serial Monitor.
  Serial.begin(9600);

  //Set WiFi mode to station
  WiFi.mode(WIFI_STA);

  readMacAddress();
}

void loop ()
{

}