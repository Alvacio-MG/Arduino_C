int latchpin = 27; //Assign output register clock (pin 12) of 74HC595
int clockpin = 26; //Assign shift register clock (pin 11) of 74HC595
int datapin = 25; //Assign input (pin 14) of 74HC595

void setup()
{
  //set pins as output to control the shift register
  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);
}

void loop()
{
  //loop - as long the count (i) is less than 256
  // the statements under the loop is excecuted
  for (int i = 0; i < 256; i++) {
    digitalWrite(latchpin, LOW); //set latchpin to LOW so LEDs won't light up while sending in bits
    shiftOut(datapin, clockpin, MSBFIRST, i); // shifts out the bits
    digitalWrite(latchpin, HIGH); //set the latchPin to HIGH for LEDs to light up
    delay (1000); //pause for a second before the next value 
  }
}
