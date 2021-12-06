#include <Arduino.h>
#include <STM32FreeRTOS.h>

void task1(void *pvParameters);
void task2(void *pvParameters);

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
  xTaskCreate(task1, "T1", 128, NULL, 2, NULL);
  xTaskCreate(task2, "T2", 128, NULL, 2, NULL);
  vTaskStartScheduler();
}

void loop() {
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  Serial.print("Idle task:"); 
  Serial.println(millis());
  delay(2000);
}

void task1(void *pvParameters){
  while(1){
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    Serial.print("Task1: ");
    Serial.println(millis());
    vTaskDelay(2000/portTICK_PERIOD_MS);
  }
}

void task2(void *pvParameters){
  while(1){
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    Serial.print("Task2: ");
    Serial.println(millis());
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}