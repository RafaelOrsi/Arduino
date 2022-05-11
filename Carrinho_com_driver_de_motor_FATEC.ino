#include <AFMotor.h>
 
AF_DCMotor motorde(1); //Seleciona o motor 1
AF_DCMotor motordd(4); //Seleciona o motor 2
AF_DCMotor motorte(2); //Seleciona o motor 3
AF_DCMotor motortd(3); //Seleciona o motor 4

int tecla = 0;
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
   tecla = Serial.read();
   Serial.print("Valor lido");
   Serial.println(tecla,DEC);
   
  if (tecla == 70)// ativando pela tecla F
  {
motorde.setSpeed(255); //Define a velocidade maxima
motorde.run(FORWARD); //Gira o motor sentido horario
motordd.setSpeed(255); //Define a velocidade maxima
motordd.run(FORWARD); //Gira o motor sentido horario
motorte.setSpeed(255); //Define a velocidade maxima
motorte.run(FORWARD); //Gira o motor sentido horario
motortd.setSpeed(255); //Define a velocidade maxima
motortd.run(FORWARD); //Gira o motor sentido horario
delay(500);
  }

  else if (tecla == 66) // ativando pela tecla B
  {
motorde.setSpeed(255); //Define a velocidade maxima
motorde.run(BACKWARD); //Gira o motor sentido horario
motordd.setSpeed(255); //Define a velocidade maxima
motordd.run(BACKWARD); //Gira o motor sentido horario
motorte.setSpeed(255); //Define a velocidade maxima
motorte.run(BACKWARD); //Gira o motor sentido horario
motortd.setSpeed(255); //Define a velocidade maxima
motortd.run(BACKWARD); //Gira o motor sentido horario
delay(500);
  }
  
  else if (tecla == 82) // ativando pela tecla R
  {
motortd.setSpeed(255); //Define a velocidade maxima
motortd.run(FORWARD); //Gira o motor sentido horario
motorde.setSpeed(255); //Define a velocidade maxima
motorde.run(BACKWARD); //Gira o motor sentido horario
  }
  
  else if (tecla == 76) // ativando pela tecla L
  {
motorte.setSpeed(255); //Define a velocidade maxima
motorte.run(FORWARD); //Gira o motor sentido horario
motordd.setSpeed(255); //Define a velocidade maxima
motordd.run(BACKWARD); //Gira o motor sentido horario
  }

  else if (tecla == 83) // ativando pela tecla S
  {
motorde.setSpeed(0);
motorde.run(RELEASE); //Desliga o motor
motordd.setSpeed(0);
motordd.run(RELEASE); //Desliga o motor
motorte.setSpeed(0);
motorte.run(RELEASE); //Desliga o motor
motortd.setSpeed(0);
motortd.run(RELEASE); //Desliga o motor
  }
  

}
