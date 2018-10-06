#include "MotorUtils.h"
#include "UltrasonicUtils.h"
#include "MainController.h"
#include "LedControl.h"

int SENSOR1 = 42;
int SENSOR2 = 44;
int SENSOR3 = 46;
int SENSOR4 = 48;
int SENSOR5 = 50;

int SENSOR6 =  43;
int SENSOR7 =  45;
int SENSOR8 =  47;
int SENSOR9 =  49;
int SENSOR10 = 51;

bool FRONT_farLeftSensor, FRONT_leftSensor, FRONT_centerSensor,FRONT_rightSensor, FRONT_farRightSensor;
bool BACK_farLeftSensor, BACK_leftSensor, BACK_centerSensor,BACK_rightSensor, BACK_farRightSensor;

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

  pinMode(SENSOR6, INPUT);
  pinMode(SENSOR7, INPUT);
  pinMode(SENSOR8, INPUT);
  pinMode(SENSOR9, INPUT);
  pinMode(SENSOR10, INPUT);

  setupMotor();
}

void loop() {

  readProtocol();
  ultrasonicRead();

  FRONT_farLeftSensor = digitalRead(SENSOR1);
  FRONT_leftSensor = digitalRead(SENSOR2);
  FRONT_centerSensor = digitalRead(SENSOR3);
  FRONT_rightSensor = digitalRead(SENSOR4);
  FRONT_farRightSensor = digitalRead(SENSOR5);

  BACK_farLeftSensor = digitalRead(SENSOR6);
  BACK_leftSensor = digitalRead(SENSOR7);
  BACK_centerSensor = digitalRead(SENSOR8);
  BACK_rightSensor = digitalRead(SENSOR9);
  BACK_farRightSensor = digitalRead(SENSOR10);

  if(!stopProximity){
    if(!soundDetected){
          LedOff();
          motorA(SENTIDO_ANTIHORARIO);
          motorB(SENTIDO_ANTIHORARIO);


          //MOVIMENTACAO
          if(FRONT_farLeftSensor == sensorOffLine && FRONT_leftSensor == sensorOffLine &&  FRONT_centerSensor == sensorInLine && FRONT_rightSensor == sensorOffLine && FRONT_farRightSensor == sensorOffLine ){ //RETO
            analogWrite(velocityA, VELOCITY_2_MOTOR);
            analogWrite(velocityB, VELOCITY_2_MOTOR);
            DebugToSerial("MDB\n");
          } else

          //CORRECAO DE ROTA
          if(FRONT_farLeftSensor == sensorOffLine && FRONT_leftSensor == sensorOffLine &&  FRONT_centerSensor == sensorInLine && FRONT_rightSensor == sensorInLine && FRONT_farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA LEVE A ESQUERDA
            analogWrite(velocityB, VELOCITY_MIN_MOTOR);
            analogWrite(velocityA, VELOCITY_1_MOTOR);
            DebugToSerial("CORRECAO LEVE ESQUERDA\n");
          } else
          if(FRONT_farLeftSensor == sensorOffLine && FRONT_leftSensor == sensorInLine &&  FRONT_centerSensor == sensorInLine && FRONT_rightSensor == sensorOffLine && FRONT_farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA LEVE A DIREITA
            analogWrite(velocityB, VELOCITY_1_MOTOR);
            analogWrite(velocityA, VELOCITY_MIN_MOTOR);
            DebugToSerial("CORRECAO LEVE DIREITA\n");
          } else
          if(FRONT_farLeftSensor == sensorOffLine && FRONT_leftSensor == sensorInLine &&  FRONT_centerSensor == sensorOffLine && FRONT_rightSensor == sensorOffLine && FRONT_farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA ACENTUADA A DIREITA
            analogWrite(velocityB, VELOCITY_2_MOTOR);
            analogWrite(velocityA, VELOCITY_MIN_MOTOR);
            DebugToSerial("CORRECAO ACENTUADA DIREITA\n");
          } else
          if(FRONT_farLeftSensor == sensorOffLine && FRONT_leftSensor == sensorOffLine &&  FRONT_centerSensor == sensorOffLine && FRONT_rightSensor == sensorInLine && FRONT_farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA ACENTUADA A ESQUERDA
            analogWrite(velocityB, VELOCITY_MIN_MOTOR);
            analogWrite(velocityA, VELOCITY_2_MOTOR);
            DebugToSerial("CORRECAO ACENTUADA ESQUERDA\n");
          } else

          //CURVA
          if(FRONT_farLeftSensor == sensorInLine && FRONT_leftSensor == sensorInLine &&  FRONT_centerSensor == sensorInLine && FRONT_farRightSensor == sensorOffLine ){ //CURVA ESQUERDA
            analogWrite(velocityA, VELOCITY_MIN_MOTOR);
            analogWrite(velocityB, VELOCITY_MAX_MOTOR);
            DebugToSerial("CURVA ESQUERDA\n");
          } else
          if(FRONT_farLeftSensor == sensorOffLine &&  FRONT_centerSensor == sensorInLine && FRONT_rightSensor == sensorInLine && FRONT_farRightSensor == sensorInLine ){ //CURVA DIREITA
            analogWrite(velocityA, VELOCITY_MAX_MOTOR);
            analogWrite(velocityB, VELOCITY_MIN_MOTOR);
            DebugToSerial("CURVA DIREITA\n");
          } else  {
            //FOUDEU
            DebugToSerial("SandroTheBest\n");
          }

     /*if(directionControl == directionBack){

          motorA(SENTIDO_HORARIO);
          motorB(SENTIDO_HORARIO);


          //MOVIMENTACAO
          if(BACK_farLeftSensor == sensorOffLine && BACK_leftSensor == sensorOffLine &&  BACK_centerSensor == sensorInLine && BACK_rightSensor == sensorOffLine && BACK_farRightSensor == sensorOffLine ){ //RETO
            analogWrite(velocityB, VELOCITY_2_MOTOR);
            analogWrite(velocityA, VELOCITY_2_MOTOR);
            DebugToSerial("MDB\n");
          } else

          //CORRECAO DE ROTA
          if(BACK_farLeftSensor == sensorOffLine && BACK_leftSensor == sensorOffLine &&  BACK_centerSensor == sensorInLine && BACK_rightSensor == sensorInLine && BACK_farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA LEVE A ESQUERDA
            analogWrite(velocityA, VELOCITY_MIN_MOTOR);
            analogWrite(velocityB, VELOCITY_1_MOTOR);
            DebugToSerial("CORRECAO LEVE ESQUERDA\n");
          } else
          if(BACK_farLeftSensor == sensorOffLine && BACK_leftSensor == sensorInLine &&  BACK_centerSensor == sensorInLine && BACK_rightSensor == sensorOffLine && BACK_farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA LEVE A DIREITA
            analogWrite(velocityA, VELOCITY_1_MOTOR);
            analogWrite(velocityB, VELOCITY_MIN_MOTOR);
            DebugToSerial("CORRECAO LEVE DIREITA\n");
          } else
          if(BACK_farLeftSensor == sensorOffLine && BACK_leftSensor == sensorInLine &&  BACK_centerSensor == sensorOffLine && BACK_rightSensor == sensorOffLine && BACK_farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA ACENTUADA A DIREITA
            analogWrite(velocityA, VELOCITY_2_MOTOR);
            analogWrite(velocityB, VELOCITY_MIN_MOTOR);
            DebugToSerial("CORRECAO ACENTUADA DIREITA\n");
          } else
          if(BACK_farLeftSensor == sensorOffLine && BACK_leftSensor == sensorOffLine &&  BACK_centerSensor == sensorOffLine && BACK_rightSensor == sensorInLine && BACK_farRightSensor == sensorOffLine ){ //CORREÇO DE ROTA ACENTUADA A ESQUERDA
            analogWrite(velocityA, VELOCITY_MIN_MOTOR);
            analogWrite(velocityB , VELOCITY_2_MOTOR);
            DebugToSerial("CORRECAO ACENTUADA ESQUERDA\n");
          } else

          //CURVA
          if(BACK_farLeftSensor == sensorInLine && BACK_leftSensor == sensorInLine &&  BACK_centerSensor == sensorInLine && BACK_farRightSensor == sensorOffLine ){ //CURVA ESQUERDA
            analogWrite(velocityB, VELOCITY_MIN_MOTOR);
            analogWrite(velocityA, VELOCITY_MAX_MOTOR);
            DebugToSerial("CURVA ESQUERDA\n");
          } else
          if(BACK_farLeftSensor == sensorOffLine &&  BACK_centerSensor == sensorInLine && BACK_rightSensor == sensorInLine && BACK_farRightSensor == sensorInLine ){ //CURVA DIREITA
            analogWrite(velocityB, VELOCITY_MAX_MOTOR);
            analogWrite(velocityA, VELOCITY_MIN_MOTOR);
            DebugToSerial("CURVA DIREITA\n");
          } else  {
            //FOUDEU
            DebugToSerial("SandroTheBest\n");
          }
     }*/

  }   else  {
      DebugToSerial("SoundDetected\n");
      analogWrite(velocityA, VELOCITY_MIN_MOTOR);
      analogWrite(velocityB, VELOCITY_MIN_MOTOR);
      LedOn();
    }
    } else{
      DebugToSerial("ProximityDetected");
      analogWrite(velocityA, VELOCITY_MIN_MOTOR);
      analogWrite(velocityB, VELOCITY_MIN_MOTOR);
    }
}
