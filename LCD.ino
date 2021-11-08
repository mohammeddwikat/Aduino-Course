#include <LiquidCrystal_I2C.h>
#include <Wire.h>
 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
void setup()
{
  lcd.begin(16,2);
  lcd.clear();
  String gg = "The Autstic";
  lcd.print("The Autistic");
 
  
}
 
 
void loop()
{
}