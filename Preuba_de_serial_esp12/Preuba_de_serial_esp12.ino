int contador=0;

void setup() {
  Serial.begin(115200);
}

void loop(){
  //Imprimimos el valor del contador en el monitor serial
  Serial.print("Contador: ");
  Serial.println(contador);  
  //incrementamos el contador y esperamos medio segundo
  contador++;
  delay(500);
}
