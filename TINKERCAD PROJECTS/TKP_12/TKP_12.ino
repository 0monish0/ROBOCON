const int tPin = 8;
const int ePin = 7;
const int l1 = 2;
const int l2 = 3;
const int l3 = 4;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  
  pinMode(tPin, OUTPUT);
  pinMode(ePin, INPUT);
  
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
}

void loop() {
  digitalWrite(tPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(tPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin, LOW);
  
  duration = pulseIn(ePin, HIGH);
  distance = duration * 0.01715;
  
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("cm");
  
  if (distance > 250) {
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
  } else if (distance > 175 && distance <= 250) {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
  } else if (distance > 100 && distance <= 175) {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, LOW);
  } else {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, HIGH);
  }
  
  delay(200);
}
