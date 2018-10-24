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
