const int trigPin = 13;
const int echoPin = 14;
long duracion;
int distancia;
void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(100);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(30);
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH);
  Serial.println(duracion);
  distancia = (duracion * 0.034) / 2;
  Serial.println(distancia);
  delay(500);
} 