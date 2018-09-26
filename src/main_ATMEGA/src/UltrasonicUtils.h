#include "../lib/Ultrasonic/Ultrasonic.h"

#define pino_trigger2 10
#define pino_echo2 11
#define pino_trigger1 12
#define pino_echo1 13

Ultrasonic ultrasonic1(pino_trigger1, pino_echo1);
Ultrasonic ultrasonic2(pino_trigger2, pino_echo2);

bool stopProximity = false;
float cmMsec1;
long microsec1;
float cmMsec2;
long microsec2;

void ultrasonicRead(){
  microsec1 = ultrasonic1.timing();
  cmMsec1 = ultrasonic1.convert(microsec1, Ultrasonic::CM);
  if(cmMsec1 <= 30){
    stopProximity = true;
  } else {
    stopProximity = false;
  }

  microsec2 = ultrasonic2.timing();
  cmMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::CM);
  if(cmMsec2 <= 30){
    stopProximity = true;
  } else{
    stopProximity = false;
  }
}
