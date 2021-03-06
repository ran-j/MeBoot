#include <Servo.h>
//ref https://circuitdigest.com/sites/default/files/inlineimages/servo-rotation.gif
//ref http://www.microcontroller-project.com/uploads/2/2/1/5/22159166/4020311_orig.jpg

Servo pataDianteira1;
Servo pataDianteira2;

Servo pataTraseira1;
Servo pataTraseira2;


void setup() {
  pataDianteira1.attach(9);//esquerda
  pataDianteira2.attach(10);//direita
  
  pataTraseira1.attach(11);//direita
  pataTraseira2.attach(3);//esquerda
  
  ResetarPosicao();
  delay(500);
  Serial.begin(9600);//inicia o serial
  
}

void loop(){
  AndarParaFrente();
  
}

void AndarParaFrente(){
  Serial.println("Andando para frente");
 
  MovimentoQuad1(50,50);
  delay(500);
  MovimentoQuad2(50,50);
}


void MovimentoQuad1(int Posi1, int Posi2) {//mover uma perna da frente e outra de trás esquerda
  Serial.println("Movendo lado direito");
   
  pataDianteira1.write(Posi1);
  pataTraseira2.write(Posi2); 
  
  delay(500);
  pataDianteira1.write(0);
  pataTraseira2.write(0); 
}

void MovimentoQuad2(int Posi1, int Posi2) {//mover uma perna da frente e outra de trás direita
  Serial.println("Movendo lado direito");
  
  pataDianteira2.write(Posi1);
  pataTraseira1.write(Posi2);
 
  delay(500);
  pataDianteira2.write(0);
  pataTraseira1.write(0); 
}

void ResetarPosicao() { //zerar a posições das patas
  Serial.println("Pocição resetada");
 
  pataDianteira1.write(0);//reset de posição
  pataDianteira2.write(0);//reset de posição

  pataTraseira1.write(0);//reset de posição
  pataTraseira2.write(0);//reset de posição
}
