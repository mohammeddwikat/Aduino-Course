#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

IRrecv myReceiver(5);
decode_results myResults;
IRsend mySender;


void setup(){
Serial.begin(9600);
myReceiver.enableIRIn(),
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);  
pinMode(3, OUTPUT);


}
// 13 Red
// 12 Green
// 11 Blue
void loop(){
  if(myReceiver.decode(&myResults)){
    
    if(myResults.decode_type == NEC){
      Serial.println(myResults.value);
      delay(500);
      Serial.println("NEC");
      mySender.sendSony(1231, 20);
      myReceiver.enableIRIn(),
      myReceiver.resume();
     }
  }
}
