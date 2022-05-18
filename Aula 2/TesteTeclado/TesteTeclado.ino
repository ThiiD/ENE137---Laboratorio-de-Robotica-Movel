const int PWMA = 5, AIN1 = 6, AIN2 = 7, STBY = 8, BIN1 = 9, BIN2 = 10, PWMB = 11;

int MTA = 0, MTB = 0;

void setup() {
  // put your setup code here, to run once:
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
  // put your  main code here, to run repeatedly:
  MTA = 0;
  MTB = 0;
  analogWrite(PWMA,MTA);
  analogWrite(PWMB,MTB);
  int dado;
  if(Serial.available()>0)
  {
    dado = Serial.read();
  }
  switch (dado)
  {
  case 'w':
    MTA = 120;
    MTB = 120;
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMA,MTA);
    analogWrite(PWMB,MTB);
    delay(200);
    break;
    
  case 'a':
    MTA = 30;
    MTB = 120;
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMA,MTA);
    analogWrite(PWMB,MTB);
    delay(200);
    break;

  case 'd':
    MTA = 120;
    MTB = 30;
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMA,MTA);
    analogWrite(PWMB,MTB);
    delay(200);
    break;

  case 's':
    MTA = 120;
    MTB = 120;
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMA,MTA);
    analogWrite(PWMB,MTB);
    delay(200);
    break;
  
//  case 'c':
//    digitalWrite(AIN1, HIGH);
//    digitalWrite(AIN2, HIGH);
//    digitalWrite(BIN1, HIGH);
//    digitalWrite(BIN2, HIGH);
//    MTA = 120;
//    MTB = 120;
//    break;
  }
}
