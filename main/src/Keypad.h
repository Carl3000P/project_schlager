#include "../lib/Keypad/src/Keypad.h"

const byte LINHAS = 4;
const byte COLUNAS = 4;

String pass_key = "";

//Matriz de caracteres
char matriz_teclas[LINHAS][COLUNAS] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//Definicao dos pinos das linhas
byte PinosLinhas[LINHAS] = {KEYPAD_PIN_LINE_1, KEYPAD_PIN_LINE_2,KEYPAD_PIN_LINE_3, KEYPAD_PIN_LINE_4};
//Definicao dos pinos das colunas
byte PinosColunas[COLUNAS] = {KEYPAD_PIN_COLUMN_1, KEYPAD_PIN_COLUMN_2, KEYPAD_PIN_COLUMN_3 ,KEYPAD_PIN_COLUMN_4};

//Inicializa o teclado
Keypad keypad = Keypad( makeKeymap(matriz_teclas), PinosLinhas,PinosColunas, LINHAS, COLUNAS);

void unlockProtocol(){
  char pressed_key = keypad.getKey();
  //Mostra no serial monitor o caracter da matriz,
  //referente a tecla que foi pressionada
  if (pressed_key){
    Serial.println(pass_key);
    if(pressed_key == '#'){
      pressed_key = 0;
      if(pass_key == "1234"){
        equipamentBlocked = false;
        digitalWrite(unoPin, HIGH);
        pressed_key = 0;
      }
    }
    pass_key.concat(String(pressed_key));
    //Serial.println("Tecla pressionada : ");
    //Serial.print(pressed_key);
}
}
