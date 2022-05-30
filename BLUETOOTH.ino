void setup() {  

  Serial.begin(9600);
  pinMode(5,OUTPUT);    
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);  
}

void loop() {  

  char c = Serial.read();
  if(c == '1') digitalWrite(5,HIGH);
  if(c == '2') digitalWrite(6,HIGH);
  if(c == '3') digitalWrite(7,HIGH);
    
  if(c == 'A') digitalWrite(5,LOW);
  if(c == 'B') digitalWrite(6,LOW);
  if(c == 'C') digitalWrite(7,LOW);
  
  delay(1000);   

}
 
