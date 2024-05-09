unsigned long tiempo = 0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(921600);
}

void loop() {
  tiempo = millis();
  // put your main code here, to run repeatedly:
  if (tiempo == 1500){
    
  }
  Serial.print("Transcurrido: ");
  Serial.println(tiempo);
}
