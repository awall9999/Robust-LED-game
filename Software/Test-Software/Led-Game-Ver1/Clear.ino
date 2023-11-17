void ClearAll(){
  // What do you think it does?
  for (int i = 0; i <= LN; i++) {LEDPos[i]=0;} // All LEDs to 0
   
}

void ClearSmile(){
  //Clears the Smilefield
  for (int Row = 0; Row <= 2; Row++){
                                     for (int Col = 0; Col <= 1; Col++) {LEDPos[Smile [Row][Col]]=0;}
                                    }
   
}

void ClearField(){
  //Clears the Gamefield
  for (int Row = 0; Row <= 3; Row++){
                                     for (int Col = 0; Col <= 4; Col++) {LEDPos[Field [Row][Col]]=0;}
                                    }
   
}




void ClearFieldSlow(){
  //Clears the Playfield dot by dot
  for (int Row = 0; Row <= 3; Row++){
                                     for (int Col = 0; Col <= 4; Col++) {LEDPos[Field [Row][Col]]=0;
                                                                         UpdateLEDs(); 
                                                                         WaitMS(50);
                                                                        }
    
                                      }
}

void ClearPlayer(){
    //Clears the Playerfield
    for (int Col = 0; Col <= 4; Col++) {LEDPos[Player [Col]]=0;}
     
}
