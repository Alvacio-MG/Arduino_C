#include <avr/io.h>

const int pinA = 8; // Pin conectado a la fase A del motor paso a paso
const int pinB = 9; // Pin conectado a la fase B del motor paso a paso
const int pinC = 10; // Pin conectado a la fase C del motor paso a paso
const int pinD = 11; // Pin conectado a la fase D del motor paso a paso

const int estados[4][4] = {
  {1, 0, 0, 1}, // Estado 1: A encendido, B apagado, C apagado, D encendido
  {0, 1, 0, 1}, // Estado 2: A apagado, B encendido, C apagado, D encendido
  {0, 0, 1, 1}, // Estado 3: A apagado, B apagado, C encendido, D encendido
  {1, 1, 0, 0}  // Estado 4: A encendido, B encendido, C apagado, D apagado
};

int estadoActual = 0; // Índice del estado actual en el array

void setup() {
  // Definir los pines como salidas
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Establecer los estados de las salidas según el estado actual
  digitalWrite(pinA, estados[estadoActual][0]);
  digitalWrite(pinB, estados[estadoActual][1]);
  digitalWrite(pinC, estados[estadoActual][2]);
  digitalWrite(pinD, estados[estadoActual][3]);
  Serial.print("estado A:");
  Serial.println(estados[estadoActual][0]);

  // Avanzar al siguiente estado
  estadoActual = estadoActual + 1;
  if (estadoActual >= 4 ){
    estadoActual = 0;
  }
  // Esperar un tiempo entre pasos
   // Ajustar el tiempo según la velocidad deseada del motor
}
