#include <Wire.h>

#include <LiquidCrystal_I2C.h>

// C++ code
//interfacing LCD thorugh I2c and printing name


LiquidCrystal_I2C lcd(0x23,16,2);
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("MONISH");
  lcd.setCursor(1,1);
  lcd.print("Hello, World!");
  
}

void loop(){

}