const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

const int velocityA = 6;
const int velocityB = 9;

int SENTIDO_HORARIO = 0;
int SENTIDO_ANTIHORARIO = 1;
int PONTO_MORTO = 2;
int FREIO = 3;

int VELOCITY_MIN_MOTOR = 0;
int VELOCITY_1_MOTOR = 0;
int VELOCITY_2_MOTOR = 100;
int VELOCITY_MAX_MOTOR = 155;

void setupMotor(){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void motorA(int commandToMotorA){

    if(commandToMotorA == SENTIDO_HORARIO){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    } else{
    if(commandToMotorA == SENTIDO_ANTIHORARIO){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    } else{
    if(commandToMotorA == FREIO){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
    } else {
    if(commandToMotorA == PONTO_MORTO){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }
      }
    }
  }
}

void motorB(int commandToMotorB){

    if(commandToMotorB == SENTIDO_HORARIO){
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    } else{
    if(commandToMotorB == SENTIDO_ANTIHORARIO){
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    } else{
    if(commandToMotorB == FREIO){
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
    } else {
    if(commandToMotorB == PONTO_MORTO){
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
      }
    }
  }
}
