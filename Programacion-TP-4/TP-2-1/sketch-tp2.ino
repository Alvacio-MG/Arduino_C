// C++ code
//variables de los pines
int ledP = 3;
int btn1 = 4;
int btn2 = 5;
int pot = A5;
// variables de los estados 
int potEs = 0;
int btn1Es = 0;
int btn2Es = 0;
int ledEs = 0;

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
    // debug
 if (digitalRead(btn1) == HIGH || digitalRead(btn2) == HIGH){
    Serial.print("Botón apretadito:");
    Serial.print(digitalRead(btn1));
    Serial.println(digitalRead(btn2));
    delay(50);
 }
 if (analogRead(pot) > 0){
    Serial.println(analogRead(pot));
 }
}