#include <Servo.h>
//ref https://circuitdigest.com/sites/default/files/inlineimages/servo-rotation.gif

Servo pataDianteira1;
Servo pataDianteira2;

Servo pataTraseira1;
Servo pataTraseira2;


void setup() {
  pataDianteira1.attach();//colocar o pino usado.
  pataDianteira2.attach();//colocar o pino usado.
  
  pataTraseira1.attach();//colocar o pino usado.
  pataTraseira2.attach();//colocar o pino usado.
  
  ResetarPosicao();
  
  Serial.begin(9600);//inicia o serial
  
}

void loop(){
	AndarParaFrente();
	
}

void AndarParaFrente(){
	Serial.print("Andando para frente");
	Serial.print("\t"); 
	
	MovimentoQuad1(90,90);
	delay(15);
	MovimentoQuad2(90,90);
}


void MovimentoQuad1(int Posi1, int Posi2) {//mover uma perna da frente e outra de trás esquerda
	Serial.print("Movendo lado direito");
	Serial.print("\t"); 
	
	pataDianteira1.write(Posi1);
	pataTraseira2.write(Posi2);	
	
	pataDianteira2.write(0);
	pataTraseira1.write(0);
}

void MovimentoQuad2(int Posi1, int Posi2) {//mover uma perna da frente e outra de trás direita
	Serial.print("Movendo lado direito");
	Serial.print("\t"); 
	
	pataDianteira2.write(Posi1);
	pataTraseira1.write(Posi2);
	
	pataDianteira1.write(0);
	pataTraseira2.write(0);	
}

void ResetarPosicao() { //zerar a posições das patas
	Serial.print("Pocição resetada");
	Serial.print("\t"); 

	pataDianteira1.write(0);//reset de posição
	pataDianteira2.write(0);//reset de posição

	pataTraseira1.write(0);//reset de posição
	pataTraseira2.write(0);//reset de posição
}