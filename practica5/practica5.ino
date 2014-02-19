int inBtns[] = {22,24,26,28,30,32,34,36};
int pushBtn = 49;
int outLeds[] = {38,40,42,44,46,48,50,52};
int valuesBcd[] = {126,48,109,121,51,91,95,112,127,115};

bool bitHigh = false;
int value = 0;
void countLoop();
void setLedsValue(int a);

void setup(){
  pinMode(pushBtn, INPUT);
  for(int i = 0; i < 8; i++){
    pinMode(inBtns[i], INPUT);
    pinMode(outLeds[i], OUTPUT);
  }
}


void loop() {
  countLoop();
  setLeds();
}

void countLoop(){
  if(!digitalRead(pushBtn) && bitHigh){
    value = (value + 1) % 100;
    bitHigh = false;
  }else if(digitalRead(pushBtn)){
    bitHigh = true;
  }
}

void setLeds(){
  int dec = value / 10;
  setLedsValue(valuesBcd[dec]);
  delay(5);
  setLedsValue(valuesBcd[value % 10] + 128);
  delay(5);
}

void setLedsValue(int a){
  for(int i = 0; i < 8; i++){
    digitalWrite(outLeds[i],bitRead(a, i) ? HIGH : LOW);
  }
}



