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
  pinMode(ledP, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);
}

void loop()
{
btn1Es = digitalRead(btn1);
btn2Es = digitalRead(btn2);
potEs = analogRead(pot);

 if (btn1Es == HIGH){
    Serial.print("Botón apretadito:");
    Serial.print(digitalRead(btn1));
    Serial.println(digitalRead(btn2));
    ledEs = map(potEs, 0, 1023, 0, 255);
    Serial.print("estado del led");
    Serial.println(ledEs);
    delay(50);
 }
 
 if (btn2Es == HIGH){
    Serial.print("Botón apretadito:");
    Serial.print(digitalRead(btn1));
    Serial.println(digitalRead(btn2));
    ledEs = 0;
    delay(50);
 }
 while(btn1Es == HIGH && btn2Es == HIGH){
   blink();
   btn1Es = digitalRead(btn1);
   btn2Es = digitalRead(btn2);
 }

analogWrite(ledP, ledEs);
}
void blink(){
   unsigned long tiempo = millis();
   potEs = analogRead(pot);
   interval = potEs;
   if (tiempo - tiempoAn >= interval){
      tiempoAn = tiempo;
      digitalWrite(ledP, ledEs);
      ledEs = !ledEs;
      Serial.println(interval);
   }
}
void update(){
   
}