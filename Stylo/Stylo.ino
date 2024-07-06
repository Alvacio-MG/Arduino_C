//Constantes de pines de entrada y salida
const int potPin = A0;
const int potPin0 = A1;
int boton = 8;
int boton2 = 7;
const int buzzerPin = 11; // creo que lo borré sin querer

//Variables de control
float baseFrequency = 440.0;
bool botonE2 = 0;
bool botonEA2 = 0;
bool botonE = 0;
bool botonEA = 0;
float tecla = 0;
int notasN = 12;
bool buzzerStat = 0;
float tiempoP = 0;

void setup() {
  // Inicializar comunicación serial y establecer los pines de entrada y salida
  pinMode(potPin, INPUT);
  pinMode(potPin0, INPUT);
  pinMode(boton, INPUT);
  pinMode(boton2, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  //Establece las variables de lectura de los potenciómetros y las acomoda respecto a los valores necesitados 
    float sensorValue= analogRead(potPin);
    float sensorValue0= analogRead(potPin0);
    //Serial.println(sensorValue);
    float papa1 = map(sensorValue0,0,1023,0,100);
    float papa = papa1/100;
    //Serial.println(papa);
    sensorValue = map(sensorValue, 0, 1023, 0, notasN);
    //Establece las variables de lectura de lso pines de lso botones
    botonE = digitalRead(boton);
    botonE2 = digitalRead(boton2);
    //Un detector de escalón que lee los pines de los botónes y cuando detecta que son pulsados, duplica la frecencia base de las notas 
      if (botonE == 1 && botonEA == 0){
        baseFrequency = baseFrequency*2;
        botonEA = 1;
    }
    else if(botonE == 0 && botonEA == 1){
      botonEA = 0;
    }

      if (botonE2 == 1 && botonEA2 == 0){
        baseFrequency = baseFrequency/2;
        botonEA2 = 1;
    }
    else if(botonE2 == 0 && botonEA2 == 1){
      botonEA2 = 0;
    }
    //Un limitaodr de la frecuecnia base, que impida que se salga del rago de la sexta octava(1760Hz)
    if(baseFrequency >= 1760){
      baseFrequency = 55;
    } 
    //Un limitaodr de la frecuecnia base, que impida que se salga del rago de la primera octava(55Hz)
    if(baseFrequency <= 55){
      baseFrequency = 1760;
    } 
    //Si se detecta el stylo hace contacto con alguna tecla, se evalúa la tecla y se ejecuta la nota correspondiente, de lo contrario, se apaga el buzzer
  if(sensorValue > 0){
    tecla = constrain(sensorValue, 0, notasN);
    Serial.print("Tecla pulsada:");
    Serial.println(tecla);
      float frecu = (baseFrequency*pow(pow(2.00,0.0833),tecla))*(1.00+papa);
  tone(buzzerPin,frecu);
      Serial.print("Frecuencia:");
    Serial.println(frecu);
  }
  else{
    noTone(buzzerPin);
  }