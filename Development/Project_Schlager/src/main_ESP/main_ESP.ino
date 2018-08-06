#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "LedControl.h"

int ky038Pin = A0; 
int raspberryPin = 0;

int ky038Value = 0;

int MAX_KY_VALUE = 100;

void DebugToSerial(String debug){
  //Serial.println(debug);
  //ProtocolNumberToESP = "11" + debug;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500);
  //DebugToSerial("Start...");
  xTaskCreate(ky_read, "ky_read", 10240, NULL, 2, NULL);
  xTaskCreate(verifyKy038Value, "verifyKy038Value", 10240, NULL, 3, NULL);
  
}

void ky_read(void *args){
  while(1){
      ky038Value = analogRead(ky038Pin);
      //DebugToSerial(ky038Value, DEC);
    }
  vTaskDelete( NULL );
}

void verifyKy038Value(void *args){
  while(1){
      if(ky038Value >= MAX_KY_VALUE){
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
