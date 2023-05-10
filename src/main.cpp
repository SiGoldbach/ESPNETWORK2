//This file is made with this link: https://randomnerdtutorials.com/esp8266-nodemcu-http-post-ifttt-thingspeak-arduino/
//This is how it must be since i either copy the most of it or sit and write the same code since there really is only 
//is one easy way to solve this problem. 

//#include <espUpload.h>
#include <ESP8266WiFi.h>    
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h> 
#include <espNetworking.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
using namespace std;
   // Include the Wi-Fi library
//Standard code to connect to wifi. 
const char* ssid     = "HUAWEI P30";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "8879abcd";     // The password of the Wi-Fi network
const char* serverName = "http://api.thingspeak.com/update";
String apiKey = "T4P6ZTXR1T428AW9";
char buffer[100];
int bufferSize=100;
const int analogInPin =A0;
int sensorValue = 0;
String command="";


void setup() {
  for(int i=0;i<100;i++){
    buffer[i]='0';
  }
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  Serial.println('\n');
  while (!Serial) {
 // wait for serial port to connect. Needed for native USB port only
}
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print('.');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}
void loop() { // run over and over
if (Serial.available()) {
command=Serial.readString();

Serial.println(command);
Serial.println("I read a String");
if(command.charAt(0)=='D'){
  doorIsOpenedNetworking();
}
else{
  //Here i am making a function to find the two integers in the read input if there are less than two nothing will hapen 
  //The two first integers will be used. 
  //Using help from this article 
  //https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
int nums[2];
for (int i = 0; i < 2; i++)
{
  nums[i]=-7000;
  /* code */
}

if(command.charAt(0)=='T'){
int numscounter=0;
string temp="";
for (char i = 0; i < command.length(); i++)
{
  if((command.charAt(i)>='0' and command.charAt(i)<='9') or command.charAt(i)=='.'){
  temp+=command.charAt(i);
  }else{
    if(temp.length()!=0){
    nums[numscounter]=stof(temp);
    numscounter++;
    temp="";

    } 
  }
  

  /* code */
}
int realMeasurement=1;
for (int i = 0; i < 2; i++)
{
  if(nums[i]==-7000){
    realMeasurement=0;

  }
  
  /* code */
}
if (realMeasurement){
  Serial.print("Uploading measurement \n");
  UploadTempAndHumidityServer(nums[0],nums[1]);
}
else{
  Serial.print("Failed converting the numbers. \n");
}
}



}
}
}