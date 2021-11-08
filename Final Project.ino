#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


IRrecv myReceiver(5);
decode_results myResults;
IRsend mySender;
int score = 10;



int input1 = 9;
int input2 = 10;

//mot 2
int input3 = 12;
int input4 = 13;

void setup(){
  Serial.begin(9600);
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);
  pinMode(input4, INPUT);
  pinMode(3, OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
  
  lcd.print("Autistic : " + (String)score);
  myReceiver.enableIRIn();
}
char c;
void loop(){
  c = '\0';
  if(Serial.available() > 0){
   delay(50);
   c = Serial.read();
   switch(c){
    case 'F':
      
      digitalWrite(input1, LOW);
      digitalWrite(input2, HIGH); 
    
      digitalWrite(input3, LOW);
      digitalWrite(input4, HIGH); 
      break;
    case 'B':
      digitalWrite(input1, HIGH);
      digitalWrite(input2, LOW); 
      Serial.println("ASDASD");      
      digitalWrite(input3, HIGH);
      digitalWrite(input4, LOW);
      break;
    case 'R':
      digitalWrite(input1, LOW);
      digitalWrite(input2, HIGH); 
    
      digitalWrite(input3, LOW);
      digitalWrite(input4, LOW); 
      break;
    case 'L':
      digitalWrite(input1, LOW);
      digitalWrite(input2, LOW); 
      
      digitalWrite(input3, LOW);
      digitalWrite(input4, HIGH); 
      break;
     case 'S':
          mySender.sendSony(1231, 20);
          break;
    default:
      digitalWrite(input1, LOW);
      digitalWrite(input2, LOW); 
      
      digitalWrite(input3, LOW);
      digitalWrite(input4, LOW);
      Serial.print(c);
      break;
  }
      
  }
  if(myReceiver.decode(&myResults)){
    if(myResults.decode_type == NEC){
      Serial.println(myResults.value);
      score--;
      digitalWrite(input1, LOW);
      digitalWrite(input2, LOW); 
      digitalWrite(input3, LOW);
      digitalWrite(input4, LOW);
      delay(5000);
      Serial.println("NEC");
      myReceiver.enableIRIn(),
      myReceiver.resume();
     }
  }
  lcd.clear();
  lcd.print("Autistic : " + (String)score);

}
