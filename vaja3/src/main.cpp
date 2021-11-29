#include <Arduino.h>

int indx=0;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    char c = Serial.read(); 
    Serial.println(c);
    if( c=='#'){
      Serial.println("V zanki:");
      for(int n = 10; n<14; n++){
        while(Serial.available() == 0);
        c =  Serial.read();
        Serial.print(n);
        Serial.print(' ');
        Serial.println((int)c);
        if(c=='0') digitalWrite(n, HIGH);
        else if(c=='1')  digitalWrite(n, LOW);      
      }
    }
  }
}
