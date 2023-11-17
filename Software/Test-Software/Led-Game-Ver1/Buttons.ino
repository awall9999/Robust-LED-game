void CheckButtons(){
random();


if (digitalRead(Left)==1 && PlayerPos > 0 && Block==0) {Block=1;  // If left button is pressed and position not already then far left position > execute
                          
                          LEDPos[Player[PlayerPos]]=0;            // Delete old Player position
                          PlayerPos--;                            // move player position to the left
                          LEDPos[Player[PlayerPos]]=PlayerColor;  // Set Player position
                          UpdateLEDs();                           // Update LED's
                          
                          } 
                           
if (digitalRead(Right)==1 && PlayerPos < 4 && Block==0) {Block=1;
                           
                           LEDPos[Player[PlayerPos]]=0;
                           PlayerPos++;
                           LEDPos[Player[PlayerPos]]=PlayerColor;
                           UpdateLEDs(); 
                           
                          } 

if (digitalRead(FireOn)==1 && Block==0) {Block=1;
                            PlayerFire=1;
                             
                          } 

if (digitalRead(Left) == 0 && digitalRead(Right) == 0 && digitalRead(FireOn) == 0 && Block == 1) {Block=0;
                                                                                                  Sleeptimer=millis();   // Reset SleepTimer
                                                                                                 } 
  
}
