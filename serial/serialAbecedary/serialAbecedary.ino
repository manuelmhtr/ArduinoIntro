// This thing send the abecedary ASCII code 4ever & ever.

int data_start = 65;
int data_end = 90;
int delay_value = 10;
int num = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.write(num + data_start);
  delay(delay_value);
  num = (num + 1) % (data_end - data_start + 1);
}
