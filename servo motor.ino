#include <Servo.h>
Servo myServo;

int servo = 9;
int value2 = A2;

void setup(){
    pinMode(value, OUTPUT);
    pinMode(value2, INPUT);
    myServo.attach(servo);
    myServo.write(0);
    
}
void loop(){
  int dota = analogRead(value2);

  int gg = map(dota, 0, 1023, 0 , 180);

  myServo.write(gg);
  
  
}

// anglewith speed

#include <VarSpeedServo.h>





int value =9;
int value2=A1;
VarSpeedServo ob;

void setup(){
      
  pinMode(value, OUTPUT);
  pinMode(value2 , INPUT);
  ob.attach(value);
  ob.write(180,120, true);

  
}

void loop(){
  int ff= analogRead(value2);
  int speed = map(ff,0,1023,0,255 );

  if(ob.read()== 0){
    ob.write(180,speed,false);
  }
  else if(ob.read()== 180){
    ob.write(0,speed,false);
  }
  
  
}

