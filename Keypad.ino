#include <Keypad.h>

//Keypad myKeypad = (makeKeymap(), rowPins arr bytes, colPins arr bytes, ROWS 4 , COLS 4);
//get key
// setDebunceTime(int time);
char a[4][4] = {{'1','2','3','4'},{'5','6','7','8'},{'9','A','B','C'},{'D','E','F','G'}};
   
byte arr1[4] = {2,3,4,5};
byte arr2[4] = {8,9,10,11};
Keypad myKeypad(makeKeymap(a), arr1, arr2, 4,4);
void setup(){
    Serial.begin(9600);
}
void loop(){
    char gg = myKeypad.getKey();
    if(gg != '\0'){
       Serial.println(gg);
    }
}
