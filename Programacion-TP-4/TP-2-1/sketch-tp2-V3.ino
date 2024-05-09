// C++ code
// variables de los pines
byte ledP = 3;
byte btn1 = 4;
byte btn2 = 5;
byte pot = A5;
// variables de los estados 
int potEs = 0;
byte btn1Es = 0;
byte btn2Es = 0;
byte ledEs = 0;
// variables del tiempo
unsigned long tiempoAn = 0;
unsigned long interval = 0;

void setup()
{
// establecer los pines de salida
  pinMode(ledP, OUTPUT);
// establecer los pines de entrada
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(pot,INPUT);
//iniciar la comunicación serial
  Serial.begin(9600);
}

void loop()
{

update(); // comprobar el estado de los botones y el potenciómetro 

 if (btn1Es == HIGH){ // si el botón 1 está pulsado
 // debug
    Serial.print("Botón pulsado: ");
    Serial.print(btn1Es);
    Serial.println(btn2Es);
    // variable que almacena el estado del led y debug
    ledEs = map(potEs, 0, 1023, 0, 255);
    Serial.print("estado del led: ");
    Serial.println(ledEs);
    /* delay(50); */
 }
 
 if (btn2Es == HIGH){ // si el botón 2 está pulsado
 // debug
    Serial.print("Botón pulsado: ");
    Serial.print(btn1Es);
    Serial.println(btn2Es);
    // variable que almacena el estado del led
    ledEs = 0;
    /* delay(50); */
 }
 while(btn1Es == HIGH && btn2Es == HIGH){ // si ambos botónes están pulsados
   blink(); // llama la función que hace parpadear al led
   update(); // actualiza el valor de los botones
 }
 // estblece el valor del led
   analogWrite(ledP, ledEs); 

}
void blink(){ // función qu enciende y apaga el led
   unsigned long tiempo = millis(); // almacena le tiempo actual
   update(); 
   interval = map(potEs, 0, 1023, 0, 5000); // establece le tiempo del intervalo en relación al potenciómetro
   if (tiempo - tiempoAn >= interval){ // si el tiempo actual menos el tiempo en que ocurrió la ultima "activación" del if es mayor al intervalo 
      //temporizador
      tiempoAn = tiempo; // actualiza la variable del tiempo anterior
      //estado del led
      digitalWrite(ledP, ledEs); 
      ledEs = !ledEs; // niega el valor de la variable que almacena le estado del led
      //debug
      Serial.println(interval);
   }
}
void update(){ //funcion para leer el estado de los botones y el potenciometro
   btn1Es = digitalRead(btn1);
   btn2Es = digitalRead(btn2);
   potEs = analogRead(pot);
}