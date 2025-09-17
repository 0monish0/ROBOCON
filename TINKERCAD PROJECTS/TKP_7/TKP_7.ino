// Moves two servos from their current position to target angle with complementary motion.  
//Show pulse Width of 2 servos using oscilioscope in tinkercad
#include <Servo.h>

Servo s;
Servo s1;
int a = 0;

void setup() {
  s.attach(9);
  s1.attach(10);
  Serial.begin(9600);
  s.write(0);
  s1.write(180);
}

void loop() {
  if (Serial.available() > 0) {
    a = Serial.parseInt();
    
    int cpos = s.read();
    int st= a > cpos ? 1 : -1;
    for (int i = cpos; i != a; i += st) {
      s.write(i);
      s1.write(180 - i);
      delay(50);
    }
  }
}
