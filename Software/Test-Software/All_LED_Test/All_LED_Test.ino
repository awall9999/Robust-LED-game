// All LED Test. All WS2812b LEDs will randomly change colour every second.

#define NOOP            asm("nop\n")
#define BITHIGH         asm ("sbi %0, %1 \n": : "I" (_SFR_IO_ADDR(PORTD)), "I" (PORTD2) );
#define BITLOW          asm ("cbi %0, %1 \n": : "I" (_SFR_IO_ADDR(PORTD)), "I" (PORTD2) );
unsigned long time_now = 0;
unsigned long timer = 50;
volatile byte  red[60],green[60],blue[60];
volatile byte  pos[60],color[60],LED[60];


                            


int Result=0;
int LEDPos=-1;
int LB=255; //Brightness LED

void setup() {
  Serial.begin(9600);
  
  pinMode(2,OUTPUT);
  for (int i = 0; i <= 60; i++) {red[i]=0;green[i]=0;blue[i]=0;} // reset all LEDs
  Resetall();
  Serial.println("Start");
  
  Result=67;
  
}





void loop() {
 Serial.println();
 Result=random(1,11);
 for (int count = 0; count <= 59; count++){LED[count] = random(1,11);}
 

 for (int count = 0; count <= 59; count++){
    
    
    LEDcall(LED[count]);
  }
 
delay(1000);
  
}
