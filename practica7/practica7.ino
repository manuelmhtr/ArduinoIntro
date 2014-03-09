int inBtns[] = {22,24,26,28,30,32,34,36};
int outLeds[] = {38,40,42,44,46,48,50,52,53};

bool activeAlarm = false;
void checkAlarm();
void setAlarm(bool active);

void setup(){
  for(int i = 0; i < 8; i++){
    pinMode(inBtns[i], INPUT);
    pinMode(outLeds[i], OUTPUT);
  }  
}


void loop() {
  checkAlarm();
}

void checkAlarm(){
  if(digitalRead(inBtns[7])) activeAlarm = false;
  if(!digitalRead(inBtns[7]) && (!digitalRead(inBtns[0]) || !digitalRead(inBtns[1]) || !digitalRead(inBtns[2]) || !digitalRead(inBtns[3]))){
    activeAlarm = true;
  }
  setAlarm(activeAlarm);
}

void setAlarm(bool active){
  digitalWrite(outLeds[0], active ? HIGH : LOW);
  digitalWrite(outLeds[1], active ? HIGH : LOW);
  digitalWrite(outLeds[8], active ? HIGH : LOW);
}
