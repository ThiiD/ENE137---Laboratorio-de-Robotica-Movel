int LED = 13;
float vRefD = 0, vRefE = 0;
int aux = 0;

byte dado[9];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(10);
  Serial.println('a');
  char data = 'b';
  while (data != 'a')
  {
    data = Serial.read();
  }
  pinMode(LED,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (Serial.available() > 8)
  {    
    dado[0] = Serial.read();
    if(dado[0] == 1)
    {      
      for(int i=1; i<9; i++)
      {
        dado[i] = Serial.read();
      }      
      vRefD = *(float *)&dado[1];
      vRefE = *(float *)&dado[5];
      if(vRefD == 0.2 && vRefE == 0.2)
      {
        digitalWrite(LED, !digitalRead(LED));
      }
    }
  } 
}
