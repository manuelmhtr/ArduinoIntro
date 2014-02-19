int inBtns[] = {22,24,26,28,30,32,34,36};
int outLeds[] = {38,40,42,44,46,48,50,52};

void switchesSet();

void setup(){
  for(int i = 0; i < 8; i++){
    pinMode(inBtns[i], INPUT);
    pinMode(outLeds[i], OUTPUT);
  }  
}

void loop() {
  switchesSet();
}

void switchesSet(){
  for(int i = 0; i < 8; i++)digitalWrite(outLeds[i], digitalRead(inBtns[i]) ? LOW : HIGH);
}


