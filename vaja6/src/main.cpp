#include <Arduino.h>
#include <STM32FreeRTOS.h>

static void nitLed1(void* arg) {
  UNUSED(arg);
  while (1) {
    digitalWrite(10, LOW);
    vTaskDelay(500/portTICK_PERIOD_MS);
    digitalWrite(10, HIGH);
    vTaskDelay(500/portTICK_PERIOD_MS);
  }
}

static void nitLed2(void* arg) {
  UNUSED(arg);
  while (1) {
    digitalWrite(11, LOW);
    vTaskDelay(166/portTICK_PERIOD_MS);
    digitalWrite(11, HIGH);
    vTaskDelay(166/portTICK_PERIOD_MS);
  }
}

static void nitLed3(void* arg) {
  UNUSED(arg);
  while (1) {
    digitalWrite(12, LOW);
    vTaskDelay(133/portTICK_PERIOD_MS);
    digitalWrite(12, HIGH);
    vTaskDelay(133/portTICK_PERIOD_MS);
  }
}

static void serial(void* arg) {
  UNUSED(arg);
  while (1) {
    Serial.println("Cetrta nit....");
    vTaskDelay(100/portTICK_PERIOD_MS);
  }
}

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  xTaskCreate(nitLed1, NULL, 256, NULL, 1, NULL);
  xTaskCreate(nitLed2, NULL, 256, NULL, 1, NULL);
  xTaskCreate(nitLed3, NULL, 256, NULL, 1, NULL);
  xTaskCreate(serial, NULL, 256, NULL, 1, NULL);
  vTaskStartScheduler();
}

void loop() {

}