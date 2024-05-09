const int inputPin = 14;
const int outputPin = 27;
bool buttonPressed = false;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(inputPin), handleInterrupt, CHANGE);
}

void handleInterrupt() {
  if (digitalRead(inputPin) == HIGH) {
    buttonPressed = true;
  } else {
    buttonPressed = false;
    digitalWrite(outputPin, HIGH);    // Establecer el pin de salida en HIGH
    delayMicroseconds(29*22);          // Mantener el estado HIGH durante 29.8 microsegundos
    digitalWrite(outputPin, LOW);     // Establecer el pin de salida en LOW
  }
}

void loop() {
  // El código en loop() se ejecutará repetidamente después de manejar la interrupción
  if (buttonPressed) {
    // Realiza alguna acción adicional mientras se mantiene el botón presionado
  }
}