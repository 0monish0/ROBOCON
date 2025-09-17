int step = 5;
int dir = 4;int dtime = 1000;
int data[10]={0}; int sum;int c;
void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  c=0;
  digitalWrite(4,HIGH);
  digitalWrite(5, HIGH);
  delay(dtime);
  digitalWrite(5, LOW);
  delay(dtime);
  for(int i =0;i<10;i++){
  	int potval = analogRead(A0);
  	int mappot = map(potval,0,1023,100,2000);
    data[i]=mappot;
    delay(100);
  }
  for(int i =0;i<10;i++){

     sum+=data[i];
    
  }
  int r = data[9];
  if(sum ==(r*10)){
    if(c==0){
      Serial.print("CONSTANT VALUE:");
      Serial.println(r);
      c++;
    }
    delay(100);
    dtime= r;
    
  }
  sum=0;
}
