// C++ code
//controlling 4 led lighting sequentially using potentiometer
void setup()
{
  pinMode(A4, INPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
	int a = analogRead(A4);
  	Serial.println(a);
  if(a>0 &&a<250){
  	digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
  }
  if(a>250 &&a<500){
  	digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
  }if(a>500 &&a<800){
  	digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
  }if(a>800 &&a<1023){
  	digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);}
  
}