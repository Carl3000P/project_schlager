void setupLEDS() {
  //DebugToSerial("Led 1 set");
  pinMode(ALERT_LED_PIN, OUTPUT);
}

void LedOn(){
  digitalWrite(ALERT_LED_PIN, HIGH);
}

void LedOff(){
  digitalWrite(ALERT_LED_PIN, LOW);
}
