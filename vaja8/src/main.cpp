#include <Arduino.h>
#include <STM32FreeRTOS.h>

void tA(void *pvParameters);
void tB(void *pvParameters);
void tC(void *pvParameters);
SemaphoreHandle_t serSem;

void setup() {
  Serial.begin(9600);
  if(serSem == NULL){
    serSem=xSemaphoreCreateMutex();
    if(serSem != NULL){
      xSemaphoreGive(serSem);
    }
  }

  //xSemaphoreTake(serSem, (TickType_t)5);
  xTaskCreate(tA, "tA", 128, NULL, 2, NULL);
  xTaskCreate(tB, "tB", 128, NULL, 2, NULL);
  xTaskCreate(tC, "tC", 128, NULL, 2, NULL);
  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void tA(void *pvParameters){
  while(1){
    if(xSemaphoreTake(serSem, (TickType_t)5)==1){
      Serial.println("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
      xSemaphoreGive(serSem);
    }
    vTaskDelay(1);
  }
}

void tB(void *pvParameters){
  while(1){
    if(xSemaphoreTake(serSem, (TickType_t)5)==pdTRUE){
      Serial.println("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
      xSemaphoreGive(serSem);
    }
    vTaskDelay(1);
  }
}

void tC(void *pvParameters){
  while(1){
    if(xSemaphoreTake(serSem, (TickType_t)5)==1){
      Serial.println("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
      xSemaphoreGive(serSem);
    }
    vTaskDelay(1);
  }
}