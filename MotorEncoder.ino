
/* Programação para usar motor com Encoder
  Para motores LEGO, ligue os fios conforme a imagem:
  http://www.josepino.com/articles/nxt/lego_connector_output.gif

  Ligação do Motor LEGO:
  Preto - Positivo ou negativo do motor (Ligar na Ponte H)
  Branco - Positivo ou negativo do motor (Ligar na Ponte H)
  Vermelho - GND do Encoder (Ligar no GND do circuito)
  Verde - Alimentação do Encoder (Ligue em uma fonte externa de 5V)
  Amarelo - Saida A do Encoder (Ligar em um pino digital de preferência com interrupção
  Azul - Saída B do Encoder (Ligar em um pino digital de preferência com interrupção

  OBS: Nos motores de LEGO NXT e EV3 uma rotação corresponde à 720 pulsos
*/
#include <Encoder.h>

// Mude os dois pinos para os pinos do encoder
//   Melhor performance: os dois pinos do encoder estão ligados em uma porta interrupt
//   Boa Performance: apenas um dos dois está em uma porta interrupt
//   Baixa Performance:  nenhum dos dois está em uma porta interrupt

// Para saber quais pinos são interrupt consulte em:
// https://www.arduino.cc/en/Reference/AttachInterrupt

Encoder encoder(18, 19);
#define forcaMotor 150 // PWM que o motor irá girar

#define motorFrente 6 // Porta PWM que o motor está conectado na Ponte H
#define motorTras 5 // Porta PWM que o motor está conectado na Ponte H

#define pulsosPorVolta 3575 // Número de pulsos por volta que o motor lê com o encoder

void setup() {
  pinMode(motorFrente, OUTPUT);
  pinMode(motorTras, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Inicio da contagem do Encoder:");
}

int contador = 0;

void loop() {
  
  Serial.println(encoder.read()); // Exibe no Serial a contagem do Encoder
  
  counter++;
  
  // Contador para fazer com que o motor só gire uma única vez
  if(contador == 1) {
    // Função para movimentar o motor
    moverMotor(forcaMotor);
    // Faz com que o motor se mova até que a contagem do encoder chegue ao número determinado
    while(encoder.read() <= pulsosPorVolta) {
    }
    moverMotor(0); // quando a contagem chegar ao fim, para o motor
    Serial.print("Contagem de pulsos: ");
    Serial.println(encoder.read());
    encoder.write(0); // reseta o graus da contagem do encoder
  }
  
  
}

/*
 * Função para movimentar o motor para frente ou para trás
 * Parâmetro é a força em que o motor irá girar
 */
void moverMotor(int MotorA) {
  if (MotorA > 0) {
    analogWrite(motorFrente, MotorA);
    analogWrite(motorTras, 0);
  }
  else if (MotorA == 0) {
    analogWrite(motorFrente, 0);
    analogWrite(motorTras, 0);
  }
  else {
    analogWrite(motorFrente, 0);
    analogWrite(motorTras, abs(MotorA));
  }

};




