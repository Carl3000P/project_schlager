#define SERIAL_LED_PIN 5
#define ALERT_LED_PIN 4


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
