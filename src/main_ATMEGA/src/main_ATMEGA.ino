#include "LedControl.h"

#define relayPin 0 //TODO define relayPin

void setup() {
  Serial.begin(115200);
  delay(500);
  ////Serial.println("Start...");
  setupLEDS();
}

void DebugToSerial(String debug){ //Function that controls debug information to not flood Serial communication
  //Serial.println(debug);
  //ProtocolNumberToESP = "11" + debug;
}

void loop() {

 if (Serial.available() > 0) {

    ProtocolNumber = Serial.readString();

    // say what you got:
    DebugToSerial("Command received: ");
    DebugToSerial(ProtocolNumber);

    ProtocolOperation = ProtocolNumber.substring(0, 1);
    DebugToSerial("Protocol Operation: ");
    DebugToSerial(ProtocolOperation);

    ProtocolCommand = ProtocolNumber.substring(1);
    DebugToSerial("Protocol Command: ");
    DebugToSerial(ProtocolCommand);
  }

  } else
  if(ProtocolOperation == "0"){
    if(ProtocolCommand == "0"){
      digitalWrite(relayPin, LOW);
    } else
    if(ProtocolCommand == "1"){
      digitalWrite(relayPin, HIGH);
    }
  }
}
