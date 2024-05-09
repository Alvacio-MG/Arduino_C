#include <dummy.h>
int led = 14;
int oscilo = 27;
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
Serial.begin(2000000);
}

void loop() {
  // put your main code here, to run repeatedly:
 unsigned long period=1000;
 unsigned long period2=2000;
static unsigned long previousMillis=0;
static unsigned long previousMillis2=0;

if ((millis()-previousMillis) > period){
  // ---------------------------------
  // TODO:
  // Codigo de la Tarea 
  // ...
  // --------------------------------- 
  digitalWrite(led, HIGH);
  
for (int x = 0; x < 20; x++){
   int sensorValue1 = analogRead(oscilo);
   Serial.println(sensorValue1);
}
previousMillis += period;
}
else if ((millis() - previousMillis2) > period2){
  digitalWrite(led, LOW);
  for (int x = 0; x < 20; x++){
   int sensorValue1 = analogRead(oscilo);
   Serial.println(sensorValue1);
}
  previousMillis2 += period2;
/*  int sensorValue2 = analogRead(oscilo);
Serial.println(sensorValue2); */
}
/* int sensorValue = analogRead(oscilo);
Serial.println(sensorValue); */
 /* int sensorValue3 = analogRead(oscilo);
Serial.println(sensorValue3); */
}
/* 

#include <dummy.h>
int led = 14;
int oscilo = 27;
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
Serial.begin(2000000);
}

void loop() {
  // put your main code here, to run repeatedly:
 unsigned long period=1000;
 unsigned long period2=2000;
static unsigned long previousMillis=0;
static unsigned long previousMillis2=0;

while ((millis()-previousMillis) > period){
  // ---------------------------------
  // TODO:
  // Codigo de la Tarea 
  // ...
  // --------------------------------- 
  digitalWrite(led, HIGH);
for (int x = 0; x < 10; x++){
   int sensorValue1 = analogRead(oscilo);
   Serial.println(sensorValue1);
}
previousMillis += period;
}
while ((millis() - previousMillis2) > period2){
  digitalWrite(led, LOW);
for(int y = 0; y < 10; y++){  
 int sensorValue2 = analogRead(oscilo);
 Serial.println(sensorValue2);
}
previousMillis2 += period2;
}
/* int sensorValue = analogRead(oscilo);
Serial.println(sensorValue); */
 /* int sensorValue3 = analogRead(oscilo);
Serial.println(sensorValue3); */
/* } */



