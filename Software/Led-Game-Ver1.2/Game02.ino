// Guess the color
// Move the coloured player icon to the dot with the same colour and press fire to select. If the colour is the same you win
void Game02 () {
  

GameStartupAni();
 
 ClearAll();
 PlayerPos=0; // Player in position 0
 PlayerColor=0; // Player color is blanc
 LEDPos[Status]=2; //Power Led is Green
 LEDPos[Player[PlayerPos]]=PlayerColor; //Light up Player
 UpdateLEDs(); // update LEDs   
  

 int DotColor[5] = {0,0,0,0,0};
 int SelectStartBolor=0;
 int ColorRND=0;
 int ColorCheck=0;
 
 int NewDot=0;
 int Life=0;
 do{
 //SelectStartBolor=random(1,10);
 // Set Dots and Colors
 for (int Pos = 0; Pos <= 4; Pos++){DotColor[Pos]=random(1,10);
                                    do{
                                    ColorRND=random(1,8);
                                    if (ColorRND != DotColor[0] && ColorRND != DotColor[1]&& ColorRND != DotColor[2]&& ColorRND != DotColor[3]&& ColorRND != DotColor[4] ) ColorCheck=1;  
                                    }while (ColorCheck == 0);
                                    DotColor[Pos]= ColorRND;
                                    WaitMS(500);
                                    LEDPos[Field [3][Pos]]=DotColor[Pos];
                                    
                                    PlayVoice(8);
                                    UpdateLEDs();
                                    ColorCheck=0; 
                                    }
 
 WaitMS(1000);
// Set Player Color
 PlayVoice(4);
 do{SelectStartBolor=random(0,5);
    PlayerFire=0;
    LEDPos[Player[PlayerPos]]=DotColor[SelectStartBolor];
    PlayerColor=DotColor[SelectStartBolor];
    UpdateLEDs();
    WaitMS(random(50,300));
    
 } while (digitalRead(Busy) != 1); // Repeat until the Soundfile is finished  
 

 do {
     CheckButtons();
     if(PlayerFire==1) {
                        if(PlayerColor==LEDPos[Field [3][PlayerPos]]){LedAniWinner01();SmileResult(Life,0);} else {LedAniLooser01();SmileResult(Life,1);}
                       }
    WaitMS(100);
    if ((unsigned long)(millis() - Sleeptimer) > GoToSleep){GoodNight();} // if no button pressed, game will shutdown after the set time (normaly 1 min)
    }while (PlayerFire != 1);
    PlayerFire=0;
    Life++;
    WaitMS(1000);
                                    
 }while (Life != 3);
WaitMS(1000);
PlayVoice(11);
WaitMS(6000);
if (digitalRead(ByPassMenu) == 1) {GameSelect=5;} else {AutoSelect =1;} //when pin 10 is open or high, jump to Gameselect when pin 10 is Low play next game
 }
 
