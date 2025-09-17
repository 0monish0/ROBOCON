// C++ code
//To print the Distance in cm Through HC-SR04 ultrasonic sensor
void setup()
{
  pinMode(7,OUTPUT);
  pinMode(6,INPUT);
  Serial.begin(9600);
  
}

void loop()
{	
  digitalWrite(7,LOW);
  digitalWrite(7,HIGH);
  delayMicroseconds(10);
  digitalWrite(7,LOW);
  long a = pulseIn(6,HIGH);
  float d =a*0.01715;
  Serial.print(d);
  Serial.print("cm\n");
  delay(1000);
}