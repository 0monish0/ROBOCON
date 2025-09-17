int pot = A0;
int lpin = 9;
int potval = 0;
int mapval = 0;

void setup() {
  Serial.begin(9600);
  pinMode(lpin, OUTPUT);
}

void loop() {
  potval = analogRead(pot);
  mapval = map(potval, 0, 1023, 0, 255);
  analogWrite(lpin, mapval);
  
  Serial.print("Potentiometer Value:");
  Serial.print(potval);
  Serial.print("\tPWM Output:");
  Serial.println(mapval);
  
  delay(100);
}
