/*
 * Led game for people with special needs
 * This code is for 16Mhz Arduinos. 
 * no external Lib needed
 * (C) Alain MAUER
 * www.alainsprojects.com
 */




#define HALT            asm("nop\n"); //Do Nothing
#define BITHIGH         asm ("sbi %0, %1 \n": : "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB4) ); // Port D12 up
#define BITLOW          asm ("cbi %0, %1 \n": : "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB4) ); // Port D12 down

int LN = 33; // Numbers of LEDs used
int LB=255; //Brightness LED
unsigned long GoToSleep = 1; //Game enter standby in X minutes
int NumberOfGames = 3; // Mumber of Games you have programed. max 5
const int FireOn = 2;
const int Left = 3;
const int Right = 4;
const int Busy = 11;
const int DataOut = 12;
const int ByPassMenu = 10;
const int Piezo = 5;

unsigned long time_now = 0;

unsigned long Sleeptimer = 0;

byte Player[5] = {6,5,4,3,2}; //define the LEDs for the Player
byte Status = 0; //define the LED for the Status
byte Smile [3][2] = { { 27,26}, 
                      { 24,25},
                      { 13,12},
                    };                    //define the LEDs for the smileys
byte Field [4][5] = { { 32,31,30,29,28}, 
                      { 19,20,21,22,23},
                      { 18,17,16,15,14},
                      { 7,8,9,10,11},
                    };                    //define the LEDs for the GameField

byte LEDPos[100]; // All Leds. 100 for this sketch
int counter=0;        // Test Variable
int PlayerPos=0; // Start Position 1 for the Player
int PlayerFire=0; //Check if Player fired
int PlayerColor=0; //Start Color of the Player, 0 = blanc
int Block=0; //Button debounce/block repeat
int GameSelect=0;
int AutoSelect =0;
//Sound
byte DFDataFile[] = {0x7E,0xFF,0x06,0x0F,0x00,0x01,0x00,0xEF}; // Dataset to send to the DF Mini player
int VolumeSet =0;
int FolderSet =1;

void WaitMS(int period){     // MicroSecond Delay Timer
    time_now = millis();
    do {
       //CheckButtons();
       } while ((unsigned long)(millis() - time_now) < period);  

}

void(* resetFunc) (void) = 0; // Reset the Arduino

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  LN=LN-1; // Led Start at 0 so I have to remove one 
  GoToSleep=GoToSleep*60000;
  pinMode(DataOut,OUTPUT);
  pinMode(FireOn,INPUT);
  pinMode(Left,INPUT);
  pinMode(Right,INPUT);
  pinMode(Busy,INPUT);
  pinMode(Piezo,OUTPUT);
  pinMode(ByPassMenu,INPUT_PULLUP);
  NumberOfGames=NumberOfGames-1; // correct the Number of Games, offset to zero
  if (digitalRead(ByPassMenu) == 1) {GameSelect=5;} else {GameSelect=0;} //when pin 10 is open or high, jump to Gameselect when pin 10 is Low first game
  LedTest();
  
  
  Serial.println("Scott's LED Game");
  Serial.println("Beta 1     ready");
  
  
}

void loop() {
LEDPos[Status]=2;
UpdateLEDs();
Sleeptimer=millis(); 

if (GameSelect == 0) Game01();
if (GameSelect == 1) Game02();
if (GameSelect == 2) Game03();
if (GameSelect == 3) Game04();
if (GameSelect == 4) Game05();
if (GameSelect == 5) GameStart();
if (AutoSelect == 1) {GameSelect++;if (GameSelect > NumberOfGames)GameSelect=0;AutoSelect = 0;}

}
