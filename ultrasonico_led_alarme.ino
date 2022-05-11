
//Incluindo biblioteca Ultrasonic.h
#include "Ultrasonic.h"

//criando objeto ultrasonic e definindo as portas digitais do Trigger - 6 - e Echo - 7
Ultrasonic ultrasonic(6,7);

long microsec = 0;
float distanciaCM = 0;

void setup() {
  Serial.begin(9600); //Inicializando o serial monitor
  
  pinMode(8,OUTPUT); //Definindo pino digital 8 como saída.
  pinMode(9,OUTPUT); //Definindo pino digital 9 como saída.
  pinMode(13,OUTPUT); //Definindo pino digital 10 como saída.
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
  digitalWrite(8,LOW);  
  digitalWrite(9,LOW);
  noTone(13);
   
  
  //Acendendo o led adequado para a distância lida no sensor
  if (distanciaCM > 100) {
    digitalWrite(8,HIGH);  
  }
  
  if (distanciaCM <=100) {
    tone(13,1500);
    digitalWrite(9,HIGH);
    delay(500);
  }
}
