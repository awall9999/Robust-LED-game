void GameStart(){
// Game menu if D10 is open
// left and right moves the blue dot. The position of the dot is the Gameplay. Fire to start the selected game
// It´s more for advanced players or test purposes

int OldPlayerPos = 0;
ClearAll();
LEDPos[Status]=2;
LEDPos[Field [0][0]]=3 ;
PlayerPos=0;
PlayerFire=0;
PlayerColor=0;
UpdateLEDs();

do{
 CheckButtons();
 
 if (PlayerPos != OldPlayerPos) {LEDPos[Player[PlayerPos]]=0;
                                 LEDPos[Field [0][OldPlayerPos]]=0 ;
                                 WaitMS(10);
                                 if (PlayerPos > NumberOfGames) PlayerPos = NumberOfGames;
                                 LEDPos[Field [0][PlayerPos]]=3 ;
                                 OldPlayerPos = PlayerPos;
                                 UpdateLEDs();
                                 
                                 }                                
                                 
 
 
 if ((unsigned long)(millis() - Sleeptimer) > GoToSleep){GoodNight();} // if no button pressed, game will shutdown after the set time (normaly 1 min)
 WaitMS(10); 
}while (PlayerFire != 1);
PlayerFire = 0;
GameSelect=PlayerPos;

  
}
