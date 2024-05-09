#include <Adafruit_GFX.h>
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include <Adafruit_SSD1306.h>
#define WIDTH 128
#define HEIGHT 64
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(WIDTH, HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
 // if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
  //  Serial.println(F("SSD1306 allocation failed"));
  //  for(;;); // Don't proceed, loop forever
 // }
 display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  Wire.begin();
}

void loop() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("it´s been a log, long time");
  display.setCursor(20, 20);
  display.setTextSize(2);
  display.print(millis()/100);  
  display.display();
}
