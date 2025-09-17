int ena =9;
int in1 = 7;
int in2 = 6;

int enb = 10;
int in3= 5;
int in4= 4;

int enc = 11;
int in5 = 3;
int in6 = 2;

char ch;
void setup(){
  pinMode(ena,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enc,OUTPUT);
  pinMode(in5,OUTPUT);
  pinMode(in6,OUTPUT);
  Serial.begin(9600);

}
void loop(){
  
  if(Serial.available()>0){
  	 ch=Serial.read();
  }
  digitalWrite(ena,HIGH);
  digitalWrite(enb,HIGH);
  digitalWrite(enc,HIGH);
  switch (ch) {
      case 'w':
        moveForward();
        break;
      case 's':
        moveBackward();
        break;
      case 'a':
        moveLeft();
        break;
      case 'd':
        moveRight();
        break;
      default:
        stopMotors();
        break;
    }
  

}
void moveForward() {
  Serial.println("FORWARD");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
}

void moveBackward() {
  
  Serial.println("BACKWARD");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
}

void moveLeft() {
  
  Serial.println("LEFT");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
}

void moveRight() {
  
  Serial.println("RIGHT");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
}
void stopMotors() {
  
  Serial.println("STOP");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
}