int ky038AValue = 0;
int ky038DValue = 0;

int MAX_KY_VALUE = 60;
bool equipamentBlocked = true;
bool soundDetected = false;

//SENSOR CONTROL VARIALES
bool FRONT_farLeftSensor, FRONT_leftSensor, FRONT_centerSensor,FRONT_rightSensor, FRONT_farRightSensor;
bool BACK_farLeftSensor, BACK_leftSensor, BACK_centerSensor,BACK_rightSensor, BACK_farRightSensor;

bool sensorInLine = true;
bool sensorOffLine = false;

//ULTRASONIC CONTROL VARIABLES
bool stopProximity1 = false;
bool stopProximity2 = false;
bool stopProximity = false;
float cmMsec1;
long microsec1;
float cmMsec2;
long microsec2;

//MOTOR CONTROL VARIABLES
int SENTIDO_HORARIO = 0;
int SENTIDO_ANTIHORARIO = 1;
int PONTO_MORTO = 2;
int FREIO = 3;

int VELOCITY_MIN_MOTOR = 0;
int VELOCITY_1_MOTOR = 0;
int VELOCITY_2_MOTOR = 100;
int VELOCITY_MAX_MOTOR = 155;
