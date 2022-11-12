#include <Servo.h>
// Rotary Encoder Inputs
#define CLK 16
#define DT 5
Servo servo;
int counter = 0;
int angle = 0;
int currentStateCLK;
int lastStateCLK;
void setup() {
  // Set encoder pins as inputs
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  // Setup Serial Monitor
  Serial.begin(9600);
  // Attach servo on pin D4 to the servo object
  servo.attach(2);
  servo.write(counter);
  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);
}
void loop() {
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);
  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1) {
    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
      angle-=5;
    } else {
      // Encoder is rotating CW so increment
      counter ++;
      angle+=5;
    }
    // Move the servo
    servo.write(angle);
    Serial.print("Position: ");
    Serial.println(counter);
    Serial.print("Angle: ");
    Serial.println(angle);
  }
  // Remember last CLK state
  lastStateCLK = currentStateCLK;
}
