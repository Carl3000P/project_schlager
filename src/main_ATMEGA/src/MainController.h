#pragma once

#define relayPin 22 //TODO define relayPin

bool soundDetected = false;

bool ProtocolNumber;

String ProtocolNumberToESP = "";
String LastCommandToESP = "";

void DebugToSerial(String debug){ //Function that controls debug information to not flood Serial communication
  Serial.println(debug);
}

void readProtocol(){

      ProtocolNumber = digitalRead(22);

     delay(200);

     if(ProtocolNumber == false){
       soundDetected = false;
       digitalWrite(relayPin, LOW);
     } else
     if(ProtocolNumber == true){
       soundDetected = true;
       digitalWrite(relayPin, HIGH);
     }
}
