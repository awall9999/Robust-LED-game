/*
 * This programm part, is the worst idea that I could have. I´m sorry :)
 * Working on a better solution with deep sleep
 * my time was limited, and hey, it works.
 */


void GoodNight(){
   // clears the screen and waits until you press fire.
   // When fire button pressed > System Reset
   // I know this is a dirty methode, but I'm working on a better one.
   PlayVoice(14); //Play goodbye song
   WaitMS(3000);  //Wait 3seconds
   ClearAll();
   UpdateLEDs();
   
   resetFunc(); // Reset the Arduino.
   
  
  
}
