//includes


//variables
int val = 9;
int val2 = 10;
int val3 = 5; 

int cal = 12;
int cal2 = 13;
int cal3 = 6; 

void setup(){
  pinMode(val, OUTPUT);
  pinMode(val2, OUTPUT);
  pinMode(cal, OUTPUT);
  pinMode(cal2, OUTPUT);
  pinMode(val3, OUTPUT);
  pinMode(cal3, OUTPUT);

}
void loop(){

  digitalWrite(val, LOW);
  digitalWrite(val2, HIGH); 

  digitalWrite(cal, LOW);
  digitalWrite(cal2, HIGH); 

  for(int i=0 ; i < 255; i++){
      analogWrite(cal3, i); 
      analogWrite(val3, i); 
  }
} 
