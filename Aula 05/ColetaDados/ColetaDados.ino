#include <PololuWheelEncoders.h>

PololuWheelEncoders encoders;
long tempo = 0;
int dT = 100;
int esquerdo, direito;



int PWMA = 5;
int AIN1 = 7;
int AIN2 = 6;
int STBY = 8;
int BIN1 = 9;
int BIN2 = 10;
int PWMB = 11;
int MTA = 0, MTB = 0;
int dado = 0;
int aux = 0;
void setup() {
  // put your setup code here, to run once:

  encoders.init(16,17,18,19);
  
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  digitalWrite(STBY, HIGH);

  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);

  Serial.begin(9600);
  delay(10);
  Serial.println('a');
  char data = 'b';
  while (data != 'a'){
    data = Serial.read();
  }
}


void loop() {
 // put your main code here, to run repeatedly:
  
  
//
//  if (Serial.available() > 0)
//  {

    aux = 1;
    
    if (millis() - tempo >= dT)
   {
      tempo = millis();
     if(aux==1)   
      {        
        dado = Serial.read();
        esquerdo = encoders.getCountsAndResetM1();
        direito = encoders.getCountsAndResetM2();
        Serial.println(dado);
        Serial.println( 600*esquerdo/48);
        Serial.println( 600*direito/48);
        MTA = dado;
        MTB = dado;
        analogWrite(PWMA, MTA);
        analogWrite(PWMB, MTB);
      }
      
    }
     
   }
//}
