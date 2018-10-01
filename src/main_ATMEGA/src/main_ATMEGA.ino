#include "MotorUtils.h"
#include "UltrasonicUtils.h"
#include "MainController.h"
#include "LedControl.h"

int SENSOR1 = 2;
int SENSOR2 = 43;
int SENSOR3 = 44;
int SENSOR4 = 42;
int SENSOR5 = 12;

bool farLeftSensor, leftSensor, centerSensor,rightSensor, farRightSensor;

bool sensorInLine = false;
bool sensorOffLine = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //calibrate();
  delay(3000);

  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(SENSOR3, INPUT);
  pinMode(SENSOR4, INPUT);
  pinMode(SENSOR5, INPUT);

  setupMotor();
}

void loop() {

  readProtocol();
  ultrasonicRead();

  if(!stopProximity){
    if(!soundDetected){
      LedOff();
      farLeftSensor = sensorOffLine;
      leftSensor = sensorOffLine;
      centerSensor = sensorInLine;
      rightSensor = sensorOffLine;
      farRightSensor = sensorOffLine;


      motorA(SENTIDO_ANTIHORARIO);
      motorB(SENTIDO_ANTIHORARIO);


      //MOVIMENTACAO
      if(farLeftSensor == sensorOffLine && leftSensor == sensorOffLine &&  centerSensor == sensorInLine && rightSensor == sensorOffLine && farRightSensor == sensorOffLine ){ //RETO
        analogWrite(velocityA, VELOCITY_2_MOTOR);
        analogWrite(velocityB, VELOCITY_2_MOTOR);
        DebugToSerial("MDB\n");
      } else

      //CORRECAO DE ROTA
      if(farLeftSensor == sensorOffLine && leftSensor == sensorOffLine &&  centerSensor == sensorInLine && rightSensor == sensorInLine && farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA LEVE A ESQUERDA
        analogWrite(velocityA, VELOCITY_MIN_MOTOR);
        analogWrite(velocityB, VELOCITY_1_MOTOR);
        DebugToSerial("CORRECAO LEVE ESQUERDA\n");
      } else
      if(farLeftSensor == sensorOffLine && leftSensor == sensorInLine &&  centerSensor == sensorInLine && rightSensor == sensorOffLine && farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA LEVE A DIREITA
        analogWrite(velocityA, VELOCITY_1_MOTOR);
        analogWrite(velocityB, VELOCITY_MIN_MOTOR);
        DebugToSerial("CORRECAO LEVE DIREITA\n");
      } else
      if(farLeftSensor == sensorOffLine && leftSensor == sensorInLine &&  centerSensor == sensorOffLine && rightSensor == sensorOffLine && farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA ACENTUADA A DIREITA
        analogWrite(velocityA, VELOCITY_2_MOTOR);
        analogWrite(velocityB, VELOCITY_MIN_MOTOR);
        DebugToSerial("CORRECAO ACENTUADA DIREITA\n");
      } else
      if(farLeftSensor == sensorOffLine && leftSensor == sensorOffLine &&  centerSensor == sensorOffLine && rightSensor == sensorInLine && farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA ACENTUADA A ESQUERDA
        analogWrite(velocityA, VELOCITY_MIN_MOTOR);
        analogWrite(velocityB, VELOCITY_2_MOTOR);
        DebugToSerial("CORRECAO ACENTUADA ESQUERDA\n");
      } else

      //CURVA
      if(farLeftSensor == sensorInLine && leftSensor == sensorInLine &&  centerSensor == sensorInLine && farRightSensor == sensorOffLine ){ //CURVA ESQUERDA
        analogWrite(velocityA, VELOCITY_MIN_MOTOR);
        analogWrite(velocityB, VELOCITY_MAX_MOTOR);
        DebugToSerial("CURVA ESQUERDA\n");
      } else
      if(farLeftSensor == sensorOffLine &&  centerSensor == sensorInLine && rightSensor == sensorInLine && farRightSensor == sensorInLine ){ //CURVA DIREITA
        analogWrite(velocityA, VELOCITY_MAX_MOTOR);
        analogWrite(velocityB, VELOCITY_MIN_MOTOR);
        DebugToSerial("CURVA DIREITA\n");
      } else  {
       //FOUDEU
        analogWrite(velocityA, VELOCITY_MIN_MOTOR);
        analogWrite(velocityB, VELOCITY_MIN_MOTOR);
        DebugToSerial("SandroTheBest\n");
      }
}   else  {
      DebugToSerial("SoundDetected");
      analogWrite(velocityA, VELOCITY_MIN_MOTOR);
      analogWrite(velocityB, VELOCITY_MIN_MOTOR);
      LedOn();
    }
  }
}
