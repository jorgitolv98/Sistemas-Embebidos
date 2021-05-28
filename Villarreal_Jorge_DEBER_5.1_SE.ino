/*
   DEBER 5.1 Funciones Específicas - Memoria EEPROM
   OBJETIVO: Realizar la escritura de la memoria EEPROM a travez de un teclado matricial, el cual debe cumplir que se visualice en una 
   LCD cada caracter que se introduzca (uno por uno el que vayamos escribiendo en la memoria EEPROM), es decir, cada vez que se presione una tecla.
   NOMBRE: Jorge Villarreal
   */
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <EEPROM.h>

//Diseño del teclado matricial
const byte filas = 4;      //número de filas del teclado
const byte columnas = 4;    //número de columnas del teclado
char keys[filas][columnas] = { //define los valores del arreglo matricial
  {'1', '2', '3', ' '},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
//Pines dedicados para el Keypad
byte pinfilas[filas] = {13, 12, 11, 10}; //pines para las filas
byte pincolms[columnas] = {9, 8, 7, 6}; //pines para las columnas

//Creación de Keypad
Keypad teclado = Keypad(makeKeymap(keys), pinfilas, pincolms, filas, columnas); //Se detalla los pines y el numero dimensional del arreglo (4x4)
//Pines LCD.
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); //pines a emplear desde A0 hasta A5

char dat[15], op[1];
int i = 0;
int j = 0;
int m;
char sal;
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(16,0);
  lcd.print("DEBER 5.1");
for (m = 0; m < 8; m++) { //Ciclo for para recorrer el texto
          lcd.scrollDisplayLeft();    //direccion de dezplazamiento a la izquierda
          delay(200);
        }

  lcd.setCursor(16,1);
  lcd.print("INGRESE DATOS: ");
  for (m = 0; m < 8; m++) { //Ciclo for para recorrer el texto
          lcd.scrollDisplayLeft();    //direccion de dezplazamiento a la izquierda
          delay(200);
        }
        lcd.clear();
}

void loop() {
  //Verificacion de si una tecla fue presionada 
  char tcl=teclado.getKey();
  if(tcl){
    lcd.setCursor(0,0);
    lcd.print(String("Dato pulsado: ")+String(tcl));
    lcd.setCursor(0,1);
    lcd.print("INGRESO CORRECTO");
    dat[i]=tcl;
    i++;
    for(int z=0;z<15;z++){
    EEPROM.write(z,dat[z]);
    }
    if(i==15){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.println("ALMACENADO");
      i=0;
    }
    op[j]=tcl;
    if(op[0]==' '){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("DATOS GUARDADOS");
      lcd.setCursor(0,1);
      for(int w=0;w<15;w++){
      sal=EEPROM.read(w);
      lcd.print(sal);
      }
      delay(2500);
      i=0;
      j=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("INGRESE DATOS:");
    }
  }
}
