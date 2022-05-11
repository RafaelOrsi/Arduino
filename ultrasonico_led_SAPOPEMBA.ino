#include <Ultrasonic.h>

/*
Projeto Arduino - Arduino com sensor de proximidade ultrasonico HHC-SRO4
*/

//Incluindo biblioteca Ultrasonic.h
//#include "Ultrasonic.h"

//criando objeto ultrasonic e definindo as portas digitais do Trigger - 3 - e Echo - 4
Ultrasonic ultrasonic(3,4);

//Declaração das constantes referentes aos pinos digitais.
const int led9 = 13;
const int led8 = 12;
const int led7 = 11;
const int led6 = 10;
const int led5 = 9;
const int led4 = 8;
const int led3 = 7;
const int led2 = 6;
const int led1 = 5;


long microsec = 0;
float distanciaCM = 0;

void setup() {
  Serial.begin(9600); //Inicializando o serial monitor
  
  pinMode(led9,OUTPUT); //Definindo pino digital 13 como saída.
  pinMode(led8,OUTPUT); //Definindo pino digital 12 como saída.
  pinMode(led7,OUTPUT); //Definindo pino digital 11 como saída.
  pinMode(led6,OUTPUT); //Definindo pino digital 10 como saída.
  pinMode(led5,OUTPUT); //Definindo pino digital 9 como saída.
  pinMode(led4,OUTPUT); //Definindo pino digital 8 como saída.
  pinMode(led3,OUTPUT); //Definindo pino digital 7 como saída.
  pinMode(led2,OUTPUT); //Definindo pino digital 6 como saída.
  pinMode(led1,OUTPUT); //Definindo pino digital 5 como saída.
}

void loop() {  
  microsec = ultrasonic.timing(); //Lendo o sensor
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); //Convertendo a distância em CM

  ledDistancia();

  Serial.print(distanciaCM);
  Serial.println(" cm");
  delay(1000);
}

//Método que centraliza o controle de acendimento dos leds.
void ledDistancia() {
  
  //Apagando todos os leds
  digitalWrite(led9,LOW);  
  digitalWrite(led8,LOW);
  digitalWrite(led7,LOW);
  digitalWrite(led6,LOW);  
  digitalWrite(led5,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led3,LOW);  
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
  
  //Acendendo o led adequado para a distância lida no sensor
  if (distanciaCM <=100) {
    digitalWrite(led1,HIGH);  
  }
  
  if (distanciaCM <=80) {//and distanciaCM >= 10) {
    digitalWrite(led2,HIGH);
  }
  
  if (distanciaCM <=70) {
    digitalWrite(led3,HIGH);
  }
  
  if (distanciaCM <=60) {
    digitalWrite(led4,HIGH);
  }
  
  if (distanciaCM <=50) {
    digitalWrite(led5,HIGH);
  }
  
    if (distanciaCM <=40) {
    digitalWrite(led6,HIGH);
  }
  
    if (distanciaCM <=30) {
    digitalWrite(led7,HIGH);
  }
  
    if (distanciaCM <=20) {
    digitalWrite(led8,HIGH);
  }
  
    if (distanciaCM <=10) {
    digitalWrite(led9,HIGH);
  }
  
}
