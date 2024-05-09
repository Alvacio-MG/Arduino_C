const int inputPin = 13;
volatile unsigned long previousTime = 0;
volatile unsigned long interval = 0;

void IRAM_ATTR handleInterrupt() {
  unsigned long currentTime = micros();
  interval = currentTime - previousTime;
  previousTime = currentTime;
}

void setup() {
  pinMode(inputPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(inputPin), handleInterrupt, RISING);
  Serial.begin(115200);
}

void loop() {
  if (interval > 0) {
    Serial.print("Interval: ");
    Serial.print(interval);
    Serial.println(" microseconds");
    interval = 0;
  }
}