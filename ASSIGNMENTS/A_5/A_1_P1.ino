// controlling left or right motion through input by ultrasonic sensor
#include <Servo.h>
int ena = 9;
int in1 = 7;
int in2 = 6;
int enb = 10;
int in3 = 5;
int in4 = 4;
int trig = 2;
int echo = 3;
void setup() {
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);}
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int duration = pulseIn(echo, HIGH);
  float d = duration * 0.01715; 
  Serial.print("Distance: ");
  Serial.print(d);
  Serial.println(" cm");
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
    if(d>=20 && d<=100){
    	Serial.println("Turning Left");
      analogWrite(ena,50);
	  analogWrite(enb,255);
      
    }
  else{if(d>200 && d<=350){
    	Serial.println("Turning Right");
      analogWrite(ena,255);
      analogWrite(enb,50);}
       else{
	  analogWrite(ena,255);
         analogWrite(enb,255);}  
      }
}


