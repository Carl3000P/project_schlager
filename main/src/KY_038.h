void setupKY_038(){
  pinMode(ky038APin, INPUT);
  pinMode(ky038DPin, INPUT);
}

void volumeHigh(){
  if(!equipamentBlocked){
    digitalWrite(raspberryPin, HIGH);
    LedOn();
    soundDetected = true;
    delay(2000);
    Serial.println("Volume High");
    Serial.println("Pins Highed");
    Serial.println("____________");
  }
}

void volumeLow(){
  if(!equipamentBlocked){
    digitalWrite(raspberryPin, LOW);
    LedOff();
    soundDetected = false;
    Serial.println("Volume Low");
    Serial.println("Pins Lowered");
    Serial.println("____________");
  }
}

void ky_read(){
      ky038AValue = analogRead(ky038APin);
      ky038DValue = digitalRead(ky038DPin);
      delay(50);
      if(ky038AValue >= MAX_KY_VALUE){
        volumeHigh();
    } else  {
        volumeLow();
      }
      Serial.print("Sound: ");
      Serial.println(ky038AValue);
      delay(100);
  }
