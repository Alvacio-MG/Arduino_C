const int pinEntrada = 13;
int estadoAnterior = LOW;
unsigned long tiempoInicio = 0;

void setup() {
  pinMode(pinEntrada, INPUT);
  Serial.begin(9600);
}

void loop() {
  int estadoActual = digitalRead(pinEntrada);

  if (estadoActual != estadoAnterior) {
    if (estadoActual == HIGH) {
      tiempoInicio = micros();
    } else {
      unsigned long tiempoDuracion = micros() - tiempoInicio;
      Serial.print("Duración en HIGH: ");
      Serial.println(tiempoDuracion);
    }
  }

  estadoAnterior = estadoActual;
}