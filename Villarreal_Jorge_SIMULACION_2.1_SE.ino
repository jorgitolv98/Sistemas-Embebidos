/* 
CAPITULO II: PUERTOS DIGITALES
Código I: Manejo de puertos configurados como salidas
OBJETIVO: Encender y apagar leds mediante el uso de diferentes tipos de variables
NOMBRE: Jorge Villarreal
*/

/*variables: numéricas enteras(int), decimales(float), caracteres (chart)*/
#define led1 8           /* uso de #define, es una variable que no se pueda alterar su valor, no existe depuración de errores  */
int led2 = 9;            /*se puede considerar como una variable normal, no es muy recomendable  */
const int led3 = 10;     /*variable constante, es la recomendable*/
void setup() {
  pinMode(led1,OUTPUT);      /*Declaro el pin 8 como salida*/
    pinMode(led2,OUTPUT);    /*Declaro el pin 9 como salida*/
      pinMode(led3,OUTPUT);  /*Declaro el pin 10 como salida*/

}

void loop() {
  digitalWrite(led1,HIGH);        //Envía 5v al pin 8
  delay(500);                     //Se detiene el microcontrolador por medio segundo
    digitalWrite(led1,LOW);       //Envía 0v al pin 
     delay(500);                  //Se detiene el microcontrolador por medio segundo
    digitalWrite(led2,HIGH);      //Envía 5v al pin 9
    digitalWrite(led3,LOW);       //Envía 0v al pin 10
    delay(400);                   //Se detiene el microcontrolador por 400 ms
    digitalWrite(led3,HIGH);      //Envía 5v al pin 10
    digitalWrite(led2,LOW);       //Envía 0v al pin 9
    delay(400);                   //Se detiene el microcontrolador por 400 ms

}
