#include <Arduino.h>
#include <STM32FreeRTOS.h>

void tA(void *pvParameters);
void tB(void *pvParameters);
void tC(void *pvParameters);
SemaphoreHandle_t semA;
SemaphoreHandle_t semB;
SemaphoreHandle_t semC;

void vklopiLed(int n){
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(10+n,LOW);
}


void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  vklopiLed(3);
  semA=xSemaphoreCreateMutex();
  xSemaphoreGive(semA);
  semC=xSemaphoreCreateMutex();
  xSemaphoreGive(semC);
  semB=xSemaphoreCreateMutex();
  xSemaphoreGive(semB);


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
    if(xSemaphoreTake(semC, portMAX_DELAY )==pdTRUE){
      vTaskDelay(1);
      Serial.println("tA1");
      if(xSemaphoreTake(semA, portMAX_DELAY )==pdTRUE){
        vklopiLed(0);   
        Serial.println("tA2");
        delay(1000);
        xSemaphoreGive(semA);
      }
      xSemaphoreGive(semC);
    }
    vTaskDelay(1);
  }
}

void tB(void *pvParameters){
  while(1){
    if(xSemaphoreTake(semA, portMAX_DELAY )==pdTRUE){
      vTaskDelay(1);
      Serial.println("tB1");
      if(xSemaphoreTake(semB, portMAX_DELAY )==pdTRUE){
        vklopiLed(1);
        Serial.println("tB2");
        delay(1000);
        xSemaphoreGive(semB);
      }
      xSemaphoreGive(semA);
    }
    vTaskDelay(1);
  }
}
void tC(void *pvParameters){
  while(1){
    if(xSemaphoreTake(semB, portMAX_DELAY )==pdTRUE){
      vTaskDelay(1);
      Serial.println("tC1");
      if(xSemaphoreTake(semC, portMAX_DELAY )==pdTRUE){
        vklopiLed(2);
        Serial.println("tC2");
        delay(1000);
        xSemaphoreGive(semC);
      }
      xSemaphoreGive(semB);
    }
    vTaskDelay(1);
  }
}
