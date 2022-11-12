#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

TinyGPSPlus gps;
SoftwareSerial SerialGPS(4, 5);


float Latitude , Longitude;
int year , month , date, hour , minute , second;
String DateString , TimeString , LatitudeString , LongitudeString;


void setup() {
  Serial.begin(9600);
  SerialGPS.begin(9600);
  Serial.println();
}


void loop() {



  Latitude = gps.location.lat();
  LatitudeString = String(Latitude , 6);
  Longitude = gps.location.lng();
  LongitudeString = String(Longitude , 6);


  if (gps.date.isValid()) {

    DateString = ""; date = gps.date.day(); month = gps.date.month(); year = gps.date.year();

    if (date < 10) DateString = '0'; DateString += String(date); DateString += " / ";
    if (month < 10) DateString += '0'; DateString += String(month); DateString += " / ";
    if (year < 10) DateString += '0';
    DateString += String(year);
  }

  if (gps.time.isValid()) {

    TimeString = "";
    hour = gps.time.hour() + 5; //adjust UTC
    minute = gps.time.minute();
    second = gps.time.second();

    if (hour < 10) TimeString = '0'; TimeString += String(hour); TimeString += " : ";
    if (minute < 10) TimeString += '0'; TimeString += String(minute); TimeString += " : ";
    if (second < 10) TimeString += '0'; TimeString += String(second);
  }




  Serial.print( "Latitude : " ); Serial.print( LatitudeString ) ; Serial.print( " Longitude : " ) ; Serial.println( LongitudeString );
  Serial.print( "Date and time : " ); Serial.print( DateString ) ; Serial.print( " " ) ; Serial.print( TimeString );


  delay(10000);

}
