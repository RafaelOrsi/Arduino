/*
Projeto Arduino - Arduino com sensor de proximidade ultrasonico HHC-SRO4
Por Jota
----------------------------------------
--=<| www.ComoFazerAsCoisas.com.br |>=--
----------------------------------------
*/
//Incluindo biblioteca Ultrasonic.h
#include "Ultrasonic.h"

//criando objeto ultrasonic e definindo as portas digitais do Trigger - 6 - e Echo - 7
Ultrasonic ultrasonic(6,7);

//Declaração das constantes referentes aos pinos digitais.
const int ledVerde = 13;
const int ledAmarelo = 12;
const int ledVermelho = 11;

long microsec = 0;
float distanciaCM = 0;

void setup() {
  Serial.begin(9600); //Inicializando o serial monitor
  
  pinMode(ledVerde,OUTPUT); //Definindo pino digital 13 como saída.
  pinMode(ledAmarelo,OUTPUT); //Definindo pino digital 12 como saída.
  pinMode(ledVermelho,OUTPUT); //Definindo pino digital 11 como saída.
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
  digitalWrite(ledVerde,LOW);  
  digitalWrite(ledAmarelo,LOW);
  digitalWrite(ledVermelho,LOW);
  
  //Acendendo o led adequado para a distância lida no sensor
  if (distanciaCM > 20) {
    digitalWrite(ledVerde,HIGH);  
  }
  
  if (distanciaCM <=20 and distanciaCM >= 10) {
    digitalWrite(ledAmarelo,HIGH);
  }
  
  if (distanciaCM < 10) {
    digitalWrite(ledVermelho,HIGH);
  }
}
