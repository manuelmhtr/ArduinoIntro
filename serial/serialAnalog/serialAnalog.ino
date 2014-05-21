// This thing send the abecedary ASCII code 4ever & ever.

int max_value = 255;
int min_value = 0;
int delay_value = 10;
int sensorPin = A15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int num = analogRead(sensorPin);
  num = num > max_value ? max_value : num; 
  num = num < min_value ? min_value : num; 
  Serial.write(num);
  delay(delay_value);
}
