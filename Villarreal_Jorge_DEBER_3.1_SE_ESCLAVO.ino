/* 
CAPITULO III: MODULOS DE COMUNICACION I2C.
DEBER 3.1: Recepcion y envio de datos complejos por comunicacion I2C.
OBJETIVO:  Mediante comunicación I2C configurar 1 maestro y 3 esclavos. Cada esclavo tendrá conectados 3 leds en sus salidas digitales, los cuales deberán encenderse de forma síncrona   y ordenada. 
NOMBRE: Jorge Villarreal
*/
 ////////////////////////ESCLAVO////////////////////////
#include <Wire.h>   //Libreria I2C
char dato;    //variable de almacenamiento de dato
const int led1=8;   //led1 pin 8
const int led2=9;   //led2 pin 9
const int led3=10;  //led3 pin 10
void setup() {
  Wire.begin(4);    //id esclavo
  Wire.onReceive(receiveEvent); //llamando al metodo de recepcion
  Serial.begin(9600);
  pinMode(led1,OUTPUT); //pin 8 como salida
  pinMode(led2,OUTPUT); //pin 9 como salida
  pinMode(led3,OUTPUT); //pin 10 como salida
}

void loop() {

}
void receiveEvent(int bytes){
  while(Wire.available()){
    dato=Wire.read();
    switch(dato){
      case 'A':
    digitalWrite(led1,HIGH);
    delay(2500); 
    digitalWrite(led2,LOW); 
    digitalWrite(led3,LOW); 
    delay(15000);
    digitalWrite(led2,HIGH); 
    delay(2500);
    digitalWrite(led1,LOW); 
    digitalWrite(led3,LOW);  
    delay(15000);
    digitalWrite(led3,HIGH); 
    delay(2500);
    digitalWrite(led1,LOW); 
    digitalWrite(led2,LOW);   
    delay(15000);
    digitalWrite(led1,LOW); 
    digitalWrite(led2,LOW); 
    digitalWrite(led3,LOW); 
      break;

      default:
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      break;
      }
    }
  }
