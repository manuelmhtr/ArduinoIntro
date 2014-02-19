int inBtns[] = {22,24,26,28,30,32,34,36};
int outLeds[] = {38,40,42,44,46,48,50,52};

int sensorPin = A15;
int lowTemp = 43;
int highTemp = 84;

void setLeds();
int getValueFromBtns();

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
  int a = analogRead(sensorPin);
    digitalWrite(38,LOW);
    digitalWrite(40,LOW);
  if(a >= highTemp){
    digitalWrite(40,HIGH);
  }else if(a <= lowTemp){
    digitalWrite(38,HIGH);
  }
}
