// #include <SoftwareSerial.h>

// SoftwareSerial mySerial(9, 10);

void setup(){
  Serial.begin(9600);
  delay(10000);
  // if( Serial.available() ) 
  SendMessage();
}

void loop(){ }

void SendMessage(){
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  
  Serial.println("AT+CMGS=\"+916382807597\"\r"); // Replace x with mobile number
  delay(1000);
  
  Serial.println("Hi");// The SMS text you want to send
  delay(100);

  Serial.write(26);// ASCII code of CTRL+Z
  delay(1000);
}


void RecieveMessage(){
  Serial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
}
