void Resetall(){
  noInterrupts();
  for (int i = 0; i <= (24*60); i++) Zero();
  interrupts();
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
  if (LC == 9) {r=LB;g=0;b=(LB/2);}      //Rose
  if (LC == 10) {r=(LB/2);g=0;b=LB;}      //Violet
  
  noInterrupts();
  //Serial.println(r);
  for (int i = 0; i <= 7; i++){
    if (bitRead(g,7- i)) One(); else Zero();
    //Serial.print(bitRead(g,7- i));
  }
  for (int i = 0; i <= 7; i++){
    if (bitRead(r,7- i)) One(); else Zero();
    
    //Serial.print(bitRead(r,7- i));
  }
  for (int i = 0; i <= 7; i++){
    if (bitRead(b,7- i)) One(); else Zero();
  }
  interrupts();
 }



void One(){
cli();
BITHIGH;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;
BITLOW;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;
sei();
}

void Zero(){
cli();
BITHIGH;NOOP;NOOP;NOOP;NOOP;NOOP;
BITLOW;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;NOOP;
sei();
}

void Treset(){
  time_now = micros();
  BITLOW;
do {
  
} while ((unsigned long)(millis() - time_now) < timer);  
}
