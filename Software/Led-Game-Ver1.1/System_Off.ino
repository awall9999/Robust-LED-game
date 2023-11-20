void GoodNight(){
   // clears the screen and waits until you press fire.
   // When fire button pressed > System Reset
   // I know this is a dirty methode, but I'm working on a better one.
   PlayVoice(14);
   ClearAll();
   UpdateLEDs();
   do{
    
   }while (digitalRead(FireOn)!=1);
   tone(Piezo,1500,40);
   WaitMS(50);
   resetFunc();
   
  
  
}
