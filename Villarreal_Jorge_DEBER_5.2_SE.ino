  /* UNIDAD V: FUNCIONES ESPECÍFICAS
   * DEBER 5.2 : MANEJO DE MODOS SLEEP
   * OBJETIVO: Realizar un control de modos sleep por medio de interrupciones por software y hardware (CORRECCIÓN DEL CÓDIGO 23)
   * NOMBRE: Jorge Villarreal
  */
  
  #include<avr/power.h>
  #include<avr/sleep.h>
  #include<avr/wdt.h>
  #include <MsTimer2.h>
  #include<EEPROM.h>
  
  int dato;
  int on=0;
  void(* resetFunc) (void) = 0; // esta es la funcion //void on(void);
  
  void setup() {
     dato=EEPROM.read(0); //lectura de la EEPROM
     Serial.begin(9600);  //inicio de comunicación serial
     Serial.println("SETUP"); //mensaje inicial
     if(dato==0){
        set_sleep_mode(SLEEP_MODE_STANDBY); //Selección de modo SLEEP
      sleep_enable(); //se activa el modo SLEEP
      EEPROM.write(0,1);    //escritura en la EEPROM, pos. 0
      wdt_enable(WDTO_8S);    //wdt en 8s
      }
      else{
      sleep_disable(); //se desactiva el modo SLEEP
       EEPROM.write(0,0); //En la EEPROM en la pos. 0 se escribe 0
        MsTimer2::set(10000,tiempo); // configura timer 2 a un segundo
         MsTimer2::start(); //inicio del tiemer
           wdt_enable(WDTO_8S); //WDT en 8s
      }
     attachInterrupt(0,encender,LOW);
  }
  void loop() {
  if(dato==0){
    Serial.println("DORMIDO");
    delay(20);
    sleep_mode(); //entra a dormir
  }
   else{
    Serial.println("DESPIERTO");  //muestra que el el sistema se encuentra depierto
    delay(1000);  //delay
    }
  }
  void tiempo(){
    Serial.println("DORMIDO");
    delay(20);
    sleep_mode(); //entra a dormir
   }
  
   void encender (){
      resetFunc();  // llamar la fun.
   }
