void setupKY_038(){
  pinMode(ky038APin, INPUT);
  pinMode(ky038DPin, INPUT);
}

void volumeHigh(){
  if(!equipamentBlocked){
    Serial.write("01");
    digitalWrite(raspberryPin, HIGH);
  }
}

void volumeLow(){
  if(!equipamentBlocked){
    Serial.write("00");
    digitalWrite(raspberryPin, LOW);
  }
}

void ky_read(void *args){
  while(1){
      ky038AValue = analogRead(ky038APin);
      ky038DValue = digitalRead(ky038DPin);
      vTaskDelay(50);
      Serial.println(ky038AValue, DEC);
      if(ky038AValue >= MAX_KY_VALUE){
        volumeHigh();
        vTaskDelay(200);
    } else  {
        volumeLow();
      }
  }
  vTaskDelete( NULL );
}
