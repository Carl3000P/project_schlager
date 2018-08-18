#include "MainController.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "KY_038.h"
#include "Keypad.h"

void setup() {
  Serial.begin(115200);
  delay(500);
  //Starting reading Thread
  xTaskCreate(ky_read, "ky_read", 8192, NULL, 2, NULL);
  //Defining Pins
  setupKY_038();
  pinMode(raspberryPin, OUTPUT);
  pinMode(unoPin, OUTPUT);
}

void DebugToSerial(String debug){ //Function that controls debug information to not flood Serial communication
  //Serial.println(debug);
  //ProtocolNumberToESP = "11" + debug;
}

void loop() {
  char pressed_key = keypad.getKey();
  //Mostra no serial monitor o caracter da matriz,
  //referente a tecla que foi pressionada
  if (pressed_key){
    Serial.println(pass_key);
    if(pressed_key == '#'){
      if(pass_key == "1234"){
        equipamentBlocked = false;
        digitalWrite(unoPin, HIGH);
      }
    }
    pass_key.concat(String(pressed_key));
    //Serial.println("Tecla pressionada : ");
    //Serial.print(pressed_key);
  }
}
