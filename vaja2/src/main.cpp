#include <Arduino.h>

int staroStanje;
int stanjeLED = 0;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(A1, INPUT);
}

void loop() {
  int stanje = digitalRead(A1);
  if(staroStanje == 1 && stanje == 0){
    digitalWrite(12, stanjeLED);
    stanjeLED=!stanjeLED;
    delay(100);
  }

  staroStanje = stanje;

}