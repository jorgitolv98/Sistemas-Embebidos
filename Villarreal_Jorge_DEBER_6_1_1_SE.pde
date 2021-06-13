/*
DEBER 6.1
RETO 1
NOMBRE: Jorge Villarreal
*/

void setup(){
  size(500,500);  // (ancho, alto)   (displayWidth,displayHeight)  P3D: Tercera dimensión
  background(#E38100);  // color de fondo RGB
} 

void draw(){
  stroke(0,0,255);
  strokeWeight(3);
  line(0,0,500,500);   // punto de inicio, punto de fin
  stroke(0,0,255);
  strokeWeight(3);
  line(0,500,500,0);   // punto de inicio, punto de fin
  
  stroke(0);
  strokeWeight(10);
  noFill();
  rect(0,0,500,500);   // vertice superior izquierdo, ancho y altura
  
  fill(255);   
  noStroke();
  ellipse(250,250,400,400);
  
  fill(#FF0303);  
  strokeWeight(3);
  stroke(0,250,0);
  ellipse(250,250,300,300);
} 
