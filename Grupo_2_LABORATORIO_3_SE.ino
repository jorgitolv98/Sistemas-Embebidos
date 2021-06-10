/*
 * LABORATORIO 3
 * GRUPO 2
 * NOMBRES: Jorge Villarreal
 *          Marlon Ipiales
 * OBJETIVO: Realizar un juego relacionado a la consola ATARI
 * JUEGO DE LA SERPIENTE.
 */
void setup() {
  Serial.begin(9600);   //inicializamos la comunicacion serial
  pinMode(8,INPUT);     //definimos el pin 8 como entrada
  pinMode(7,INPUT);     //definimos el pin 7 como entrada
  pinMode(6,INPUT);     //definimos el pin 6 como entrada
  pinMode(5,INPUT);     //definimos el pin 5 como entrada
  pinMode(4,INPUT);     //definimos el pin 4 como entrada
}

void loop() {
 if(digitalRead(8)==LOW){   //definimos que el pin 8 se active en bajo
    delay(250);             //delay
    Serial.print("Y");      //boton que hace referencia al "start"
  }
  if(digitalRead(7)==LOW){  //definimos que el pin 7 se active en bajo
    delay(250);             //delay
    Serial.print("W");      //boton que hace referencia a "SUBIR"
  }
  if(digitalRead(6)==LOW){  //definimos que el pin 6 se active en bajo
    delay(250);             //delay
    Serial.print("S");      //boton que hace referencia a "BAJAR"
  }
  if(digitalRead(5)==LOW){  //definimos que el pin 5 se active en bajo
    delay(250);             //delay
    Serial.print("A");      //boton que hace referencia a "IZQUIERDA"
  }
  if(digitalRead(4)==LOW){  //definimos que el pin 4 se active en bajo
    delay(250);             //delay
    Serial.print("D");      //boton que hace referencia a "DERECHA"
  }
}
