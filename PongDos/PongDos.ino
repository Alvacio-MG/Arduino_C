
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int ARRIBA_B = 13;
const int ABAJO_B = 14;

const unsigned long PADDLE_RATE = 20;
const unsigned long BALL_RATE = 1;
const uint8_t PADDLE_HEIGHT = 12;
int playerScore = 0;
int aiScore = 0;
int maxScore = 8;
int BUZZER = 15;
bool resetBall = false;
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define RESET_BUTTON 3
#define OLED_RESET 4 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void drawCourt();
void drawScore();

uint8_t ball_x = 64, ball_y = 32;
uint8_t ball_dir_x = 1, ball_dir_y = 1;
unsigned long ball_update;

unsigned long paddle_update;
const uint8_t CPU_X = 22;
uint8_t cpu_y = 26;

const uint8_t PLAYER_X = 105;
uint8_t player_y = 26;

void setup() {  
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.display();
    unsigned long start = millis();
    pinMode(BUZZER, OUTPUT);
    pinMode(ARRIBA_B, INPUT);
    pinMode(ABAJO_B, INPUT);
    pinMode(RESET_BUTTON, INPUT_PULLUP);
    //digitalWrite(SW_pin, HIGH);
    display.clearDisplay();
    drawCourt();
    drawScore();  
    while(millis() - start < 2000);
    Serial.begin(9600);

    display.display();

    ball_update = millis();
    paddle_update = ball_update;
}

void loop() {
    bool update = false;
    unsigned long time = millis();

    static bool up_state = false;
    static bool down_state = false;
    

    if(resetBall)
    {
      if(playerScore == maxScore || aiScore == maxScore)
            {
              gameOver();
            }
      else{      
      display.fillScreen(BLACK);
      drawScore();
      drawCourt();       
      ball_x = random(45,50); 
      ball_y = random(23,33);
      do
      {
      ball_dir_x = random(-1,2);
      }while(ball_dir_x==0);

       do
      {
      ball_dir_y = random(-1,2);
      }while(ball_dir_y==0);
      resetBall=false;
      }
    }
   
    if(time > ball_update) {
        uint8_t new_x = ball_x + ball_dir_x;
        uint8_t new_y = ball_y + ball_dir_y;

        if(new_x == 0 || new_x == 127) {
         
          if(new_x == 0){
            playerScore+=1;
            display.fillScreen(BLACK);
            Punto();
            resetBall = true;
            
          }
          else if(new_x == 127){
            aiScore+=1;
            display.fillScreen(BLACK);
            Punto();
            resetBall = true;
          }       
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
        }

        if(new_y == 0 || new_y == 63) {
            Rebote();
            ball_dir_y = -ball_dir_y;
            new_y += ball_dir_y + ball_dir_y;
        }

        // Check if we hit the CPU paddle
        if(new_x == CPU_X && new_y >= cpu_y && new_y <= cpu_y + PADDLE_HEIGHT) {
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
        }

        if(new_x == PLAYER_X
           && new_y >= player_y
           && new_y <= player_y + PADDLE_HEIGHT)
        {
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
        }

        display.drawPixel(ball_x, ball_y, BLACK);
        display.drawPixel(new_x, new_y, WHITE);
        ball_x = new_x;
        ball_y = new_y;

        ball_update += BALL_RATE;
        update = true;
    }

    if(time > paddle_update) {
        paddle_update += PADDLE_RATE;

        // CPU paddle
        display.drawFastVLine(CPU_X, cpu_y, PADDLE_HEIGHT, BLACK);
        const uint8_t half_paddle = PADDLE_HEIGHT >> 1;
        if(cpu_y + half_paddle > ball_y) {
            cpu_y -= 1;
        }
        if(cpu_y + half_paddle < ball_y) {
            cpu_y += 1;
        }
        if(cpu_y < 1) cpu_y = 1;
        if(cpu_y + PADDLE_HEIGHT > 63) cpu_y = 63 - PADDLE_HEIGHT;
        display.drawFastVLine(CPU_X, cpu_y, PADDLE_HEIGHT, WHITE);

        // Player paddle
        display.drawFastVLine(PLAYER_X, player_y, PADDLE_HEIGHT, BLACK);
        if(digitalRead(ABAJO_B)) {
            player_y -= 1;
        }
        if(digitalRead(ARRIBA_B)) {
            player_y += 1;
        }
        up_state = down_state = false;
        if(player_y < 1) player_y = 1;
        if(player_y + PADDLE_HEIGHT > 63) player_y = 63 - PADDLE_HEIGHT;
        display.drawFastVLine(PLAYER_X, player_y, PADDLE_HEIGHT, WHITE);
    }
        update = true;
    
    if(update){
        drawScore();
        display.display();
        }
}

void drawCourt() {
    display.drawRect(0, 0, 128, 64, WHITE);
}
void drawScore() {
  // draw AI and player scores
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(45, 0);
  display.println(aiScore);
  display.setCursor(75, 0);
  display.println(playerScore);
}

void gameOver(){ 
  display.fillScreen(BLACK);
  if(playerScore>aiScore)
  {
    display.setCursor(20,4);
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.println("WOW, en ");
    display.println("serio lo ");
    display.println("lograste");
  }else
  {
    display.setCursor(45,4);
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.println("Mejor ");
    display.println("suerte"); 
    display.println("para la ");
    display.println("proxima");            
  }
 delay(200);
 display.display();
 delay(2000);
 aiScore = playerScore = 0;
  
unsigned long start = millis();
while(millis() - start < 2000);
ball_update = millis();    
paddle_update = ball_update;
resetBall=true;
}

void Rebote() 
{
  tone(BUZZER, 500, 50);
}
void Punto() 
{
  tone(BUZZER, 250, 50);
}
