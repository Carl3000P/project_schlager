String SendToArduino = "";
String prefix = "";
String LastCommand = "";

void setupKY_038(){
  pinMode(ky038APin, INPUT);
  pinMode(ky038DPin, INPUT);
}

void volumeHigh(){
  if(!equipamentBlocked){
    if(LastCommand != "01"){
      prefix = "01";
      LastCommand = "01";
    }
    digitalWrite(raspberryPin, HIGH);
  }
}

void volumeLow(){
  if(!equipamentBlocked){
    if(LastCommand != "00"){
      prefix = "00";
      LastCommand = "00";
    }
    digitalWrite(raspberryPin, LOW);
  }
}

void ky_read(void *args){
  while(1){
      ky038AValue = analogRead(ky038APin);
      ky038DValue = digitalRead(ky038DPin);
      vTaskDelay(50);
      if(ky038AValue >= MAX_KY_VALUE){
        volumeHigh();
        vTaskDelay(2000);
    } else  {
        volumeLow();
      }
      SendToArduino = prefix;
      SendToArduino.concat(String(ky038AValue, DEC));
      Serial.write(SendToArduino.c_str());
      Serial.flush();
      vTaskDelay(500);
  }
  vTaskDelete( NULL );
}
