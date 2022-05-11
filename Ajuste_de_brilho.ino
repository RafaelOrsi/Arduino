int i;

void setup() {
  pinMode(9,OUTPUT);
}
void loop(){
 for(i=0;i<=255;i++){
  analogWrite(9,i);
 delay(20);
 }
 delay(2000);
 for(i=0;i>=255;i--){
  analogWrite(9,i);
 delay(20);
 }
 }
