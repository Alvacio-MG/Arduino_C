// Pines de los leds
const byte ledPin = 3;

const int ledPins[] = {13, 12, 14, 27};
const byte numLeds = sizeof(ledPins) / 2;

const byte rgbPins[] = {26, 25, 33}; 
const byte RGB = 3;

// Pines del 7 segmentos
const int segmentA = 13;
const int segmentB = 12;
const int segmentC = 14;
const int segmentD = 27;
const int segmentE = 26;
const int segmentF = 25;
const int segmentG = 33;

// Números del 7 segmentos
int numeros[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 0, 0, 1, 1}   // 9
};

// Control de números del 7 segmentos
int numeroActual = 1;  

// Pin del botón
const int buttonPin = 32;

// Variable para almacenar el estado anterior del botón
int botStAn = LOW;

// Variable para almacenar los pulsos
int pulseCount = 0;

// Variables para controlar los estados del led
bool ledState = false;
unsigned long tiempoAnteriror = 0;
unsigned long interval = 1000; // Define el tiempo de espera

bool ledStates[] = {false, false, false, false};
unsigned long tiempoAnt[] = {0, 0, 0, 0};
//unsigned long tiempoDes[] = {50, 100, 150};
unsigned long tiempoDes = 50;
 byte ledBr[] = {0, 0, 0};
// Variable para almacenar el led actual a modificar (Punto2)
int ledActual = 0;

bool whileCont = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Configurar el pin del botón como entrada con resistencia pull-up interna
  Serial.begin(9600); // Iniciar la comunicación serial para mostrar los resultados en el Monitor Serie
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
}

void loop() {
   
  // Leer el estado del botón
  int buttonState = digitalRead(buttonPin);
  
  // Contador de pulsos
  if (buttonState == HIGH && botStAn == LOW) {
    pulseCount++; // Incrementar el contador de pulsos
    Serial.print("Pulsos: ");
    Serial.println(pulseCount); // Debug del contador de pulsos 
    Serial.println(sizeof(ledPins));
    Serial.println(sizeof(ledPins[0]));
    Serial.println(RGB);
    ledState = false;
    ledActual = 0;
     for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
    }
  }
  
  // Actualizar el estado anterior del botón
  botStAn = buttonState;
  // Reiniciar el contador
   if(pulseCount > 3){
     pulseCount = 0;
  }
  // Ejecutar las distintas funciones correspondientes a las pulsaciones realizadas 
  if(pulseCount == 0){
  punto1();
  }
  
  else if(pulseCount == 1){
  punto2();
  }
  
  else if(pulseCount == 2){
  punto3();
  }
  else if(pulseCount == 3){
  punto4();
  }
}
void punto1(){
// Obtener el tiempo actual
  unsigned long tiempoActual = millis();

  // Comprobar que el paso del tiempo es mayor al del intervalo
  if (tiempoActual - tiempoAnteriror >= interval) {
    //Actualizar  la variable de tiempo de referencia
    tiempoAnteriror = tiempoActual;

   // Establecer el estado del led como el opuesto al estado actual
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}

void punto2() {
  // Obtener el tiempo actual
  unsigned long tiempoActual = millis();

  // Temporizador
  if (tiempoActual - tiempoAnt[ledActual] >= interval) {
    tiempoAnt[ledActual] = tiempoActual;

    // Invertir el estado del led actual
    ledStates[ledActual] = !ledStates[ledActual];
    digitalWrite(ledPins[ledActual], ledStates[ledActual]);

    // Seleccionar un LED aleatorio
    int previousLedIndex = ledActual;
    while (ledActual == previousLedIndex) {
      ledActual = random(0, numLeds);
    }
  }
}
 void punto3() {
    /* unsigned long tiempoActual = millis();
     for (int i = 0; i < numLeds; i++){
        if (tiempoActual - tiempoAnt[i] >= tiempoDes[i]){
            tiempoAnt[i] = tiempoActual;
            analogWrite(rgbPins[i], ledBr[i]);
          Serial.println("Se activó el IF");
          Serial.println(i);
          if(ledBr[2] > 0){
            whileCont = true;
          }
          while(whileCont == true){
            ledBr[i] -= 5;
            whileCont = false;
            Serial.println("Se activó el WHILE");
            Serial.println(ledBr[i]);

          }
        }   
    }   */
     if (ledActual < RGB) {
    unsigned long tiempoActual = millis();
    if (tiempoActual - tiempoAnteriror >= tiempoDes) {
      tiempoAnteriror = tiempoActual;
      // Incrementar el brillo del led 
      ledBr[ledActual] += 5;
      ledBr[ledActual] = constrain(ledBr[ledActual], 0, 255);
      // Actualizar el brillo del led
      analogWrite(rgbPins[ledActual], ledBr[ledActual]);     
    }
    // Si el brillo del led actual ha alcanzado el máximo, pasar al siguiente LED
    if (ledBr[ledActual] >= 255) {
      ledActual++;
      Serial.println(ledBr[0]);
    }
  }
  // Apagar lentamente los led
  else {
    for (int i = RGB - 1; i >= 0; i--) {
      unsigned long tiempoActual = millis();
      if (tiempoActual - tiempoAnteriror >= tiempoDes) {
       tiempoAnteriror = tiempoActual;
        // Reducir el brillo del led
        ledBr[i] -= 5;
        ledBr[i] = constrain(ledBr[i], 0, 255);
        // Actualizar el birllo del led  
        analogWrite(rgbPins[i], ledBr[i]);   
      }
    }
        if (ledBr[0] <= 0) {
      ledActual = 0;
      // Establecer el brillo de todos los leds en 0 
      for (int i = 0; i < RGB; i++) {
        ledBr[i] = 0;
        analogWrite(rgbPins[i], ledBr[i]);
      }
    }
  }

 }
 void punto4(){
  unsigned long tiempoActual = millis();  

  if (tiempoActual - tiempoAnteriror >= 1000) {
    tiempoAnteriror = tiempoActual; 
    mostrarNumero(numeroActual);

    // Incrementar el número actual
    numeroActual++;
    if (numeroActual > 9) {
      numeroActual = 0;
    }
  }
}
void mostrarNumero(int numero) {
  // Obtener los estados de los segmentos para el número dado
  int *estados = numeros[numero];

  // Establecer los pines del display según los estados de los segmentos
  digitalWrite(segmentA, estados[0]);
  digitalWrite(segmentB, estados[1]);
  digitalWrite(segmentC, estados[2]);
  digitalWrite(segmentD, estados[3]);
  digitalWrite(segmentE, estados[4]);
  digitalWrite(segmentF, estados[5]);
  digitalWrite(segmentG, estados[6]);
}