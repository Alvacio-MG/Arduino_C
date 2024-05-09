//#include <SoftwareSerialTX.h>
//#include <Arduino.h>
//#include "SoftwareSerial.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  // Serial2.begin(115200);
  //Serial2.begin(115200, SERIAL_8N1, RXD1, TXD1);
}
void loop() {
 if(Serial.available());
  Serial.write(Serial.read());

}
