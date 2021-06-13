/*
 * DEBER 6.1
 * RETO 4
 * NOMBRE: Jorge Villarreal
*/

#define led 8
char letra = ' ';

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    letra = Serial.read();
    Serial.print(letra);
    if(letra == 'S'){
      digitalWrite(led, HIGH);
    }
    else if(letra == 'N'){
      digitalWrite(led, LOW);
    }
  }
}
