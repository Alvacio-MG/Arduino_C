int led = 14;
int oscilo = 27;
int x = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(2000000);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long periodo = 100;
  unsigned long period2 = 2000;
  unsigned long periodIN = 10;
  static unsigned long previoMillis = 0;
  static unsigned long previousMillis2 = 0;
  static unsigned long previousMillisIN = 0;
  if ((millis() - previoMillis) > periodo) {

    x++;
    analogWrite(led, x);
    previoMillis += periodo;
    while (x >= 250) {
      x = 0;
    }
       
  }
  int sensorValue = analogRead(oscilo);
    Serial.println(sensorValue);
}
