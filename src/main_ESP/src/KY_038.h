String SendToArduino = "";
String prefix = "";
String LastCommand = "";

void setupKY_038(){
  pinMode(ky038APin, INPUT);
  pinMode(ky038DPin, INPUT);
}

void volumeHigh(){
  if(!equipamentBlocked){
    digitalWrite(raspberryPin, HIGH);
    digitalWrite(27, HIGH);
    vTaskDelay(2000);
    Serial.println("Volume High");
    Serial.println("Pins Highed");
    Serial.println("____________");
  }
}

void volumeLow(){
  if(!equipamentBlocked){
    digitalWrite(raspberryPin, LOW);
    digitalWrite(27, LOW);
    Serial.println("Volume Low");
    Serial.println("Pins Lowered");
    Serial.println("____________");
  }
}

void ky_read(void *args){
  while(1){
      ky038AValue = analogRead(ky038APin);
      ky038DValue = digitalRead(ky038DPin);
      vTaskDelay(50);
      if(ky038AValue >= MAX_KY_VALUE){
        volumeHigh();
    } else  {
        volumeLow();
      }
      Serial.println(ky038AValue);
      vTaskDelay(500);
  }
  vTaskDelete( NULL );
}
