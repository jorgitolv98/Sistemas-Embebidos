/* 
CAPITULO II: PUERTOS DIGITALES COMO SALIDA
DEBER 2.1 Código II: Manejo de puertos configurados como salidas.
OBJETIVO: Realizar el código necesario para encender 4 leds de forma síncrona, es decir, encender uno por uno. Cada vez que se encienda un led los demás deben estar apagados.
NOMBRE: Jorge Villarreal
*/

/*variables: numéricas enteras(int), decimales(float), caracteres (chart)*/
#define led1 8           /* uso de #define, es una variable que no se pueda alterar su valor, no existe depuración de errores  */
int led2 = 9;            /*se puede considerar como una variable normal, no es muy recomendable  */
const int led3 = 10;     /*variable constante, es la recomendable*/
const int led4 = 11;     /*variable constante, es la recomendable*/
void setup() {
  pinMode(led1,OUTPUT);      /*Declaro el pin 8 como salida*/
    pinMode(led2,OUTPUT);    /*Declaro el pin 9 como salida*/
      pinMode(led3,OUTPUT);  /*Declaro el pin 10 como salida*/
       pinMode(led4,OUTPUT);  /*Declaro el pin 11 como salida*/

}

void loop() {
digitalWrite(led1,HIGH);        //Envía 5v al pin 8
      delay(200);               //Se detiene el microcontrolador por 200 ms
      digitalWrite(led1,LOW);   //Envía 0v al pin 8
      delay(200);               //Se detiene el microcontrolador por 200 ms
      digitalWrite(led2,HIGH);  //Envía 5v al pin 9
      delay(200);               //Se detiene el microcontrolador por 200 ms
      digitalWrite(led2,LOW);   //Envía 0v al pin 9
      delay(200);               //Se detiene el microcontrolador por 200 ms
      digitalWrite(led3,HIGH);  //Envía 5v al pin 10
      delay(200);               //Se detiene el microcontrolador por 200 ms
      digitalWrite(led3,LOW);   //Envía 0v al pin 10
      delay(200);               //Se detiene el microcontrolador por 200 ms
      digitalWrite(led4,HIGH);  //Envía 5v al pin 11
      delay(200);               //Se detiene el microcontrolador por 200 ms
      digitalWrite(led4,LOW);   //Envía 0v al pin 11
      delay(200);               //Se detiene el microcontrolador por 200 ms

}
