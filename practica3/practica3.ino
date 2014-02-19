int inBtns[] = {22,24,26,28,30,32,34,36};
int outLeds[] = {38,40,42};

void setLeds();
int getValueFromBtns();
void setLedsValue(int a);

void setup(){
  for(int i = 0; i < 8; i++){
    pinMode(inBtns[i], INPUT);
    pinMode(outLeds[i], OUTPUT);
  }  
}

void loop() {
  setLeds();
}

void setLeds(){
  int a = getValueFromBtns();
  for(int i = 0; i < 3; i++)digitalWrite(outLeds[i],LOW);
  if(a > 50){
    digitalWrite(outLeds[0],HIGH);
  }else if(a == 50){
    digitalWrite(outLeds[1],HIGH);
  }else{
    digitalWrite(outLeds[2],HIGH);
  }
}

int getValueFromBtns(){
  int a = 0;
  for(int i = 0; i < 8; i++){
    if(!digitalRead(inBtns[i])){
      bitSet(a, i);
    }
  }
  return a;
}

