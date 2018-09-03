#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int ESP_Pin = 12;
bool started = false;
bool unlocked = false;
void cleanDisplay(){
  lcd.setCursor(0,0);
  lcd.print("                  ");
  lcd.setCursor(0,1);
  lcd.print("                  ");
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(ESP_Pin, INPUT);
    lcd.begin(16, 2);
}

void loop() {

    // put your main code\ here, to run repeatedly:
    if(!started){
    Serial.println(digitalRead(ESP_Pin));
    if(digitalRead(ESP_Pin) == 0){
      cleanDisplay();
      lcd.setCursor(0,0);
      lcd.print("Digite a senha");
      //Serial.println("Desbloqueie");
      lcd.setCursor(0,1);
      lcd.print("Para desbloquear");
      started = false;
    } else

    if(digitalRead(ESP_Pin) > 0){
      cleanDisplay();
      /*lcd.setCursor(0,0);
      lcd.print("                  ");
      lcd.setCursor(0,1);
      lcd.print("                  ");*/
      lcd.setCursor(0,0);
      lcd.print("Iniciando...");
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("Iniciando.. ");
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("Iniciando.  ");
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("Iniciando   ");
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("Iniciando.  ");
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("Iniciando.. ");
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("Iniciando...");
      //Serial.println("Iniciando");
      started = true;
    }
  } else{
      if(!unlocked){
        cleanDisplay();
        lcd.setCursor(0,0);
        lcd.print("Schlager");
        unlocked = true;
      }
  }
}
