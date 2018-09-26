#pragma once

#define relayPin 0 //TODO define relayPin

bool soundDetected = false;

String ProtocolNumber = "";
String ProtocolOperation = "";
String ProtocolCommand = "";

String ProtocolNumberToESP = "";
String LastCommandToESP = "";

void DebugToSerial(String debug){ //Function that controls debug information to not flood Serial communication
  Serial.println(debug);
  //ProtocolNumberToESP = "11" + debug;
}

void readProtocol(){
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

   if(ProtocolOperation == "0"){
     if(ProtocolCommand == "0"){
       soundDetected = false;
       digitalWrite(relayPin, LOW);
     } else
     if(ProtocolCommand == "1"){
       soundDetected = true;
       digitalWrite(relayPin, HIGH);
     }
   }
}
