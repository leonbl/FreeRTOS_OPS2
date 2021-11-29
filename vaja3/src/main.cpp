#include <Arduino.h>
char c = 65;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(c++);
  delay(100);
  if(c > 90) c=65;
}
