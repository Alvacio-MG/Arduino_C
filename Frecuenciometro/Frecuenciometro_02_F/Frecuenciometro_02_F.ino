
const int pinPWM = 14; // Cambia el número del pin según tu conexión

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long pulseHigh = pulseIn(pinPWM, HIGH); // Tiempo en alto
  unsigned long pulseLow = pulseIn(pinPWM, LOW);   // Tiempo en bajo

  unsigned long period = pulseHigh + pulseLow;      // Período completo
  float frequency = 1.0 / (period * 1e-6);          // Convierte el período a frecuencia en microsegundos

  Serial.print("Frecuencia: ");
  Serial.print(frequency);
  Serial.println(" Hz");

  delay(1000); // Espera 1 segundo antes de realizar la próxima medición
}