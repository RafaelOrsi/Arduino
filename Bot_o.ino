/*
Projeto Arduino acendendo e apagando o led com botão.
Por João Paulo - Jota
----------------------------------------
--=<| www.ComoFazerAsCoisas.com.br |>=--
----------------------------------------
*/

//Declaração das constantes
const int led = 8;    //constante led refere-se ao pino digital 8.
const int botao = 2;  //constante botão refere-se ao pino digital 2.

//Declaração da variável que conterá os estados do botão (0 LOW, 1 HIGH).
int estadoBotao = 0;

//Método setup, executado uma vez ao ligar o Arduino.
void setup() {
  pinMode(led,OUTPUT);   //Definindo o pino digital 8 como de saída.
  pinMode(botao,INPUT);  //Definindo o pino digital 2 como pino de entrada. 
}

//Método loop, executado enquanto o Arduino estiver ligado.
void loop() {  
  //Lendo o estado do pino 2, constante botao, e atribuindo 
  //o resultado a variável estadoBotao.
  estadoBotao = digitalRead(botao);          
  
  //Verificando o estado do botão para definir se acenderá ou
  //apagará o led.  
  if (estadoBotao == HIGH) {
    digitalWrite(led,HIGH); //Botão pressionado, acende o led.
  } else {
    digitalWrite(led,LOW);  //Botão não pressionado, apaga o led.    
  }       
}
