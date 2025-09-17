//code for variable rpm of dc gear toy motor through potentiometer 
void setup(){
	pinMode(3,OUTPUT);
  	pinMode(A5,INPUT);
  digitalWrite(3,LOW);
  Serial.begin(9600);
}
void loop(){
  int pval = analogRead(A5);
  Serial.print("Potent Value:");
  Serial.println(pval);
  int lval = map(pval,0,1023,0,255);
  Serial.print("Mapped Value:");
  Serial.println(lval);
  analogWrite(3,lval);
  delay(50);
	
}