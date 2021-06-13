/*
 * DEBER 6.1
 * RETO 4 
 * NOMBRE: Jorge Villarreal
 */

import processing.serial.*;
Serial porto;

void setup() {
  size(400, 400);
  porto = new Serial(this,"COM2",9600);

  background(#D0D8D7);
  fill(#FF0313);
  stroke(#FF0313);
  ellipse(200, 200, 100, 100);
  fill(#0A0A0A);
  textSize(20);
  textAlign(CENTER);
  text("PRESIONE EL BOTON \n PARA ENCENDER O APAGAR EL LED", 200, 70);
  fill(#FAFFFE);
  textSize(15);
  text("¡APAGADO!", 200, 200);
}

void draw() {
}

void mousePressed() {
  if (mouseButton == RIGHT) {
    background(#D0D8D7);
    fill(#18FA05);
    stroke(#18FA05);
    ellipse(200, 200, 100, 100);
    fill(#0A0A0A);
    textSize(20);
    textAlign(CENTER);
    text("PRESIONE EL BOTON \n PARA ENCENDER O APAGAR EL LED", 200, 70);
    fill(#FAFFFE);
    textSize(15);
    text("¡ENCENDIDO!", 200, 200);
    porto.write('S');
  }
  
  if(mouseButton == LEFT){
    background(#D0D8D7);
    fill(#FF0313);
    stroke(#FF0313);
    ellipse(200, 200, 100, 100);
    fill(#0A0A0A);
    textSize(20);
    textAlign(CENTER);
    text("PRESIONE EL BOTON \n PARA ENCENDER O APAGAR EL LED", 200, 70);
    fill(#FAFFFE);
    textSize(15);
    text("¡APAGADO!", 200, 200);
    porto.write('N');
  }
}
