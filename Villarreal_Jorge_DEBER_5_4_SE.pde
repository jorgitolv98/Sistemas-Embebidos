/*
*DEBER 5.4: Funciones y tareas de RTOS.
OBJETIVO: Realizar el funcionamiento de un semáforo basados en las funciones y tareas de RTOS.
*NOMBRE: Jorge Villarreal
*/

int tiempo;  //variable de tiempo
PImage startImg;  //Variable para la imagen

void setup() {
  startImg=loadImage("semaforix.jpg");  //cargamos la imagen
  size(400, 400);  //especificamos el tamaño de ventana
}
void draw() {
 
  int retardo = millis()-tiempo;  //retardo de cambio de color
  if (retardo < 2000) {  //si es menor a 2s
   imageMode(CENTER);
    image(startImg, width/2,height/2,400,400); //llamamos y escalonamos nuestra imagen
    fill(255,random(255),0);//#65EA4C  //color al texto
    textSize(20);  //tamaño de texto
    text("     Semáforo\n        PARE",125,20);  //texto
    fill(255, 0, 0); ellipse(200, 120, 75, 75);  //color rojo y ubicación-dimensión.
    fill(0, 0, 0); ellipse(200, 200, 75, 75);  //color amarillo y ubicación-dimensión.
    fill(0, 0, 0); ellipse(200, 280, 75, 75);  //color verde y ubicación-dimensión.
  } else if (retardo<2500) {
    imageMode(CENTER);
    image(startImg, width/2,height/2,400,400);
    fill(255,random(255),0);//#65EA4C
    textSize(20);
    text("     Semáforo\n       ESPERE",125,20);
    fill(0, 0, 0); ellipse(200, 120, 75, 75);
    fill(255, 255, 0); ellipse(200, 200, 75, 75);
    fill(0, 0, 0); ellipse(200, 280, 75, 75);
  } else if (retardo<5500) {
    imageMode(CENTER);
    image(startImg, width/2,height/2,400,400);
    fill(255,random(255),0);//#65EA4C
    textSize(20);
    text("     Semáforo\n        SIGA",125,20);
    fill(0, 0, 0); ellipse(200, 120, 75, 75);
    fill(0, 0, 0); ellipse(200, 200, 75, 75);
    fill(0, 255, 0); ellipse(200, 280, 75, 75);
  } else
  {
    tiempo = millis(); // tiempo en milisegundos.

  }
}
