#include <TinyGPS++.h> // library for GPS module
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
TinyGPSPlus gps;  // The TinyGPS++ object
SoftwareSerial ss(4, 5); // The serial connection to the GPS devicepm
float latitude , longitude;
String lat_str , lng_str;
WiFiServer server(80);

void setup()
{
  Serial.begin(9600);
  ss.begin(9600);
}


void loop()
{

  while (ss.available() > 0) {
    if (gps.encode(ss.read())) {
      if (gps.location.isValid()) {//check whether gps location is valid


        latitude = gps.location.lat();
        lat_str = String(latitude , 6); // latitude location is stored in a string
        longitude = gps.location.lng();
        lng_str = String(longitude , 6); //longitude location is stored in a string
      }
      Serial.print("Latitude : ");
      Serial.println(lat_str);
      Serial.print("Longitude : ");
      Serial.println(lng_str);
    }
  }
}
