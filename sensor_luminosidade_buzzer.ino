/*
Projeto Arduino sensor de luz com saida de leds.
Por Jota
----------------------------------------
--=<| www.ComoFazerAsCoisas.com.br |>=--
----------------------------------------
*/

int sensor = 0;      //Pino analógico em que o sensor está conectado.
int valorSensor = 0; //variável usada para ler o valor do sensor em tempo real.

const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;

//Função setup, executado uma vez ao ligar o Arduino.
void setup(){
  //Ativando o serial monitor que exibirá os valores lidos no sensor.
  Serial.begin(9600);
  
  //Definindo pinos digitais dos leds como de saída.
  pinMode(ledVerde,OUTPUT);
  pinMode(ledAmarelo,OUTPUT);
  pinMode(ledVermelho,OUTPUT);
}

//Função loop, executado enquanto o Arduino estiver ligado.
void loop(){
  
  //Lendo o valor do sensor.
  int valorSensor = analogRead(sensor);
 
  //Os valores da luminosidade podem ser alterados conforme a necessidade.
  //Luminosidade baixa.
  if (valorSensor < 100) {
    apagaLeds();
    tone(ledVermelho,1500);
  }
  
  //Luminosidade média.
  if (valorSensor >= 100 && valorSensor <= 200) {
    apagaLeds();
    digitalWrite(ledAmarelo,HIGH);
  }
  
  //Luminosidade alta.
  if (valorSensor > 200) {
    apagaLeds();
    digitalWrite(ledVerde,HIGH);
  }
  
  //Exibindo o valor do sensor no serial monitor.
  Serial.println(valorSensor);
  
  delay(50); 
}

//Função criada para apagar todos os leds de uma vez.
void apagaLeds() {
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledAmarelo,LOW);
  noTone(ledVermelho);
} 
 
