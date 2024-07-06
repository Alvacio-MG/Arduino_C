//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__ESP32CORE_BLUETOOTH

#include <BluetoothSerial.h>;

// RemoteXY connection settings
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"


#include <RemoteXY.h>;

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 37 bytes
  { 255,3,0,0,0,30,0,17,0,0,0,31,1,106,200,1,1,2,0,5,
  22,60,60,60,32,2,26,31,1,13,17,24,24,0,2,31,0 };
 
// this structure defines all the variables and events of your control interface
struct {

    // input variables
  int8_t joystick_01_x; // from -100 to 100
  int8_t joystick_01_y; // from -100 to 100
  uint8_t button_01; // =1 if button pressed, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;  
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_BUTTON_01 14

int ejex = 0;
int ejey = 0;
int motorPin1 = 13;
int motorPin2 = 12;
int motorPin3 = 14;
int motorPin4 = 27;
const int estados[5][4] = {
  {1,0,1,0},
  {0,1,0,1},
  {1,0,0,0},
  {0,0,1,0},
  {0,0,0,0}
  };

void setup()
{
  RemoteXY_Init ();
 
  pinMode (PIN_BUTTON_01, OUTPUT);
  pinMode (motorPin1, OUTPUT);
  pinMode (motorPin2, OUTPUT);
  pinMode (motorPin3, OUTPUT);
  pinMode (motorPin4, OUTPUT);

  Serial.begin(9600);
 
  // TODO you setup code
 
}

void loop()
{
  RemoteXY_Handler ();
 
  //digitalWrite(PIN_BUTTON_01, (RemoteXY.button_01==0)?LOW:HIGH);
  ejex = RemoteXY.joystick_01_x;
  ejey = RemoteXY.joystick_01_y;

  Serial.print("Valor en Y");
  Serial.println(RemoteXY.joystick_01_y);
  Serial.print("Valor en X");
  Serial.println(RemoteXY.joystick_01_x);
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay()
  if(ejex == 100){
    MotorSet(0);
  }
  else if(ejex == -100){
    MotorSet(1);
  }
  else if(ejey == 100){
    MotorSet(3);
  }
    else if(ejey == -100){
    MotorSet(2);
  }
  else{
    MotorSet(4);
  }

}
void MotorSet(int varX){
digitalWrite(motorPin1,estados[varX][0]);
digitalWrite(motorPin2,estados[varX][1]);
digitalWrite(motorPin3,estados[varX][2]);
digitalWrite(motorPin4,estados[varX][3]);
Serial.print("Estado del motor 1A:");
Serial.println(estados[varX][0]);
}