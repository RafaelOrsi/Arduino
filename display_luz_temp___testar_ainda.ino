/*
Projeto Arduino com LCD, sensor de luz e de temperatura. 
Por Jota
----------------------------------------
--=<| www.ComoFazerAsCoisas.com.br |>=--
----------------------------------------
*/
#include "LiquidCrystal.h"
#include "Limits.h"
const int sensorLuz  = A0; //Pino analógico em que o sensor de luz está conectado.
const int sensorTemp = A1; //Pino analógico em que o sensor de temperatura está conectado.

int valorSensorLuz  = A0;  //variável usada para ler o valor do sensor de luz.
int valorSensorTemp = 0;  //variável usada para ler o valor do sensor de temperatura.
int menorValorTemp  = INT_MAX;  //Variável usada para armazenar o menor valor da temperatura.

//Criando um objeto da classe LiquidCrystal e 
//inicializando com os pinos da interface.
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

void setup() {
  //Inicializando o LCD e informando o tamanho de 16 colunas e 2 linhas
  //que é o tamanho do LCD JHD 162A usado neste projeto.
  lcd.begin(16, 2);    
}

void loop() { 
  //Lendo o valor do sensor de luz
  valorSensorLuz  = analogRead(sensorLuz);
  
  //Para evitar as grandes variações de leitura do componente 
  //LM35 são feitas 8 leitura é o menor valor lido prevalece.  
  menorValorTemp  = INT_MAX; //Inicializando a variável com o maior valor int possível
  for (int i = 1; i <= 8; i++) {
    //Lendo o valor do sensor de temperatura.
    valorSensorTemp = analogRead(sensorTemp);   
 
    //Transformando valor lido no sensor de temperatura em graus celsius aproximados.
    valorSensorTemp *= 0.54 ; 
    
    //Mantendo sempre a menor temperatura lida
    if (valorSensorTemp < menorValorTemp) {
      menorValorTemp = valorSensorTemp;
    }
   
   delay(150); 
  }   
    
  //Exibindo valor da leitura do sensor de temperatura no display LCD.
  lcd.clear();  //limpa o display do LCD.     
  lcd.print("Temp: ");  //imprime a string no display do LCD.                 
  lcd.print(menorValorTemp);
  lcd.write(B11011111); //Simbolo de graus celsius
  lcd.print("C");
  
  //Exibindo valor da leitura do sensor de luz no display LCD.
  lcd.setCursor(0,1);  //posiciona o cursor na coluna 0 linha 1 do LCD.
  lcd.print("Luz: ");  //imprime a string no display do LCD.       
  lcd.print(valorSensorLuz);  
   
  delay(2000); //aguarda 2 segundos
}
