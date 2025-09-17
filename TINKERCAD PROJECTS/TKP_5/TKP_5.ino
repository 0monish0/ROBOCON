// interfacing 2 dc motors with l293d controlling speed thourgh serial monitor
// enter value range from 0 to 255 only
int ena =9;
int in1 = 7;
int in2 = 6;

int enb = 10;
int in3= 5;
int in4= 4;
int dc=0;
void setup(){
  pinMode(ena,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  Serial.begin(9600);

}
void loop(){
  
  if(Serial.available()>0){
  	 dc=Serial.parseInt();
  }
  analogWrite(ena,dc);
  analogWrite(enb,dc);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  

}