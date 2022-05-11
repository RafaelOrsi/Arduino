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
   
  if (tecla == 97)// ativando pela tecla a
  {
motorde.setSpeed(255); //Define a velocidade maxima
motorde.run(FORWARD); //Gira o motor sentido horario
  }

  if (tecla == 115) // ativando pela tecla s
  {
motordd.setSpeed(255); //Define a velocidade maxima
motordd.run(FORWARD); //Gira o motor sentido horario
  }
  
  if (tecla == 100) // ativando pela tecla d
  {
motorte.setSpeed(255); //Define a velocidade maxima
motorte.run(FORWARD); //Gira o motor sentido horario
  }
  
  if (tecla == 102) // ativando pela tecla d
  {
motortd.setSpeed(255); //Define a velocidade maxima
motortd.run(FORWARD); //Gira o motor sentido horario
  }

  if (tecla == 113) // ativando pela tecla q
  {
motorde.setSpeed(0);
motorde.run(RELEASE); //Desliga o motor
  }

  if (tecla == 119) // ativando pela tecla w
  {
motordd.setSpeed(0);
motordd.run(RELEASE); //Desliga o motor
  }
  if (tecla == 101) // ativando pela tecla e
  {
motorte.setSpeed(0);
motorte.run(RELEASE); //Desliga o motor
  }
  
  if (tecla == 114) // ativando pela tecla r
  {
motortd.setSpeed(0);
motortd.run(RELEASE); //Desliga o motor
  }
  

}
