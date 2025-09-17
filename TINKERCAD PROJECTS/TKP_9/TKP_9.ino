// Moves servo to mapped analog input if current and previous readings are stable (difference < 50).
#include <Servo.h>

Servo s;
int prev = -1;

void setup() {
    s.attach(9);
    pinMode(A0, INPUT);
    Serial.begin(9600);
}

void loop() {
    int potVal = analogRead(A0);
    int mappedVal = map(potVal, 0, 1023, 0, 180);

    if (prev != -1 && abs(mappedVal - prev) < 50) {
        Serial.print("STABLE VALUE: ");
        Serial.println(mappedVal);

        int cpos = s.read();
        int step = mappedVal > cpos ? 1 : -1;
        for (int i = cpos; i != mappedVal; i += step) {
            s.write(i);
            delay(15);
        }
    }

    prev = mappedVal;
    delay(250);
}
