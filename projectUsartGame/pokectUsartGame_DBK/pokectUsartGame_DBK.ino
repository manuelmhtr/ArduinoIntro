byte incomingByte0;      // a variable to read incoming serial data into
byte incomingByte1;
byte letter0;      // a variable to read incoming serial data into
byte letter1;
void setup()
{
  // initialize serial communication:
  Serial.begin(9600);
  Serial1.begin(9600);
}
void loop() 
{
  // see if there's incoming serial data:
  if (Serial1.available() > 0)
  {
    letter1 = incomingByte1 = Serial1.read();
  }
  if (Serial.available() > 0)
  {
    letter0 = incomingByte0 = Serial.read();
    if(incomingByte0)Serial1.write(incomingByte0);
  }
   
  if(letter0 && letter1){
    if(letter0 == letter1)
    {
      Serial.write ("\nCorrecto!");
    }else{
      Serial.write ("\nIncorrecto!");
    }
    letter0 = 0;
    letter1 = 0;
  }else if(incomingByte0){
    Serial.write ("\nEscribiste: ");
    Serial.write (letter0);
    Serial.write (" (Esperando oponente)");
  }else if(incomingByte1){
    Serial.write ("\nTu oponente espera que escribas algo...");
  }
  incomingByte0 = 0;
  incomingByte1 = 0;
}
