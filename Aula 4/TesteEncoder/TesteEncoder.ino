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

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(PWMA, MTA);
  analogWrite(PWMB, MTB);

  if (Serial.available() > 0)
  {
    int dado = Serial.read();

    switch (dado)
    {
      case 'w':

        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);
        MTA = 120;
        MTB = 120;
        break;

      case 's':
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
        MTA = 120;
        MTB = 120;
        break;

      case 'a':
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
        MTA = 120;
        MTB = 120;
        break;

      case 'd':
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);
        MTA = 120;
        MTB = 120;
        break;

        case 'c':
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, HIGH);
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, HIGH);
        MTA = 120;
        MTB = 120;
        break;


    }

  }
  if (millis() - tempo >= dT)
    {
      tempo = millis();
      // leitura do encoder
      esquerdo = encoders.getCountsAndResetM1();
      direito = encoders.getCountsAndResetM2();
      Serial.print(esquerdo);
      Serial.print(";");
      Serial.println(direito);
    }
}
