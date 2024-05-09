int boton = 1;
int SH = 13;
int ST = 14;
int DS = 26;
int OE = 27;
int pul = 0;

void setup() {
  pinMode(SH, OUTPUT);
  pinMode(ST, OUTPUT);
  pinMode(DS, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(boton, INPUT);

}

void loop() {
  if (digitalRead(boton) == HIGH) {
    pul = pul + 1;
    delay(300);
  }
  if (pul == 1) {
    digitalWrite(DS, HIGH);
    digitalWrite(SH, HIGH);
    digitalWrite(ST, HIGH);
    digitalWrite(OE, HIGH);
    digitalWrite(DS, HIGH);
    digitalWrite(DS, HIGH);
    digitalWrite(DS, HIGH);
    digitalWrite(DS, HIGH);
    digitalWrite(DS, HIGH);
    digitalWrite(DS, HIGH);
    digitalWrite(DS, HIGH);
    digitalWrite(DS, HIGH);
  }
  else if (pul == 10) {
    pul = 0;
  }
}
