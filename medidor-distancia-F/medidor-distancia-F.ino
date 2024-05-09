// C++ code
//
int eco = 14;
int trigg = 13;
/* int ledV = 5;
int ledA = 6; */
int tiempo = 0;
  
void setup()
{
  pinMode(trigg, OUTPUT);
  pinMode(eco, INPUT);
//  pinMode(ledV, OUTPUT);
  //pinMode(ledA, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  long duracion;
  long distancia;
  
  digitalWrite(trigg,LOW);
  delay(4);
  digitalWrite(trigg,HIGH);
  delay(10);
  digitalWrite(trigg,LOW);
  
  duracion = pulseIn(eco, HIGH);
  Serial.print("La duración del pulso fue");
  Serial.println(duracion);
  distancia = duracion / 58;
  
  if(distancia >= 320 && distancia <= 0)
  {
    Serial.println("fuera de rango");
  }
  else 
  {
    Serial.print(distancia);
    Serial.println("cm");
    /* digitalWrite(ledA,HIGH); */
  }
  /* if(distancia <= 10 && distancia <= 1)
  {
    digitalWrite(ledV,HIGH);
  } */
}