//control 2 servo with the help potentiometeer and electrostati
#include <Servo.h>
int a=0;
Servo s;
Servo s1;
int ultracm(int t,int e){
	digitalWrite(t, LOW);
  	delayMicroseconds(2);
  	digitalWrite(t, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(t, LOW);
  
  	int duration = pulseIn(e, HIGH);
  	float dist = duration * 0.01715;
	Serial.print("Distance: ");
  	Serial.print(dist);
  	Serial.println(" cm");
  	return dist;
}


void setup(){
	s.attach(9);
  s1.attach(10);
  pinMode(A0,INPUT);
 
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(6,INPUT);

}
void loop(){
	int potval = analogRead(A0);
  	int mappot = map(potval,0,1023,0,180);
  	int ul = ultracm(7,6);
  	int mapul = map(ul,20,350,0,180);	
  	s.write(mappot);
  s1.write(mapul);
  }
	
                      


