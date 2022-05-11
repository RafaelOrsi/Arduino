

int tecla = 0;
int ledVerde = 8;
int ledAmarelo = 9;
int ledVermelho = 10;


void setup(){
  //Ativando o serial monitor que exibirá os valores lidos no sensor.
  Serial.begin(9600);
  
  //Definindo pinos digitais dos leds como de saída.
  pinMode(ledVerde,OUTPUT);
  pinMode(ledAmarelo,OUTPUT);
  pinMode(ledVermelho,OUTPUT);
}


void loop(){
   tecla = Serial.read();
   Serial.println(tecla);
A
   if (tecla == 97) // ativando pela tecla a
   {
   digitalWrite(ledVermelho,HIGH);
   }
   
   if (tecla == 115) // ativando pela tecla s
   {
   digitalWrite(ledAmarelo,HIGH);  
   }
   
   if (tecla == 100) // ativando pela tecla d
   {
   digitalWrite(ledVerde,HIGH); 
   }
   
   if (tecla == 32) // ativando pela tecla space
   {
   digitalWrite(ledVerde,LOW);
   digitalWrite(ledAmarelo,LOW); 
   digitalWrite(ledVermelho,LOW);
     }
}
 
  
 
