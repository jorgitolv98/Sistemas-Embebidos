/* 
CAPITULO IV: PERIFERICOS ESPECIALES.
DEBER 4.1: CAD Y PWM.
OBJETIVO:  Realizar un sistema en el cual se conecten 2 motores (parecido al diagrama que se utilizo en clase). Los datos de CAD, V y PWM se deben visulizar en una LCD para cada motor.   A travez de la activación de un botón y un switch (el funcionamiento de un motor dependerá de la activación de un botón y el otro dependerá de la activación de un switch, a su elección) entrará en funcionamiento el motor que corresponda y se visualizará en la LCD de ese motor los datos de CAD, Voltaje y PWM. 
NOMBRE: Jorge Villarreal
*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,5,4,3,2);
LiquidCrystal lcd1(A3,A4,9,8,7,6);

int conversor;
float voltaje;
int dutty;

int conversor1;
float voltaje1;
int dutty1;

void setup() {
  lcd.begin(16,2);
  lcd1.begin(16,2);
}

void loop() {
  conversor=analogRead(A1);
  voltaje=(conversor*5.0)/1023;
  dutty=conversor/4;
  analogWrite(11,dutty);
  lcd.setCursor(0,0);
  lcd.print("CAD:");
  lcd.setCursor(5,0);
  lcd.print(conversor);
  lcd.setCursor(0,1);
  lcd.print("V:");
  lcd.setCursor(3,1);
  lcd.print(voltaje);
  lcd.setCursor(9,1);
  lcd.print("PWM:");
  lcd.setCursor(13,1);
  lcd.print((dutty*100)/255);
  delay(300);


  conversor1=analogRead(A0);
  voltaje1=(conversor1*5.0)/1023;
  dutty1=conversor1/4;
  analogWrite(10,dutty1);
  lcd1.setCursor(0,0);
  lcd1.print("CAD:");
  lcd1.setCursor(5,0);
  lcd1.print(conversor1);
  lcd1.setCursor(0,1);
  lcd1.print("V:");
  lcd1.setCursor(3,1);
  lcd1.print(voltaje1);
  lcd1.setCursor(9,1);
  lcd1.print("PWM:");
  lcd1.setCursor(13,1);
  lcd1.print((dutty1*100)/255);
  delay(300);

}
