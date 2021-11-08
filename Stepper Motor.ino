#include <Stepper.h>

#include <VarSpeedServo.h>

/*
DDRD = ####
DDRB =  ###
DDRC= ####

DDR
PORT
PIN

PORTD = 

360 =>> 2048

120 =>> ??

120 * 2048 / 360 = 
 i << 1 (<< 4)
*/

void setup(){
  Serial.begin(9600);
  byte i = 0b11110000; // 4 - 7 
  DDRD = DDRD | i;

  
  
}

void loop(){

   int val;
   if(Serial.available()){
      val = Serial.parseInt();
      Serial.println(val);
    }

    
    long steps = val*6;
    Serial.println(steps);
    int counter  = 0;
    byte str = 0b0001;
    for(long i=0 ; i < steps ; i++){
        PORTD = (PORTD & 0b00001111) | (str << 4); 
        str = str << 1 ;
        
        if(counter == 4){
          str = 0b0001;
          counter = 0;
        }
        else
          counter++;
        delay(5);
    }
    

   
}
