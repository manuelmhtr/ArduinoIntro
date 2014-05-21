int inBtns[] = {32,34,36};
int motors[] = {38,40,42};

int count = 0;

void checkMotorsStates();

void setup(){
  for(int i = 0; i < 3; i++){
    pinMode(inBtns[i], INPUT);
    pinMode(motors[i], OUTPUT);
  }  
}


void loop(){
  checkMotorsStates();
}

void checkMotorsStates(){
  if(digitalRead(inBtns[2])){
    digitalWrite(motors[0], LOW);
    digitalWrite(motors[1], LOW);
    digitalWrite(motors[2], LOW);
    count = 0;
  }else{
    if(digitalRead(inBtns[1])){
      count = count > 0 ? count - 1 : 0;
    }else if(digitalRead(inBtns[0])){
      count = count < 1000 ? count + 1 : 1000;
    }
    digitalWrite(motors[0], count >  0    ? HIGH : LOW);
    digitalWrite(motors[1], count >  500  ? HIGH : LOW);
    digitalWrite(motors[2], count >= 1000 ? HIGH : LOW);
  }
  delay(1);
}
