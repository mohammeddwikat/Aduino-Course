#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
 
//Keypad myKeypad = (makeKeymap(), rowPins arr bytes, colPins arr bytes, ROWS 4 , COLS 4);
//get key
// setDebunceTime(int time);
char a[4][4] = {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
byte arr1[4] = {2,3,4,5};
byte arr2[4] = {8,9,10,11};
Keypad myKeypad(makeKeymap(a), arr1, arr2, 4,4);
String pass = "123123A";
String test = "";

int servo = 6;

Servo myServo;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int co = 0;
void setup(){
    Serial.begin(9600);  
    myServo.attach(servo);
    myServo.write(0);

    lcd.begin(16,2);
    lcd.clear();
}
void loop(){
    char gg = myKeypad.getKey();
    
    if(gg != '\0'){
        if(gg == '*'){
          if(test == pass){
            co = 0;
            Serial.println("Passed");
            lcd.clear();
            lcd.print("Passed");
            myServo.write(180); 
            test = "";
          }else{
            co = 0;
            test = "";
            lcd.clear();
            Serial.println("failed");
            lcd.print("failed");
            myServo.write(0);
          }
        }
        lcd.print(String(gg));
        co++;
        lcd.setCursor(co, 0);
        test += (String) gg;
    }
}