#include <espNetworking.h>
#include "iostream"
#include <ESP8266WiFi.h>    
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

WiFiClient client;
HTTPClient http;

const char* specificserverName = "http://api.thingspeak.com/update";
String tempAndHumidityAPIKEY = "T4P6ZTXR1T428AW9";
String doorOpeningAPIKEY = "LX17821TIXSN93VR";
int UploadTempAndHumidityServer(float temp, float humidity){
  
  Serial.print("The measurements where: ");
  Serial.print(temp);
  Serial.print("  ");
  Serial.print(humidity);
  Serial.print("  ");
  Serial.print("Trying to write temperature and humidity to server\n");

  http.begin(client, specificserverName);
  String httpRequestData = "api_key=" + tempAndHumidityAPIKEY + "&field1=" + String(temp)+"&field2="+String(humidity);           
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);
      
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      // Free resources
      http.end();


return 1;
}

float getTempAndHumidity(int entries){

http.begin(client,  "http://api.thingspeak.com/channels/2087340/feeds.json?api_key=1Y3EW91KEJWE5GSG&results="+String(entries));
int httpResponseCode = http.GET();
String payload = "";
if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
    Serial.println("Payload is: ");
    Serial.println(payload);
}
else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
}
http.end();




return 0.0;
}
int doorIsOpenedNetworking(){
    http.begin(client, specificserverName);
  String httpRequestData = "api_key=" + doorOpeningAPIKEY + "&field1=" + String("Visit");           
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);
      
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      // Free resources
      http.end();


      return httpResponseCode;







}

