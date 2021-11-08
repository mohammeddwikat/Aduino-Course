int value = 9;
int value2 = 8;
int stateLed = 0;
int bs = 1;

void setup(){
    Serial.begin(9600);
    pinMode(value, INPUT_PULLUP);
    pinMode(value2, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop(){
     
     int buttonState = digitalRead(value);
     
     Serial.println(buttonState);

     if(buttonState == 1){
        delay(60);
        buttonState = digitalRead(value);
        if(buttonState == 1){
            bs =1;
            if(stateLed == 1){
              digitalWrite(value2, HIGH);
              digitalWrite(11, HIGH);

            }
            else{
              digitalWrite(value2, LOW);
              digitalWrite(11, LOW);

            }
            
        }
     }
     else if(buttonState == 0){
        delay(60);
        buttonState = digitalRead(value);
        if(buttonState == 0){
          if(bs == 1){
            bs = 0;
            if(stateLed == 1){
              digitalWrite(value2, LOW);
              digitalWrite(11, LOW);

              stateLed = 0;
            }
            else{
              digitalWrite(value2, HIGH);
               digitalWrite(11, HIGH);
              stateLed = 1;
            }
          }
          
        }
        
     }

     
}
