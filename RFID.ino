#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
MFRC522 myRFID(10, 9);
byte test[4] = {0x97, 0xB4, 0x69, 0x34};

void setup(){
  SPI.begin();
  myRFID.PCD_Init();
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
}
void loop(){
  if(myRFID.PICC_IsNewCardPresent() == true){
    if(myRFID.PICC_ReadCardSerial() == true){
        lcd.clear();

        bool flag = false;
        for(int i=0 ; i <4 ;i++){
          if(myRFID.uid.uidByte[i] != test[i]){
            flag = false;
            Serial.println("Failed");
            lcd.print("Failed");
            delay(2000);
            break;
          }
          else{
            flag = true;
          }
        }
        if(flag){
          Serial.println("Passed");
          lcd.print("Passed");
          delay(2000);
        }
        
    }
  }
}
