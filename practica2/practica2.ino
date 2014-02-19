int inBtns[] = {22,24,26,28,30,32,34,36};
int outLeds[] = {38,40,42,44,46,48,50,52};

void calculate1();
void calculate2();
int getValueFromBtns();
void setLedsValue(int a);

void setup(){
  for(int i = 0; i < 8; i++){
    pinMode(inBtns[i], INPUT);
    pinMode(outLeds[i], OUTPUT);
  }  
}

void loop() {
  calculate2();
}

void calculate1(){
  int a = getValueFromBtns();
  a = (5 * a - 4)/2;
  setLedsValue(a);
}

void calculate2(){
  int a = getValueFromBtns();
  setLedsValue(sqrt(a));
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

void setLedsValue(int a){
  for(int i = 0; i < 8; i++){
    digitalWrite(outLeds[i],bitRead(a, i) ? HIGH : LOW);
  }
}


