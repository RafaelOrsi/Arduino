
//Incluindo biblioteca Ultrasonic.h
#include "Ultrasonic.h"

//criando objeto ultrasonic e definindo as portas digitais do Trigger - 6 - e Echo - 7
Ultrasonic ultrasonic(12,13);

long microsec = 0;
float distanciaCM = 0;

void setup() {
  Serial.begin(9600); //Inicializando o serial monitor
  
  pinMode(4,OUTPUT); //Definindo pino digital 4 como saída.
  pinMode(5,OUTPUT); //Definindo pino digital 5 como saída.
  pinMode(6,OUTPUT); //Definindo pino digital 6 como saída.
  pinMode(7,OUTPUT); //Definindo pino digital 7 como saída.
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
  
  //Apagando os leds e desligando o buzzer
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);  
  digitalWrite(5,LOW);
  noTone(4);
   
  
  //Acendendo o led adequado para a distância lida no sensor
  if (distanciaCM > 50) {
    digitalWrite(7,HIGH);  
  }
  
  if (distanciaCM <=50 and distanciaCM >= 20) {
    digitalWrite(6,HIGH); 
  } 
  
  if (distanciaCM <= 20 and distanciaCM >= 10) {
    tone(4,1500);
    digitalWrite(5,HIGH);
    delay(500);
  }
    if (distanciaCM < 10) {
    tone(4,1500);
    digitalWrite(5,HIGH);
    delay(50);
    noTone(4);
    digitalWrite(5,LOW);
    delay(50);
    tone(4,1500);
    digitalWrite(5,HIGH);
    delay(50);
    noTone(4);
    digitalWrite(5,LOW);
    delay(50);
    tone(4,1500);
    digitalWrite(5,HIGH);
    delay(50);
    noTone(4);
    digitalWrite(5,LOW);
    delay(50);
    tone(4,1500);
    digitalWrite(5,HIGH);
    delay(50);
    noTone(4);
    digitalWrite(5,LOW);
    delay(50);
    tone(4,1500);
    digitalWrite(5,HIGH);
    delay(50);
    noTone(4);
    digitalWrite(5,LOW);
    delay(50);
  }
}
