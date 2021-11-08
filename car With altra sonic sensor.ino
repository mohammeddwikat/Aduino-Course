//includes

int vcc1 = 2;
int vcc2 = 4;

//mot 1
int input1 = 9;
int input2 = 10;

//mot 2
int input3 = 12;
int input4 = 13;

int trig = 6;
int eco = 7;


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
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
}
void loop(){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long rea = pulseIn(eco,HIGH);
    //Serial.println();
    long val = (rea*0.034)/2;
  
  if(val > 500 && val < 1000){ //offf
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW); 
  
    digitalWrite(input3, HIGH);
    digitalWrite(input4, LOW); 

  }
  else if(val < 200){ // up 
      digitalWrite(input1, HIGH);
      digitalWrite(input2, LOW); 
    
      digitalWrite(input3, LOW);
      digitalWrite(input4, LOW); 
  
  }
  else if(val > 1000){  // down
      digitalWrite(input1, LOW);
      digitalWrite(input2, HIGH); 
    
      digitalWrite(input3, LOW);
      digitalWrite(input4, HIGH); 
  
     
  }
  Serial.println(val);
  delay(1000);
  
} 

/*
int trig = 8;
int eco = 9;

void setup(){
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    pinMode(eco, INPUT);
    
}
void loop(){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long rea = pulseIn(eco,HIGH);
    //Serial.println();
    long val = (rea*0.034)/2;

    Serial.println(val);

    delay(1000);
}






*/
