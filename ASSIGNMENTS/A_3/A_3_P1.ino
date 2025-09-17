//Enter a decimal integer between 0 and 1000.
//Convert the integer to binary number.
//For every binary bits obtained, turn respective led on or off. Every bit should be represented by a seperate led.

const int led_n = 10;                           
const int led_p[led_n] = {13,12,11,10,9,8,7,6,5,4};  

void setup()
{
  for (int i = 0; i < led_n; i++) {
    pinMode(led_p[i], OUTPUT);
    digitalWrite(led_p[i], LOW);                 
  }
  Serial.begin(9600);
  Serial.println("Enter a number between 0-1000:");
}

void dtb(int x)
{
  for (int i = 0; i < led_n; i++) {
    int bitVal = (x >> i) & 1;                   
    digitalWrite(led_p[i], bitVal);              
  }
}

void loop()
{
  if (Serial.available() > 0) {
    int num = Serial.parseInt();                 
    if (num >= 0 && num <= 1000) {
      Serial.print("Decimal: ");
      Serial.println(num);
      Serial.print("Binary : ");
      for (int i = led_n - 1; i >= 0; i--) {
        Serial.print((num >> i) & 1);            
      }
      Serial.println();
      dtb(num);                                  
    } else {
      Serial.println("number out of range, enter 0-1000");
    }
  }
}
