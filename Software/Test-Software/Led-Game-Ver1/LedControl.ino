void Resetall(){
  noInterrupts();
  for (int i = 0; i <= (24*LN); i++) Zero();
  interrupts();
  Treset();
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
BITHIGH;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;
BITLOW;HALT;HALT;HALT;HALT;HALT;HALT;
sei();
}

void Zero(){
cli();
BITHIGH;HALT;HALT;HALT;HALT;HALT;
BITLOW;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;HALT;
sei();
}


void Treset(){
  // 50uSec delay loop
  time_now = micros();
  BITLOW;
do {
  
} while ((unsigned long)(micros() - time_now) < 50);  
}
