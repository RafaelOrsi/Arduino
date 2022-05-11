
//Incluindo biblioteca Ultrasonic.h
#include "Ultrasonic.h"

//criando objeto ultrasonic e definindo as portas digitais do Trigger - 6 - e Echo - 7
Ultrasonic ultrasonic(12,13);

int potenciometro=A0; //Declarando Sensor LDR
int velocidade=0; //Coeficiente de luminosidade do LDR

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

  /*Serial.print(distanciaCM);
  Serial.println(" cm");
  delay(1000);*/
}


//Método que centraliza o controle de acendimento dos leds.
void ledDistancia() {
  
  //Apagando os leds e desligando o buzzer
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);  
  digitalWrite(5,LOW);
  noTone(4);
   
  velocidade = (analogRead(potenciometro)*5);
if (velocidade <= 1000)
{
digitalWrite(5,HIGH);
if (distanciaCM < 50) {
   tone(4,1500);
   delay(1000);
}
}

else
{
  
  //Acendendo o led adequado para a distância lida no sensor
  if (distanciaCM > 50) {
    digitalWrite(7,HIGH);
  delay(200);  
  }
  
  if (distanciaCM <=50 and distanciaCM >= 20) {
    digitalWrite(6,HIGH);
   delay(200);  
  } 
  
  if (distanciaCM < 20 ) {
    tone(4,1500);
    digitalWrite(5,HIGH);
    delay(500);
  }

}
}
