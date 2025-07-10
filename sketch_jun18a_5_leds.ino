
int led01=9;
int led02=10;
int led03=11;
int led04=12;
int led05=13;



void setup() {
pinMode(led01,OUTPUT);
pinMode(led02,OUTPUT);
pinMode(led03,OUTPUT);
pinMode(led04,OUTPUT);
pinMode(led05,OUTPUT);

}

void loop() {

  digitalWrite(led01,1);
  digitalWrite(led02,1);
  digitalWrite(led03,1);
  digitalWrite(led04,1);
  digitalWrite(led05,1);
  delay(3000);
  digitalWrite(led01,0);
  digitalWrite(led02,0);
  digitalWrite(led03,0);
  digitalWrite(led04,0);
  digitalWrite(led05,0);
  delay(2000);
  // put your main code here, to run repeatedly:

}

