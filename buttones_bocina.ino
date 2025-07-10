#include<GFButton.h>
int boton_on = 2;
int boton_off = 3;
int boton_E = 4;
int boton_A =  5;
int led01 = 6;
int led02 = 7;
int bocinaE = 8;
GFButton botonON(boton_on);
GFButton botonOFF(boton_off);
GFButton botonON_bocina(boton_E);
GFButton botonOFF_bocina(boton_A);
void setup() {
  // put your setup code here, to run once:
  pinMode(boton_on,INPUT);
  pinMode(boton_off,INPUT);
  pinMode(boton_E,INPUT);
  pinMode(boton_A,INPUT);
  pinMode(led01,OUTPUT);
  pinMode(led02,OUTPUT);
  pinMode(bocinaE,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(not botonON.isPressed()){
    digitalWrite(led01,1);
    digitalWrite(led02,1);
  }
  if(not botonOFF.isPressed()){
    digitalWrite(led01,0);
    digitalWrite(led02,0);
  }
  if(not botonON_bocina.isPressed()){
    tone(bocinaE,1200);
  }
  if(not botonOFF_bocina.isPressed()){
    noTone(bocinaE);
  }
}