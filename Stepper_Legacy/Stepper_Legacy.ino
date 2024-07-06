//#include <avr/io.h>


const byte pinA = 4; // Pin conectado a la fase A del motor paso a paso
const byte pinB = 5; // Pin conectado a la fase B del motor paso a paso
const byte pinC = 6; // Pin conectado a la fase C del motor paso a paso
const byte pinD = 7; // Pin conectado a la fase D del motor paso a paso
const int pinPot = A0; //Pin conectado al potenciometro para regular la velocidad de cambio de estado
int potStat = 0;
const int estados[4][4] = {
  {1, 0, 1, 0}, // Definición del Estado 1
  {1, 0, 0, 1}, // Definición del Estado 2
  {0, 1, 0, 1}, // Definición del Estado 3
  {0, 1, 1, 0}  // Definición del Estado 4
};


int estadoActual = 0; // Índice del estado actual en el array
//unsigned long tiempoAnterior = 0; // Tiempo en milisegundos desde el último paso


const int tiempoPaso = 25; // Tiempo de espera entre pasos en milisegundos


void setup() {
  // Definir los pines como salidas
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinPot, INPUT);


  Serial.begin(9600);
}


void loop() {
  // Establecer los estados de las salidas según el estado actual
  digitalWrite(pinA, estados[estadoActual][0]);//Establecer el estado de la fase A al que corresponde en la serie de pasos.
  digitalWrite(pinB, estados[estadoActual][1]);//Establecer el estado de la fase B al que corresponde en la serie de pasos.
  digitalWrite(pinC, estados[estadoActual][2]);//Establecer el estado de la fase C al que corresponde en la serie de pasos.
  digitalWrite(pinD, estados[estadoActual][3]);//Establecer el estado de la fase D al que corresponde en la serie de pasos.
  Serial.println(estados[estadoActual][0]); //debug
  estadoActual = (estadoActual + 1); //Aumentar el estado actual para que coincida con el estado que deberían tener los motores
  potStat = analogRead(pinPot);
  if(estadoActual >= 4){ // Reestablecer el valor del estado actual a 0, al terminar los cuatro ciclos
    estadoActual = 0;
  }
  potStat = map(potStat, 0, 1023, 1, 480); //Limitar posibles valores del porenciometro
  delay(tiempoPaso); //Establecer un tiempo entre el camabio de ciclos
  // Avanzar al siguiente estado
}
