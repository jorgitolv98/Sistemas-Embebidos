/*
 * CAPITULO IV:PERIFERICOS ESPECIALES-INTERRUPCIONES
 * DEBER 4.2: Manejo de interrupciones
 * OBJETIVO: Se va activar un juego de leds por medio de la interrupcion 0 y la seleccion del numero de veces a jugar se realiza la interrrupcion 1.
 * NOMBRE: Jorge Villarreal
 * FUNCIONES: interrupt 0: inicio del sistema e ingreso de veces de juego
 *            inicio de juego
 *            fin de juego
 *            interrupt 1: contador
 *            attachInterrupt(interrupt,rutina,modo)
 */
const int leds[6]={13,12,11,10,9,8};
int on=0;   //int0
int cont;   //int1
int i=0;      //variable de conteo
int j=0;    //variable de conteo
void setup() {
Serial.begin(9600); //activacion de la comunicacion serial
    
 attachInterrupt(0,activacion,LOW);  //interupt 0 habilitada
 attachInterrupt(1,contador,LOW);    //interrupt 1 habilitada

for(i=0;i<6;i++){   //configuracion de leds
  pinMode(leds[i],OUTPUT);
  }
  i=0;
}

void loop() {
  if(on==2){
    for(;i<cont;i++){
      for(j=0;j<6;j++){
        digitalWrite(leds[j],HIGH);
        delay(200);
        digitalWrite(leds[j],LOW);
        delay(200);
        }
      }
    }
}
void activacion(){
  switch (on){    //opciones de los botones
    case 0:
    Serial.println("Inicio del Sistema");
    Serial.println("Ingrese el numero de veces a jugar");
    on++;
    break;
    
    case 1:
    Serial.println("Inicio de Juego");
    on++;
    break;
    
    case 2:
    Serial.println("Fin de juego");
    cont=0;
    i=0;
    j=0;
    on=0;
    break ;
    }
  }
  void contador(){
    if(on==1){
      cont++;
      Serial.println(String("Juega ")+String(cont)+String(" veces"));
    
      }
    }
