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
  analogWrite(PWMA, MTA);
  analogWrite(PWMB, MTB);

  if (Serial.available() > 0)
  {
    int data = Serial.read();
      switch(data){
        case 30:
          digitalWrite(AIN1, HIGH);
          digitalWrite(AIN2, LOW);
          digitalWrite(BIN1, HIGH);
          digitalWrite(BIN2, LOW);
          MTA = 60;
          MTB = 60;
          break;

        case 31:
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
        MTA = 60;
        MTB = 60;
        break;

      case 29:
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
        MTA = 60;
        MTB = 60;
        break;

      case 28:
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);
        MTA = 60;
        MTB = 60;
        break;

      case 32:
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, HIGH);
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, HIGH);
        MTA = 60;
        MTB = 60;
        break;         
      }   
  }
}
