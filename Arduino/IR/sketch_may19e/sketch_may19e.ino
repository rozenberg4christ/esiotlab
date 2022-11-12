int Status = 12;  // Digital pin D6

int sensor = 13;  // Digital pin D7
void setup() {
Serial.begin(9600);   
  pinMode(sensor, INPUT);   // declare sensor as input
  pinMode(Status, OUTPUT);  // declare LED as output
}
void loop() {

  long state = digitalRead(sensor);
  Serial.print("State: ");
  Serial.println(state);
  if (state == HIGH) {
    digitalWrite (Status, HIGH);
    Serial.println("Motion detected!");
    delay(1000);
  }
  else {
    digitalWrite (Status, LOW);
    Serial.println("Motion absent!");
    delay(1000);
  }
}
