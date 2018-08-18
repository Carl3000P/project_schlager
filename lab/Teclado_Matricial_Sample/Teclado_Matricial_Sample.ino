//Original code: https://www.arduinoecia.com.br/2015/05/teclado-matricial-membrana-4x3-arduino.html

//Programa : Teclado matricial 4x3 Arduino
//Autor : Arduino e Cia

void setup(){
  //Pinos ligados aos pinos 4, 5, 6 e 7 do teclado - Linhas
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(18, OUTPUT);
   
  //Pinos ligados aos pinos 8, 9, e 10 do teclado - Colunas
  pinMode(19, INPUT);
  //Ativacao resistor pull-up
  digitalWrite(19, HIGH);
  pinMode(21, INPUT);
  digitalWrite(21, HIGH);
  pinMode(22, INPUT);
  digitalWrite(22, HIGH);
  pinMode(22, INPUT);
  digitalWrite(22, HIGH);
   
  Serial.begin(9600);
  Serial.println("Teclado 4x3 - Exemplo 1");
  Serial.println("Aguardando acionamento das teclas...");
  Serial.println();
}
 
void loop()
{
    for (int porta = 4; porta<8; porta++)
    {
      //Alterna o estado dos pinos das linhas
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(porta, LOW);
      //Verifica se alguma tecla da coluna 1 foi pressionada
      if (digitalRead(8) == LOW)
      {
        imprime_linha_coluna(porta-3, 1);
        while(digitalRead(8) == LOW){}
      }
  
      //Verifica se alguma tecla da coluna 2 foi pressionada    
      if (digitalRead(9) == LOW)
      {
        imprime_linha_coluna(porta-3, 2);
        while(digitalRead(9) == LOW){};
      }
     
      //Verifica se alguma tecla da coluna 3 foi pressionada
      if (digitalRead(10) == LOW)
      {
        imprime_linha_coluna(porta-3, 3);
        while(digitalRead(10) == LOW){}
      }
    }
   delay(10);
 }
 
void imprime_linha_coluna(int x, int y)
{
  //Mostra informacoes no serial monitor
  Serial.print("Linha : ");
  Serial.print(x);
  Serial.print(" x Coluna : ");
  Serial.print(y);
  delay(10);
  Serial.println();
}

