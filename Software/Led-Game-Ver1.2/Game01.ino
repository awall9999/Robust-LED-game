// Captutre the dot
// Move the Player Icon to the column, where the Dot moves down to win
int OldPlayerPos = 0;

void Game01 () {
 ClearAll();
 UpdateLEDs();
 GameStartupAni();
 
 ClearAll();
 PlayerPos=0; // Player in position 0
 PlayerColor=8; // Player color is orange
 LEDPos[Status]=2; //Power Led is Green
 LEDPos[Player[PlayerPos]]=PlayerColor; //Light up Player
 UpdateLEDs(); // update LEDs       

 int DotColor = 0;
 int DotRows = 0;
 int DotColumns = 0;
 int NewDot=0;
 int Life=0;
 int Speed = 150;
 int SpeedCounter= 0;
 
 do {
  if(NewDot==0) {NewDot=1;
                 WaitMS(1000);
                 DotColor=random(1,8);
                 do{
                   DotColumns=random(0,5);
                   
                   } while (DotColumns == PlayerPos);
                 PlayVoice(13);
                }



  LEDPos[Field [DotRows][DotColumns]] = DotColor;
  CheckButtons();
  
  
  
  SpeedCounter ++;
  if (SpeedCounter==Speed) {SpeedCounter=0;
                        PlayVoice(13);
                        LEDPos[Field [DotRows][DotColumns]] = 0;UpdateLEDs(); 
                        
                        DotRows++;
                        if(DotRows==4){WaitMS(100);
                                       if(DotColumns==PlayerPos) {LedAniWinner01();
                                                                  SmileResult(Life,0);} else {LedAniLooser01();
                                                                                              SmileResult(Life,1);}
                                       Life++;
                                       DotRows=0;
                                       NewDot=0;
                                       }
                        }


  UpdateLEDs();                        
  WaitMS(5);
} while (Life != 3);
WaitMS(1000);
PlayVoice(11);
WaitMS(7000);
if (digitalRead(ByPassMenu) == 1) {GameSelect=5;} else {AutoSelect =1;} //when pin 10 is open or high, jump to Gameselect when pin 10 is Low play next game
}
