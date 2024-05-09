#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET   -1
SSD1306Wire display(0x3C, SDA, SCL);  

void setup() {
  Serial.begin(9600);
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
    display.init();
  display.setContrast(255);
  display.display();
  delay(2000); // Pause for 2 seconds
}

void loop() {
  //display.flipScreenVertically();
 // Some test data
algo();
delay(1000);
display.clear();
  // Some test data
 
}
void algo(){
    display.setLogBuffer(5, 30);
   const char* test[] = {
    "1a",
    "2e",
    "3i",
    "4o",
    "5u",
    "6A",
    "7E",
    "8I",
    "9O",
    "10U",
    "ESTÁ FUNCIONANDO",
  };

  for (uint8_t i = 0; i < 11; i++) {
    display.clear();
    // Print to the screen
    display.println(test[i]);
    // Draw it to the internal screen buffer
    display.drawLogBuffer(0, 0);
    // Display it on the screen
    display.display();
    delay(1000);
  }
}
