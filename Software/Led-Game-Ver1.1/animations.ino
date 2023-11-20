void LedTest(){
 // RGB LED Test
 for (int LedColorTest = 3; LedColorTest >= 0; LedColorTest--){
                                        for (int i = 0; i <= LN; i++) {LEDPos[i]=LedColorTest;}
                                        UpdateLEDs();
                                        WaitMS(500);
                                        }
}


void LedAniWinner01(){
  // colorfull Led with Winnersound. Animation duration depends on length of the soundfile
  int Counter = 0;
  PlayVoice(3); // Play Applause File
  //WaitMS(300); // Give the Busy Pin a chance to rise
  do{             
  LEDPos[Field [random(4)][random(5)]]=random(1,6);
  UpdateLEDs();
  WaitMS(10);
  Counter++;
  
  } while (digitalRead(Busy) != 1); // Repeat until the Soundfile is finished                                     

ClearFieldSlow();
}

void LedAniLooser01(){
  // RED Led with Loosersound. Animation duration depends on length of the soundfile
  int Counter = 0;
  PlayVoice(12); // Play Fail File
  do{             
  LEDPos[Field [random(4)][random(5)]]=1;
  UpdateLEDs();
  WaitMS(10);
  Counter++;
  
  } while (digitalRead(Busy) != 1); // Repeat until the Soundfile is finished                                     

ClearFieldSlow();
}


void GameStartupAni(){
  //Game StartCountdown
ClearPlayer(); 
for (int row = 0; row <= 2; row++){for (int Led = 0; Led <= 4; Led++){
                                                                      LEDPos[Field [row][Led]]=1;
                                                                      }
                                   UpdateLEDs();
                                   PlayVoice(9);
                                   WaitMS(700);
                                   for (int Led = 0; Led <= 4; Led++){
                                                                      LEDPos[Field [row][Led]]=0;
                                                                      }
                                  }
for (int Led = 0; Led <= 4; Led++){LEDPos[Field [3][Led]]=2;
                                   }
                                   UpdateLEDs();
                                   PlayVoice(10);
                                   WaitMS(1000);
                                   for (int Led = 0; Led <= 4; Led++){
                                                                      LEDPos[Field [3][Led]]=0;
                                                                      }
  
}
























// test playground
void LedAni01(){
                for (int LedAni = 0; LedAni <= 150; LedAni++){
                                                            LEDPos[Field [random(4)][random(5)]]=random(1,6);
                                                            UpdateLEDs();
                                                            WaitMS(10);
                                                            }

ClearFieldSlow();
}


void LedAni02(){
  //PlayVoice(1);
ClearPlayer(); 
for (int row = 0; row <= 3; row++){for (int Led = 0; Led <= 4; Led++){
                                                                      LEDPos[Field [row][Led]]=1;
                                                                      }
                                   UpdateLEDs();
                                   WaitMS(1000);
                                   for (int Led = 0; Led <= 4; Led++){
                                                                      LEDPos[Field [row][Led]]=0;
                                                                      }
                                  }

  
}
