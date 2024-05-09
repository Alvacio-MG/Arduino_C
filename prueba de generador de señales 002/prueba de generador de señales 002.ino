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
  unsigned long periodIN=10;
static unsigned long previousMillis=0;
static unsigned long previousMillis2=0;
static unsigned long previousMillisIN=0;


/* for (int y = 0; y < 250; y++){
  if ((millis() - previousMillisIN) > periodIN){
   analogWrite(led, y);
   previousMillisIN += periodIN;
  int sensorValue1 = analogRead(oscilo);
   Serial.println(sensorValue1);
   } 
   }
 */
 for (int x = 0; x < 250; x++){
   analogWrite(led, x);
   Serial.println(x);
   delay(20);
 
 }
}