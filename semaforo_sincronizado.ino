//Projeto Arduino 2 sinais de trânsito sincronizados
//por www.comofazerascoisas.com.br

//O método setup é executado apenas uma vez, 
//quando o arduino é ligado
void setup() {  
  //definindo os pinos digitais 5, 6, 7, 8, 9 e 10 
  //como pinos de saída.
  pinMode(5,OUTPUT);    
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);  
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

//o método loop é executado repetidamente enquanto o arduino
//estiver ligado.
void loop() {    
  digitalWrite(5,LOW);   //apaga o led vermelho  (sinal 1)
  digitalWrite(7,HIGH);  //acende o led verde    (sinal 1)
  digitalWrite(8,HIGH);  //acende o led vermelho (sinal 2)
  delay(4000);           //espera 4 segundos
  digitalWrite(7,LOW);   //apaga o led verde     (sinal 1)        
  
  digitalWrite(6,HIGH);  //acende o led amarelo  (sinal 1)
  delay(2000);           //espera 2 segundos
  digitalWrite(6,LOW);   //apaga o led amarelo   (sinal 1)
  
  digitalWrite(5,HIGH);  //acende o led vermelho (sinal 1)
  digitalWrite(8,LOW);   //apaga o led vermelho  (sinal 2)
  digitalWrite(10,HIGH); //acende o led verde    (sinal 2)
  delay(4000);           //espera 4 segundos
  digitalWrite(10,LOW);  //apaga o led verde     (sinal 2)
  
  digitalWrite(9,HIGH);  //acende o led amarelo  (sinal 2)
  delay(2000);           //espera 2 segundos
  digitalWrite(9,LOW);   //apaga o led amarelo   (sinal 2)  
}
 
