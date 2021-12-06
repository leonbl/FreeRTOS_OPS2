#include <Arduino.h>
#include <STM32FreeRTOS.h>

void task1(void *pvParameters);
void task2(void *pvParameters);

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  xTaskCreate(task1, "T1", 128, NULL, 2, NULL);
  xTaskCreate(task2, "T2", 128, NULL, 2, NULL);
  vTaskStartScheduler();
}

void loop() {
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  Serial.println("Task1");
  vTaskDelay(500/portTICK_PERIOD_MS);
}

void task1(void *pvParameters){
  while(1){
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    Serial.println("Task1");
    vTaskDelay(100/portTICK_PERIOD_MS);
  }
}

void task2(void *pvParameters){
  while(1){
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    Serial.println("Task2");
    vTaskDelay(200/portTICK_PERIOD_MS);
  }
}