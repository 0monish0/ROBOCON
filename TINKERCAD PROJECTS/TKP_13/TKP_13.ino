#include <Servo.h>

Servo myServo;
int pot = A0;
int potvalue = 0;
int mapval = 0;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
  potvalue = analogRead(pot);
  mapval = map(potvalue, 0, 1023, 0, 180);
  myServo.write(mapval);
  
  Serial.print("potentiometer Value:");
  Serial.print(potvalue);
  Serial.print("\tmapped Angle:");
  Serial.println(mapval);
  
  delay(100);
}
