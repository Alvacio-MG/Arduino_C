// Pines de los leds
const byte ledPin = 3;

const int ledPins[] = {3, 5, 7, 9};
const byte numLeds = sizeof(ledPins) / 2;

const byte rgbPins[] = {11, 10, 6}; 
const byte RGB = sizeof(rgbPins) / 2;
// Pin del botón
const int buttonPin = 4;

// Variable para almacenar el estado anterior del botón
int previousButtonState = LOW;

// Variable para almacenar los pulsos
int pulseCount = 0;

// Variables para controlar los estados del led
bool ledState = false;
unsigned long tiempoAnteriror = 0;
unsigned long interval = 1000; // Define el tiempo de espera

bool ledStates[] = {false, false, false, false};
unsigned long tiempoAnt[] = {0, 0, 0, 0};
unsigned long tiempoDes[] = {5, 10, 15};

 byte ledBr[] = {255, 255, 255};
// Variable para almacenar el led actual a modificar (Punto2)
int ledActual = 0;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Configurar el pin del botón como entrada con resistencia pull-up interna
  Serial.begin(9600); // Iniciar la comunicación serial para mostrar los resultados en el Monitor Serie
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
   
  // Leer el estado del botón
  int buttonState = digitalRead(buttonPin);
  
  // Contador de pulsos
  if (buttonState == HIGH && previousButtonState == LOW) {
    pulseCount++; // Incrementar el contador de pulsos
    Serial.print("Pulsos: ");
    Serial.println(pulseCount); // Debug del contador de pulsos 
    Serial.println(sizeof(ledPins));
    Serial.println(sizeof(ledPins[0]));
    Serial.println(RGB);
     for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
    }
  }
  
  // Actualizar el estado anterior del botón
  previousButtonState = buttonState;
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
 /* else if(pulseCount == 2){
  punto4();
  }*/
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
    unsigned long tiempoActual = millis();
     for (int i = 0; i < numLeds; i++){
        if (tiempoActual - tiempoAnt[i] >= tiempoDes[i]){
            tiempoAnt[i] = tiempoActual;
            analogWrite(rgbPins[i], ledBr[i]);
          if(ledBr[i] > 0 && ledState == true){
          ledBr[i] -= 1;
            Serial.print("Se activo con i=");
            Serial.println(i);
           /* if (i == 3 && ledBr[i] <= 0 ){
            ledState = false;
           } */
          } 
          if(i == 0 && ledBr[i] <= 0){
              ledState = false;
          }
          if(ledBr[i] < 255 && ledState == false){
          ledBr[i] += 1;
            Serial.print("Se activo con i=");
            Serial.println(i);
           /* if (i == 3 && ledBr[i] <= 0 ){
            ledState = false;
           } */
          } 
           if (ledState == false && i == 0 && ledBr[i] == 0){
                ledState = true;
            }
          /* else if( i == 2 &&  ledBr[i] == 0 && ledState == false)
            Serial.println(ledBr[i]); */
        }   
    }  

 }
/* void punto4(){
  unsigned long tiempoActual = millis();
} */