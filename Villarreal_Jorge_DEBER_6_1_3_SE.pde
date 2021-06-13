/*
DEBER 6.1
RETO 4
NOMBRE: Jorge Villarreal
*/
int x=0;
int y=0;
int i=0;

void setup(){
  size(900,600);  // (ancho, alto)   (displayWidth,displayHeight)  P3D: Tercera dimensión
  background(#D6D6D6);  // color de fondo RGB
} 

void draw(){
  if(i<1){
    //background(#D6D6D6);  // color de fondo RGB
    textSize(25);
    fill(250,0,0);

    stroke(0,255,0);
    fill(#E31700);
    ellipse(450,300,300,300);
    fill(1);
    text("EL PUSH BUTTON ESTÁ PRESIONADO",250,100);
  }
} 

void mousePressed() {
  if(mouseButton==LEFT){
    stroke(0,255,0);
    fill(#1C7601);
    ellipse(450,300,300,300);
    i=1;
  }
  if(mouseButton==RIGHT){
    stroke(0,255,0);
    fill(#864504);
    ellipse(450,300,300,300);
    i=1;
  }
}

void mouseReleased() {
  if(mouseButton==LEFT){
    i=0;
  }
  if(mouseButton==RIGHT){
    stroke(0,250,0);
    fill(#34E300);
    ellipse(450,300,300,300);
    fill(1);
    text("EL PUSH BUTTON NO ESTÁ PRESIONADO",250,100);
  } 
}
