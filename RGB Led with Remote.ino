#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

IRrecv myReceiver(5);
decode_results myResults;



void setup(){
Serial.begin(9600);
myReceiver.enableIRIn(),
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);  


}
// 13 Red
// 12 Green
// 11 Blue
void loop(){
  if(myReceiver.decode(&myResults))
  {
    
    if(myResults.decode_type == NEC){
    Serial.println(myResults.value);
    delay(500);
    Serial.println("NEC");
    

     if((myResults.value) == 16738455){
          digitalWrite(11,LOW);
          digitalWrite(12,LOW);
          digitalWrite(13,LOW);
      }
      else if((myResults.value) == 16724175){
          digitalWrite(11,HIGH);
          digitalWrite(12,LOW);
          digitalWrite(13,LOW);
      }
      else if((myResults.value) == 16718055 ){
          digitalWrite(11,LOW);
          digitalWrite(12,HIGH);
          digitalWrite(13,LOW);
      }
      else if((myResults.value) == 16743045  ){
          digitalWrite(11,LOW);
          digitalWrite(12,LOW);
          digitalWrite(13,HIGH);
      }
      else {
         digitalWrite(11,LOW);
          digitalWrite(12,LOW);
          digitalWrite(13,LOW);
        }
      myReceiver.resume();
     }
     else Serial.println("Unkown");

  }
}
