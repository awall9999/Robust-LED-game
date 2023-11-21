void Resetall(){
  // Set all the LEDs color to 0. 0=off
  noInterrupts();
  for (int i = 0; i <= (24*LN); i++) Zero();
  interrupts();
  Treset();//50us delay to end the transfer of data
}

void UpdateLEDs() {
                  for (int LEDCounter = 0; LEDCounter <= LN; LEDCounter++) {LEDcall(LEDPos[LEDCounter]);} // SerialOut of the Led Data
                  Treset();
}



void LEDcall(byte LC){
  byte r,g,b;
  if (LC == 0) {r=0;g=0;b=0;}       //Blanc
  if (LC == 1) {r=LB;g=0;b=0;}      //Red
  if (LC == 2) {r=0;g=LB;b=0;}      //Green
  if (LC == 3) {r=0;g=0;b=LB;}      //Blue
  if (LC == 4) {r=LB;g=LB;b=0;}      //Yellow
  if (LC == 5) {r=0;g=LB;b=LB;}      //Cyan
  if (LC == 6) {r=LB;g=0;b=LB;}      //Magenta
  if (LC == 7) {r=LB;g=LB;b=LB;}      //White

  if (LC == 8) {r=LB;g=(LB/2);b=0;}      //Orange
  
  if (LC == 9) {r=(LB/2);g=0;b=LB;}      //Violet
  
  noInterrupts();
  // send the 24 Bits of one Led. Green,Red and Blue
  // There is probably an more elegant way to do it, but it works
  for (int i = 0; i <= 7; i++){
    if (bitRead(g,7- i)) One(); else Zero();
    
  }
  for (int i = 0; i <= 7; i++){
    if (bitRead(r,7- i)) One(); else Zero();
    
    
  }
  for (int i = 0; i <= 7; i++){
    if (bitRead(b,7- i)) One(); else Zero();
  }
  interrupts();
 }



void One(){
cli();
BITHIGH;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT; // 0,75us (0.0625 * 12)  ---  0.0625us one cycle on 16MHZ
BITLOW;HALT;HALT;HALT;HALT;HALT;HALT; // 0,375us (0.0625 * 6) --- 0.0625us one cycle on 16MHZ
sei();
}

void Zero(){
cli();
BITHIGH;HALT;HALT;HALT;HALT;HALT; // 0,3125us (0.0625 * 5) --- 0.0625us one cycle on 16MHZ
BITLOW;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT; //0,8125us (0.0625 * 13) --- 0.0625us one cycle on 16MHZ
sei();
}


void Treset(){
  // 50uSec delay loop
  time_now = micros();
  BITLOW;
do {
  
} while ((unsigned long)(micros() - time_now) < 50);  
}
