#include "../lib/Ultrasonic/Ultrasonic.h"

Ultrasonic ultrasonic1(pino_trigger1, pino_echo1);
Ultrasonic ultrasonic2(pino_trigger2, pino_echo2);

void ultrasonicRead(){

  microsec1 = ultrasonic1.timing();
  cmMsec1 = ultrasonic1.convert(microsec1, Ultrasonic::CM);
  if(cmMsec1 <= 30){
    stopProximity1 = true;
  } else {
    stopProximity1 = false;
  }

  microsec2 = ultrasonic2.timing();
  cmMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::CM);
  if(cmMsec2 <= 30){
    stopProximity2 = true;
  } else{
    stopProximity2 = false;
  }

  if(stopProximity2 || stopProximity1){
    stopProximity = true;
  } else {
      stopProximity = false;
  }
}
