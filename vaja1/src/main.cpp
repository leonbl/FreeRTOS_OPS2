#include <Arduino.h>
int d = 200;
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  for(int n=11; n<13; n++){
    digitalWrite(n, LOW);
    delay(d);
    digitalWrite(n, HIGH);
    delay(d);
    d-=10;
    if(d<=0)d=200;
  }
  for(int n=13; n>9; n--){
    digitalWrite(n, LOW);
    delay(d);
    digitalWrite(n, HIGH);
    delay(d);
     d-=10;
    if(d<=0)d=200;
  }
}