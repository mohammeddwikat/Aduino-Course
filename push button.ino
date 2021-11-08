//variables

int val = 13;
int val2 = 7;
void setup() {
  // put your setup code here, to run once:
   pinMode(val, OUTPUT);
   pinMode(val2, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  bool x=digitalRead(val2);
  
  digitalWrite(val, !x);
      
}




