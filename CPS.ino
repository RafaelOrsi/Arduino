
#include "Ultrasonic.h" //Incluindo biblioteca Ultrasonic.h

Ultrasonic ultrasonic(6,7); //criando objeto ultrasonic e definindo as portas digitais do Trigger - 6 - e Echo - 7

long microsec = 0;
float distanciaCM = 0;

void setup() {
  Serial.begin(9600); //Inicializando o serial monitor
  
  pinMode(3,OUTPUT); //Definindo pino digital 4 como saída.
}

void loop() {  
  microsec = ultrasonic.timing(); //Lendo o sensor
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); //Convertendo a distância em CM

  Serial.print(distanciaCM);
  Serial.println(" cm");
  delay(1000);

  noTone(3); //Desligando o buzzer
   
  
  //Ligando o buzzer quando a distância lida no sensor for maior que 30 cm
  if (distanciaCM > 30) {
    tone(3,1500); 
    delay(1000);
    noTone(3);
    delay(1000);
    
    tone(3,1500); 
    delay(1000);
    noTone(3);
    delay(1000);
    
    tone(3,1500); 
    delay(1000);
    noTone(3);
    delay(1000);
  }
}

