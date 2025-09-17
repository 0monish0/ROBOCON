//A servo motor's starting position (0° or 180°) is set by one ultrasonic sensor (U1).
//A slide switch (S1) then controls its action: it either stays still or moves to the opposite position.
//The speed of that movement is controlled by a second ultrasonic sensor (U2).

#include <Servo.h>
Servo s;
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

void move_ser(int deg, int time)
{
    int cpos = s.read();
    int st = cpos >= deg ? -1 : 1;
    for (int i = cpos; i != deg; i += st) {
        s.write(i);
        delay(time);
    }
    
}





void setup(){
  s.attach(12);
  pinMode(8,INPUT);
 
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(6,INPUT);
  pinMode(4,OUTPUT);
  pinMode(3,INPUT);

}

void loop(){
	
  int u1 = ultracm(7,6);
  int u2 = ultracm(4,3);
  int u2map= map(u2,20,350,0,100);
  if(digitalRead(8)==HIGH){
  		int d = u1<200? 0 : 180;
    	move_ser(d,u2map);
  }
  if(digitalRead(8)==LOW){
  		int dl = u1<200? 180 : 0;
    	move_ser(dl,u2map);
  }
}
