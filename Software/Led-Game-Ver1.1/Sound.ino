void PlayVoice(int Select){
  
  DFDataFile[3] = (0x0F);
  DFDataFile[5] = (FolderSet);
  DFDataFile[6] = (Select);
  SendData();
  for (int Wait = 0; Wait <= 30; Wait++){
                                         CheckButtons();
                                         WaitMS(10);
                                          }  
  
}


void VolumeVoice(int Select){
  // set volume funktion
  DFDataFile[3] = (0x06); 
  DFDataFile[6] = (Select);
  SendData();  
}

void ResetVoice(){
  // reset DFmini funktion
  DFDataFile[3] = (0x0C);
  SendData();  
}

void SendData(){
   // Send Data to DF mini Sound module
  for (int i = 0; i <= 7; i++) {
                                Serial.write(DFDataFile[i]); 
                               }
                                
}
