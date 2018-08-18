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
byte PinosLinhas[LINHAS] = {12, 13, 14, 18};
//Definicao dos pinos das colunas
byte PinosColunas[COLUNAS] = {19, 21, 22,23};

//Inicializa o teclado
Keypad keypad = Keypad( makeKeymap(matriz_teclas), PinosLinhas,PinosColunas, LINHAS, COLUNAS);
