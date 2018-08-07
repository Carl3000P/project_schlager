#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "LedControl.h"
#define LED_BUILTIN 16

int ky038APin = A0;
int ky038DPin = 15;
int raspberryPin = 0;

int ky038AValue = 0;
int ky038DValue = 0;

int MAX_KY_VALUE = 100;


void setup() {
  Serial.begin(115200);
  delay(500);
  //Starting reading Thread
  xTaskCreate(ky_read, "ky_read", 20480, NULL, 2, NULL);
  //Defining Pins
  pinMode(ky038APin, INPUT);
  pinMode(ky038DPin, INPUT);
}

void DebugToSerial(String debug){
  //Serial.println(debug);
  //ProtocolNumberToESP = "11" + debug;
}

void ky_read(void *args){
  while(1){
      ky038AValue = analogRead(ky038APin);
      ky038DValue = digitalRead(ky038DPin);
      vTaskDelay(500);
      Serial.println(ky038AValue, DEC);
      if(ky038AValue >= MAX_KY_VALUE){
        Serial.write("01");
        digitalWrite(raspberryPin, HIGH);
      } else  {
          Serial.write("00");
          digitalWrite(raspberryPin, LOW);
      }
    }
  vTaskDelete( NULL );
}

void loop() {

}
