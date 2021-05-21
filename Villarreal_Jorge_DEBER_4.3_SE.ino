/*
 * CAPITULO IV: PERIFERICOS ESPECIALES
 * DEBER 4.3: USO DE TIMER 2
 * OBJETIVO: Reloj con Timer 2
 * NOMBRE: Jorge Villarreal
 * FUNCIONES: MsTimer2::set(1000,flash);  //1s periodo
 *            MsTimer2::start();
 *            MsTimer::stop();
 */
#include <MsTimer2.h>     //libreria Timer 2
#include <LiquidCrystal.h>  //libreria LCD

LiquidCrystal lcd(13,12,11,10,9,8);  //objeto para la libreria LCD
int segundos=0;  //variable de segundos
int minutos=0;  //variable de minutos
int horas=0;    //variable de horas

void setup() {
lcd.begin(20,4);  //inicia la LCD
MsTimer2::set(1000, reloj); //configura el timer 2 a 1 segundo
MsTimer2::start();


}

void loop() {

}
void reloj(){
  if(segundos<59){  //condicion de segundos
    segundos++; //incrementar variable
    }
    else {
      segundos=0;
      if(minutos<59){ //condicion de minutos
        minutos++;    //incrementar variable
        }
        else{
          minutos=0;
          if(horas<23){ //condicion de horas
            horas++;      //incrementar la variable
            }
            else{
              horas=0;  
              }
          }
      }
  lcd.clear();  //borrar el anterior mensaje
  
  lcd.setCursor(6, 3);
  if (horas < 10) {
    lcd.print("0");
  }
  lcd.print(horas);
  lcd.print(":");
  lcd.setCursor(9, 3);
  if (minutos < 10) {
    lcd.print("0");
  }
  lcd.print(minutos);
  lcd.print(":");
  lcd.setCursor(12, 3);
    if (segundos < 10) {
    lcd.print("0");
  }
  lcd.print(segundos);
  lcd.setCursor(15, 3);
      
  lcd.setCursor(5,0); //ubicacion de LCD
  lcd.print(String("BIENVENIDO")); //mensaje de impresion
  lcd.setCursor(2,1); //ubicacion de LCD
  lcd.print(String("JORGE VILLARREAL")); //mensaje de impresion
  lcd.setCursor(0,2); //ubicacion de LCD
  lcd.print(String(" Hora:minuto:segundo"));
  }
