//includes

int vcc1 = 2;
int vcc2 = 4;

//mot 1
int input1 = 9;
int input2 = 10;

//mot 2
int input3 = 12;
int input4 = 13;

void setup(){
  Serial.begin(9600);
  pinMode(A1, INPUT); // x
  pinMode(A2, INPUT); // y
  pinMode(7, INPUT); // switch
  //---------------------

  pinMode(vcc1, INPUT);
  pinMode(vcc2, INPUT);
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);
  pinMode(input4, INPUT);


}
void loop(){
  
  int x = analogRead(A1);
  int y = analogRead(A2);
  int s = digitalRead(7);
  
  if(x > 400 && x < 700 && y > 400 && y < 700){ //offf
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW); 
  
    digitalWrite(input3, LOW);
    digitalWrite(input4, LOW); 

  }
  else if(y >= 0 && y < 100 && x >= 500 && x <= 600  ){ // up 
      digitalWrite(input1, HIGH);
      digitalWrite(input2, LOW); 
    
      digitalWrite(input3, HIGH);
      digitalWrite(input4, LOW); 
  
  }
  else if(y >= 1000 && x >= 500 && x <= 600   ){  // down
      digitalWrite(input1, LOW);
      digitalWrite(input2, HIGH); 
    
      digitalWrite(input3, LOW);
      digitalWrite(input4, HIGH); 
  
     
  }
  else if( y >= 500 && y < 600 && x >= 1000){ // right
      digitalWrite(input1, LOW);
      digitalWrite(input2, LOW); 
    
      digitalWrite(input3, HIGH);
      digitalWrite(input4, LOW); 
  
  }else if(y >=500 && y < 600 && x >= 0 && x < 100){ // left
      digitalWrite(input1, HIGH);
      digitalWrite(input2, LOW); 
      
      digitalWrite(input3, LOW);
      digitalWrite(input4, LOW); 
  
  }else{
      digitalWrite(input1, LOW);
      digitalWrite(input2, LOW); 
      
      digitalWrite(input3, LOW);
      digitalWrite(input4, LOW); 
  }
  
} 
