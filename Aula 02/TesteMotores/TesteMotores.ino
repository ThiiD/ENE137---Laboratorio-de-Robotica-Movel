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
  analogWrite(PWMA,MTA);
  analogWrite(PWMB,MTB);
  int dado;
  if(Serial.available()>0)
  {
    dado = Serial.read();
  }
  switch (dado)
  {
  case 'a':
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    MTA = 20;
    MTB = 20;
    break;
  case 'b':
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
