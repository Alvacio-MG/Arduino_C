// Pin de los LEDs
const int ledPin = 3;

const int ledPins[] = {3, 5, 6, 9};
const int numLeds = sizeof(ledPins) / 2; //La función "sizeof" devuelve el numero de bits del array, cada numero ocupa 2 bits, por eso se divide por dos, para obtener el número de valores que teine el arrray

// Pin del botón
const int buttonPin = 4;

// Variable para almacenar el estado anterior del botón
int previousButtonState = LOW;

// Variable para almacenar el índice actual de LED(Los leds)
int currentLedIndex = 0;

// Variable para almacenar el contador de pulsos
int pulseCount = 0;
// Variables para controlar el estado del LED
bool ledState = false;
unsigned long previousTime = 0;
unsigned long interval = 1000; // Intervalo de tiempo en milisegundos (1 segundo)

bool ledStates[] = {false, false, false, false};
unsigned long previousTimes[] = {0, 0, 0, 0};
unsigned long intervals[] = {1000, 1500, 2000, 2500}; //Cada led tiene su intevalo para que no cambien a la vez

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Configurar el pin del botón como entrada con resistencia pull-up interna
  Serial.begin(9600); // Iniciar la comunicación serial para mostrar los resultados en el Monitor Serie
  for (int i = 0; i < numLeds; i++) { //La funcion "for" es utilizada para establecer los led como output, por cada valor de "i" (desde el 0 al 4) se le asigan a un espacio
    pinMode(ledPins[i], OUTPUT); //--  del array como output, hasta que i es igual al numero de valores que tiene el array, en ese momento se detiene y deja de ejecutar el for
  }
}

void loop() {

  // Leer el estado actual del botón
  int buttonState = digitalRead(buttonPin);

  // Verificar si ha ocurrido un flanco de subida del botón
  if (buttonState == HIGH && previousButtonState == LOW) {
    pulseCount++; // Incrementar el contador de pulsos
    
    Serial.print("Pulsos: ");
    Serial.println(pulseCount); // Mostrar el contador de pulsos en el Monitor Serie
    Serial.println(sizeof(ledPins[0]));

    for (int i = 0; i < numLeds; i++) { //El bucle "for" sirve para establecer todos los leds como low
    digitalWrite(ledPins[i], LOW);
    }
  }


  //Prueba para ver el estado del boton en tiempo real
  /* if(pulseCount <= 4){
    digitalWrite(ledPin, HIGH);
    Serial.print("PulsosButt: ");
    Serial.println(pulseCount);
  }
  else{
  digitalWrite(ledPin, LOW);
  } */

  // Actualizar el estado anterior del botón
  previousButtonState = buttonState;

  // reiniciar el contador
 if(pulseCount > 3){
     pulseCount = 0;
  }
  
  // Ejecutar los distintos códigos almacenados como distintos "void"
  // Es importante que esté pusto al final ya que si no, habría un momento en que la variable "pulseCount" sería igual a 4
  if(pulseCount == 0){
  punto1();
  }
  else if(pulseCount == 1){
  punto2();
  }
}
void punto1(){
// Obtener el tiempo actual
  unsigned long currentTime = millis();

  // Verificar si ha pasado el tiempo suficiente para cambiar el estado del LED
  if (currentTime - previousTime >= interval) {
    // Guardar el tiempo actual como referencia para la próxima vez
    previousTime = currentTime;

    // Cambiar el estado del LED
    ledState = !ledState;

    // Encender o apagar el LED según el estado actual
    digitalWrite(ledPin, ledState);
  }
 

}

