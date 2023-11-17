
byte DFDataFile[] = {0x7E,0xFF,0x06,0x0F,0x00,0x01,0x00,0xEF}; // Dataset to send to the DF Mini player 
int FolderSet=1;
//  https://ttsmp3.com/

void PlayVoice(int Select){
  
  DFDataFile[3] = (0x0F);
  DFDataFile[5] = (FolderSet);
  DFDataFile[6] = (Select);
  SendData();  
}


void VolumeVoice(int Select){
  
  DFDataFile[3] = (0x06); 
  DFDataFile[6] = (Select);
  SendData();  
}

void ResetVoice(){
  
  DFDataFile[3] = (0x0C);
  SendData();  
}

void SendData(){
   // Send Data to DF mini Sound module
  for (int i = 0; i <= 7; i++) {
                                Serial.write(DFDataFile[i]); 
                               }
                                delay(1000);
}



void setup() {
  Serial.begin(9600);
  pinMode(11,INPUT);
  pinMode(13,OUTPUT);
  PlayVoice(3);
}

void loop() {
  
  if(digitalRead(11)==0) digitalWrite(13,HIGH); else digitalWrite(13,LOW);
  
}
