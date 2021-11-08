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
