//shoot the dot (Ufo)
// Move the player icon to the dot that appears at the top and press fire. If you hit it, you win.

void Game03(){
int DotColumns=0;
int DotColor=0;
int Life=0;
int Toggle=0;
GameStartupAni();
 
 ClearAll();
 PlayerPos=0; // Player in position 0
 PlayerColor=2; // Player color is blanc
 LEDPos[Status]=2; //Power Led is Green
 LEDPos[Player[PlayerPos]]=PlayerColor; //Light up Player
 UpdateLEDs(); // update LEDs 
do{ 
// Ufo Landing
PlayVoice(17);
WaitMS(10);
do{
  DotColor=random(2,10);
  LEDPos[Field [0][DotColumns]] = DotColor; UpdateLEDs();
  WaitMS (random(80,150));
  LEDPos[Field [0][DotColumns]] = 0; UpdateLEDs();
  DotColumns++;
  if (DotColumns >4) DotColumns=0;
  
} while (digitalRead(Busy) != 1); // Repeat until the Soundfile is finished   
  LEDPos[Field [0][DotColumns]] = DotColor; UpdateLEDs();
// move Player
PlayerFire=0;
do {
     CheckButtons();
     WaitMS(10);
     if ((unsigned long)(millis() - Sleeptimer) > GoToSleep){GoodNight();} // if no button pressed, game will shutdown after the set time (normaly 1 min)
   }while (PlayerFire != 1);
   PlayerFire=0;

// Fire 
PlayVoice(16);

for (int Pos = 0; Pos <= 3; Pos++){LEDPos[Field [3-Pos][PlayerPos]]=1;UpdateLEDs();
                                  
                                  if(PlayerPos==DotColumns && Pos==3){PlayVoice(18);
                                                                      for (int i = 0; i <= 10; i++) {
                                                                      LEDPos[Field [0][PlayerPos]]=Toggle;UpdateLEDs(); 
                                                                      Toggle=!Toggle;
                                                                      WaitMS(100); 
                                                                                                     }
                                                                      
                                                                     }
                                  WaitMS(100);
                                  LEDPos[Field [3-Pos][PlayerPos]]=0;UpdateLEDs();
                                  }

    
    
if(PlayerPos==DotColumns){LedAniWinner01();SmileResult(Life,0);} else {LedAniLooser01();SmileResult(Life,1);}


Life++ ;   
WaitMS(1000);                  
}while (Life != 3);

WaitMS(1000);
PlayVoice(11);
WaitMS(7000);
if (digitalRead(ByPassMenu) == 1) {GameSelect=5;} else {AutoSelect =1;} //when pin 10 is open or high, jump to Gameselect when pin 10 is Low play next game
    
}
