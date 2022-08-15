#include <PololuWheelEncoders.h>

PololuWheelEncoders encoders;

int PWMA = 5;
int AIN1 = 7;
int AIN2 = 6;
int STBY = 8;
int BIN1 = 9;
int BIN2 = 10;
int PWMB = 11;
int MTA = 0, MTB = 0;
int aux = 0;
float vRefD = 0, vRefE = 0;
float tempo = 0;
float dT = 100;
int esquerdo, direito;
float velE, velD;
float kiE = 779.6, kpE = 38.98;
float kiD = 763.84, kpD = 38.19;
float erroE = 0, erroD = 0;
float pE = 0, pD = 0;
float iE = 0, iD = 0;
float uE = 0, uD = 0;
int flag_e = 0, flag_d = 0;

byte dado[9];
// MOTOR DIREITO -> AIN
// MOTOR ESQUERDO -> BIN


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
  delay(10);
  Serial.println('a');
  char data = 'b';
  while (data != 'a'){
    data = Serial.read();
  }
}

void loop() {
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

      //--------------------------------------------------
      // Verifica o sentido de rotação do motor direito
      if (vRefD > 0)
      {
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
        flag_d = 0;
      }
      else if (vRefD = 0)
      {
        uD = 0;
        iD = 0;
      }
      else
      {
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
        vRefD = -1 * vRefD;
        flag_d = 1;
      }
      
      //--------------------------------------------------
      // Verifica o sentido de rotação do motor esquerdo
      if (vRefE > 0)
      {
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);
        flag_e = 0;
      }
      else if(vRefE = 0)
      {
        uE = 0;
        iE = 0;
      }
      else
      {
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
        vRefE = -1 * vRefE;
        flag_e = 1;
      }
      //--------------------------------------------------
    }

  }

    if (millis() - tempo >= dT)
  {
    tempo = millis();
//     Pega  nummero de pulsos do encoder
    esquerdo = encoders.getCountsAndResetM1();
    direito = -1 * encoders.getCountsAndResetM2();

    if(flag_e == 1)
    {
      esquerdo = -1 * esquerdo;  
    }

    if(flag_d == 1)
    {
      direito = -1 * direito;  
    }
 
    // Calculo de velocidade
    velE = ((M_PI * 0.042) * (esquerdo/48.0))/0.1;
    velD = ((M_PI * 0.042) * (direito /48.0))/0.1;


    // Calculo do Erro
    erroE = vRefE - velE;
    erroD = vRefD - velD;

    // Acao de controle para o motor esquerdo
    iE = iE + erroE * kiE * 0.1;
    pE = erroE * kpE;
    uE = pE + iE;
    if (uE > 255)
    {
      uE = 255;
    }
    if(uE < 0)
    {
      uE = 0;  
    }
    analogWrite(PWMB, uE);    

    // Acao de controle para o direito
    iD = iD + erroD * kiD * 0.1;
    pD = erroD * kpD;
    uD = pD + iD;
    if (uD > 255)
    {
      uD = 255;
    }
    if(uD < 0)
    {
      uD = 0;  
    }
    analogWrite(PWMA, uD);
  }  
}
