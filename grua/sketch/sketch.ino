#include <Servo.h>

Servo Horiz;
Servo Vert;
//Establece variables para los pines del joystick
byte jHoriz = 13;
byte jVert = 14;
//Las variables uqe guardan los ángulos de los servos 
byte hor = 90;
byte ver = 90;

void setup() {
  //Establece los pines del servo 
  Vert.attach(18);
  Horiz.attach(19);
}

void loop() {
  //Lectura del joystick horizontal
  if (analogRead(jHoriz) < 200 && hor < 180) {
    hor++;
  }
  else  if (analogRead(jHoriz) > 700 && hor > 0) {
    hor--;
  }

  //Lectura del joystick vertical
  if (analogRead(jVert) < 200 && ver < 180) {
    ver++;
  }
  else if (analogRead(jVert) > 700 && ver > 0) {
    ver--;
  }

  //Actualización de la pocición de los servos
   Horiz.write(hor);
   Vert.write(ver);

   //delay para mejor manejo
  delay(10); 
}