/* 
CAPITULO III: MODULOS DE COMUNICACION I2C.
DEBER 3.1: Recepcion y envio de datos complejos por comunicacion I2C.
OBJETIVO:  Mediante comunicación I2C configurar 1 maestro y 3 esclavos. Cada esclavo tendrá conectados 3 leds en sus salidas digitales, los cuales deberán encenderse de forma síncrona   y ordenada. 
NOMBRE: Jorge Villarreal
*/
////////////////////////////////MASTER/////////////////////////////////
#include <Wire.h>   //Libreria I2C
char dato;    //variable de almacenamiento de datos
void setup() {
Wire.begin();   //inicia comunicacion I2C
Serial.begin(9600);   //inicia  comunicacion serial
}

void loop() {
if(Serial.available()>0){   //verifica que esxista datos
  dato=Serial.read();   //almacena el dato en la variable
  Wire.beginTransmission(4);  //empieza la comunicacion I2C
  Wire.write(dato);   //envio dato
  Wire.endTransmission();   //termina la comunicacion I2C
  }
}
