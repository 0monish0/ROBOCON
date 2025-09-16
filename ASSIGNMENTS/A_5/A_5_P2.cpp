//control speed of motor using potentiometer and displaying speed using lcd.
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x23,16,2);

int ena =9;
int in1 = 7;
int in2 = 6;
int tv=0;
int enb = 10;
int in3= 5;
int in4= 4;
void setup(){
  lcd.init();
  lcd.backlight();

  
  pinMode(ena,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);

}
void loop(){

  
  int pv = analogRead(A0);
  
  int mpv = map(pv,0,1023,0,255);
  analogWrite(ena,mpv);
  analogWrite(enb,mpv);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println(mpv);
  
  lcd.setCursor(0,0);
  lcd.print("pwm value:");
  lcd.print(mpv);
  
  int p = map(mpv,0,255,0,100);
  lcd.setCursor(0,1);
  lcd.print("speed % :");
  lcd.print(p);
  lcd.print("%");
  
  delay(1000);
  lcd.clear();

  

}
