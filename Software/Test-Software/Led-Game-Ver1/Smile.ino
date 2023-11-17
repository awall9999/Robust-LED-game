// Set the smile result. Line 0-2,State 0-1   

void SmileResult(int Line,int State){
if (State == 0){LEDPos[Smile [Line][0]] = 2;PlayVoice(1);} // Light up Green Smiley at position x 
if (State == 1){LEDPos[Smile [Line][1]] = 1;PlayVoice(1);} // Light up Red Smiley at position x
UpdateLEDs();  
}
