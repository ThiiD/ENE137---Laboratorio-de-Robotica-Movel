#include <PololuWheelEncoders.h>
PololuWheelEncoders encoders;

int LED = 13;
float vRefD = 0, vRefE = 0;
float tempo = 0;
float dT = 100;
int esquerdo, direito;
float velE = 0, velD = 0;
float ki = 779.6, kp = 38.98;
float erroE = 0, erroD = 0;
float pE = 0, pD = 0;
float iE = 0, iD = 0;
float uE = 0, uD = 0;

int PWMA = 5;
int AIN1 = 7;
int AIN2 = 6;
int STBY = 8;
int BIN1 = 9;
int BIN2 = 10;
int PWMB = 11;

byte dado[9];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  encoders.init(16, 17, 18, 19);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  digitalWrite(STBY, HIGH);

  delay(10);
  Serial.println('a');
  char data = 'b';
  while (data != 'a')
  {
    data = Serial.read();
  }

}

void loop()
{
  // put your main code here, to run repeatedly:
  if (Serial.available() > 8)
  {
    dado[0] = Serial.read();
    if (dado[0] == 1)
    {
      for (int i = 1; i < 9; i++)
      {
        dado[i] = Serial.read();
      }
      vRefD = *(float *)&dado[1];
      vRefE = *(float *)&dado[5];

      Serial.println(velE);
      Serial.println(velD);
      Serial.println(millis() - tempo);
      

      //--------------------------------------------------
      // Verifica o sentido de rotação do motor direito
      if (vRefD > 0)
      {
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
      }
      else if (vRefD == 0)
      {
        uD = 0;
        iD = 0;
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, HIGH);
      }
      else
      {
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
      }
      
      //--------------------------------------------------
      // Verifica o sentido de rotação do motor esquerdo
      if (vRefE > 0)
      {
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);
      }
      else if(vRefE == 0)
      {
        uE = 0;
        iE = 0;
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, HIGH);
      }
      else
      {
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
      }
      //--------------------------------------------------
    }

  }

    if (millis() - tempo >= dT)
  {
    tempo = millis();
    // Pega  nummero de pulsos do encoder
    esquerdo = encoders.getCountsAndResetM1();
    direito = -1 * encoders.getCountsAndResetM2();
 
    // Calculo de velocidade
    velE = ((M_PI * 0.042) * (esquerdo/48.0));
    velD = ((M_PI * 0.042) * (direito /48.0));

    // Calculo do Erro
    erroE = vRefE - velE;
    erroD = vRefD - velD;

    // Acao de controle para o motor esquerdo
    iE = iE + erroE * ki * 0.1;
    pE = erroE * kp;
    uE = pE + iE;
    if (uE > 255)
    {
      uE = 255;
    }
    analogWrite(PWMB, uE);    

    // Acao de controle para o direito
    iD = iD + erroD * ki * 0.1;
    pD = erroD * kp;
    uD = pD + iD;
    if (uD > 255)
    {
      uD = 255;
    }
    analogWrite(PWMA, uD);
  }  
}
