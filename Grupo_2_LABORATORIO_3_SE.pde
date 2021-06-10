/*
 * LABORATORIO 3
 * GRUPO 2
 * NOMBRES: Jorge Villarreal
 *          Marlon Ipiales
 * OBJETIVO: Realizar un juego relacionado a la consola ATARI
 * JUEGO DE LA SERPIENTE.
 */
 
import processing.serial.*;    //llamamos a la librería para comunicación con proteus
import ddf.minim.*;            //llamamos a la librería para la insersión de audio

Serial port;   //declaración de variable port (para el puerto)
Minim cargar;  //declaración de variable para cargar audio
AudioPlayer sound;  //declaración de variable donde se reproducirá el audio

PImage startImg;   //declaración de variable para la imagen de fondo del menú inicial
PImage serpImg;    //declaración de variable para la imagen de la serpiente
PImage fondoImg;   //declaración de variable para la imagen del fondo de juego ejecutado.
PImage manzanaImg; //declaración de variable para la imagen de la manzana

int filas=20, columnas=20, cuadrados=20; //definimos el número de filas, columnas y cuadrados.
int i=0, j=0; //moverse en filas y columnas
ArrayList<Integer> posX = new ArrayList<Integer>();
ArrayList<Integer> posY = new ArrayList<Integer>();

int dir = 0; //Especificamos una dirección en la que siempre incia la serpiente.(sube)
int[] dirX={0, 0, -1, 1}; //direccion de la serpiente izquierda derecha
int[] dirY={-1, 1, 0, 0}; //direccion de la serpiente arriba-abajo

int manzanaX, manzanaY;  //variables para la posición de manzana en eje x e y

boolean gameOver=true; //finalización de juego.
int score = 0, highScore = 0; //Indica el puntaje obtenido y el mejor puntaje desde la ejecución.
String dato;

void setup() {
  size(400, 400);  //ingresamos el tamaño de nuestra pantalla de juego
  port= new Serial(this, "COM3",9600);  //definimos el puerto COM 3 y la velocidad
  cargar=new Minim(this); //activamos el llamado de audio en la variable cargar
  sound=cargar.loadFile("lab03sonido.wav");  //cargamos el audio en la variable
  startImg=loadImage("lab03snake.PNG"); //sube imagen de fondo del menu
  serpImg =loadImage("lab03serp.png");  //sube imagen de la serpiente
  fondoImg =loadImage("lab03area.png"); //sube imagen del fondo del juego ejecutado
  manzanaImg =loadImage("lab03manz.png"); //sube imagen de la manzana
  
  posX.add(10);  //aparicion inicial aleatoria en el eje x de la serpiente en el juego
  posY.add(10);  //aparicion inicial aleatoria en el eje y de la serpiente en el juego
  frameRate(10);  //velocidad de movimiento de la serpiente
  manzanaX=(int)random(0, 20);  //aparición aleatoria de manzana en el eje x
  manzanaY=(int)random(0, 20);  //aparición aleatoria de manzana en el eje y
}

void draw() {
  
  if (gameOver==true) { 
    
    sound.play(); //se ejecuta el sonido cargado
    imageMode(CENTER);  //centramos el modo de imagen
    image(startImg, width/2,height/2,400,400);  //ajustamos la imagen del menú
    
    fill(255,random(255),0);  //definimos color aleatorio para el texto de STAR. #65EA4C  
    textSize(40);  //especificamos el tamaño 
    text("Presione START \n    para jugar",50,80);  //definimos la posición
    fill(1); //Seleccionamos el color negro
    textSize(50);//especificamos el tamaño
    text("Puntaje: "+score, 65, 250); //indica el puntaje logrado y posicionamos
    textSize(40); //especificamos el tamaño
    text("Mejor Puntaje: "+highScore, 30, 350);  //indica el mejor puntaje y posicionamos
    manzanaX=-1; manzanaY=-1;
    posX.clear(); posY.clear(); //se limpia la pos. de la serpiente en x e y
    posX.add(-10); posY.add(-10);  
  } else {
    text(""+score, width/2-15, 100); // Mostramos la puntuación
    imageMode(CORNER);  //se inicia la imagen desde la esquina superior izquierda
    image(fondoImg, 0, 0,400,400);  //se incerta la imagen de fondo y se escala
    stroke(#159324);  // se especifica el color de los bordes
    for (i=0; i<filas; i++) {  
      line(0, i*cuadrados, width, i*cuadrados);   //dibuja las líneas de filas al tamaño establecido, para realizar cuadrícula
    }
    for (j=0; j<columnas; j++) {
      line(j*cuadrados, 0, j*cuadrados, height);  //dibuja las líneas de columnas al tamaño establecido, para realizar cuadrícula
    }
    text(""+score, width/2-15, 50); // Mostramos la puntuación
  }
  movimientoSnake(); //llamar al método de mov. de la serpiente
  comer();         //llamar al método para comer la manzana
  bordes();        //llamar al método para la detección de bordes
  funcionJuego();  //lamar al método para muerte de la serpiente
  dibManzana();    //llamar al método para diseñar la manzana
  snake();         //llamar método para diseñar la serpiente
  
  while (port.available() > 0) {  //comunicación COM
   dato=port.readString();  //se lee los datos del puerto
 switch(dato){ //realizamos el control de selección
   case "A":  //En el caso de presionar A
    dir=2;    //declaramos que la variable sea igual a 2
    println(str(dir));  //permitirá mover la serpiente a la izquierda
   break;
   case "D":  //En el caso de presionar D
    dir=3;    //declaramos que la variable sea igual a 3
    println(str(dir));  //permitirá mover la serpiente a la derecha
   break;
   case "W":  //En el caso de presionar W
    dir=0;    //declaramos que la variable sea igual a 4
    println(str(dir));  //permitirá mover la serpiente para arriba
   break;
   case "S":  //En el caso de presionar S
    dir=1;    //declaramos que la variable sea igual a 1
    println(str(dir));  //permitirá mover la serpiente para abajo
   break;
   case "Y":  //En el caso de presionar Y
    restart();  //inicia el juego
    sound.pause(); //se pone pausa al audio al comenzar el juego
   break;
   
 }
 }
}


void dibManzana() {  //método para diseñar la manzana
  imageMode(CORNER);  //se inicia la imagen desde la esquina superior izquierda
  image(manzanaImg, manzanaX*cuadrados, manzanaY*cuadrados, cuadrados, cuadrados);  //configuramos la imagen para que se ajuste al cuadrado
}


void snake() {  //método para diseñar la serpiente
  for (int k=0; k<posX.size(); k++) {  //dibuja la serpiente y aumenta el tamaño de uno en uno.
    imageMode(CORNER);  //se inicia la imagen desde la esquina superior izquierda
    image(serpImg, posX.get(k)*cuadrados, posY.get(k)*cuadrados, cuadrados, cuadrados);  //configuramos la imagen para que se ajuste al cuadrado en el que se encuentre al moverse
  }
}


void movimientoSnake() {  //método de mov. de la serpiente
  posX.add(0, posX.get(0)+dirX[dir]);    //mov. en el eje horizontal
  posY.add(0, posY.get(0)+dirY[dir]);    //mov. en el eje vertical
  
  posX.remove(posX.size()-1);  //elimina cuadros que el dibujo original no tiene en x
  posY.remove(posY.size()-1);  ////elimina cuadros que el dibujo original no tiene en y
}


void comer(){    //método para comer la manzana
  if((posX.get(0)==manzanaX)&&(posY.get(0)==manzanaY)){//cuando la serpiente se encuentra en la posición de la manzana
  
    manzanaX=(int)random(0, 20);  //la manzana aparece aleatroiamente en x
    manzanaY=(int)random(0, 20);  //la manzana aparece aleatroiamente en y
    posX.add(posX.get(posX.size()-1));//se añade un cuadro de serpiente en la posición en x, tomando el tamaño original
    posY.add(posY.get(posY.size()-1));//se añade un cuadro de serpiente en la posicion en y, tomando el tamaño original
    score++;  // el puntaje aumenta de uno en uno al comer una manzana
    highScore=max(score,highScore);  //se guarda el mejor puntaje que se dispone
    
  }
}


void bordes(){    //método para la detección de bordes
  if((posX.get(0)<0) || (posX.get(0)>columnas-1) || (posY.get(0)<0) || (posY.get(0)>filas-1)){  //se limita los bordes en el eje x y eje y.
    gameOver=true;
  }
}


void funcionJuego(){  //muerte de la serpiente
  for(int l=2;l<posX.size();l++){  //para la serpiente cuando es más grande que uno en x
    for(int m=2;m<posY.size();m++){  //para la serpiente cuando es más grande que uno en y
      if((posX.get(0)==posX.get(l)) && (posY.get(0)==posY.get(l))){  //Si se repite la pos. finaliza el juego
        gameOver=true;
      }
    }
  }
}


void restart(){    //método para reiniciar el juego.
  gameOver=false;  //Si el juego corre nuevamente
  posX.clear();    //Se limpia la pos x de la serpiente
  posY.clear();    //Se limpia la pos y de la serpiente
  posX.add(10);    //Se ubica la serpiente en el cuadro 10 del eje x
  posY.add(10);    //Se ubica la serpiente en el cuadro 10 del eje y
  manzanaX=(int)random(0, 20);  //Se ubica de forma aleatoria la manzana en el eje x
  manzanaY=(int)random(0, 20);  //Se ubica de forma aleatoria la manzana en el eje y
  i=0;  //moverse en filas
  j=0;  //moverse en columnas
  score=0;  //El puntaje actual se reinicia a 0.
}

void keyPressed(){    //método para moverse con Teclado
  if(key=='u' || keyCode==UP){  //si se preciona una de las dos teclas, se realizará un mov. de subida.
    dir=0;                      //definimos la dirección
  }
    if(key=='j' || keyCode==DOWN){  //si se preciona una de las dos teclas, se realizará un mov. de bajada.
    dir=1;                          //definimos la dirección
  }
    if(key=='h' || keyCode==LEFT){  //si se preciona una de las dos teclas, se realizará un mov. para la izquierda.
    dir=2;                          //definimos la dirección
  }
    if(key=='k' || keyCode==RIGHT){  //si se preciona una de las dos teclas, se realizará un mov. para la derecha.
    dir=3;                           //definimos la dirección
  }
  if(key=='i'){  //si se preciona la tecla, se realizará la ejecución del juego.
    restart();   //llamamos al método de incio de juego
    sound.pause();  //se pone pausa al audio al comenzar el juego
  }
}
