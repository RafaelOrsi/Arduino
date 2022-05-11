

int tecla = 0;

void setup(){
  //Ativando o serial monitor que exibirá os valores lidos no sensor.
  Serial.begin(9600);
  
  //Definindo pinos digitais de saída.
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
 
}

void loop(){
   tecla = Serial.read();
   Serial.print("Valor lido");
   Serial.println(tecla,DEC);
   
   if (tecla == 97)  {digitalWrite(1,HIGH);}// ativando pela tecla a
   
   if (tecla == 115) {digitalWrite(2,HIGH); } // ativando pela tecla s
   
   if (tecla == 100) {digitalWrite(3,HIGH); } // ativando pela tecla d
   
   if (tecla == 32) // ativando pela tecla space
   {
   digitalWrite(1,LOW);
   digitalWrite(2,LOW); 
   digitalWrite(3,LOW);
     }
}
 
  
 
