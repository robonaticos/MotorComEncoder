# Girando seu motor LEGO com Encoder no Arduino
<img src="https://github.com/FeoSilva/MotorComEncoder/blob/master/Capa.jpg" />
<br>
Já tentou utilizar o encoder dos motores LEGO e não conseguiu? <br>
Nessa programação é possível fazer a contagem dos pulsos do Encoder e girar até determinado número de pulsos.<br><br>
OBS: É possível integrar esse código com um sistema de controle P.I.D. para que melhore a perfomance e a precisão do giro do motor.

<h2> Como funciona os Encoders de Quadratura </h2>
O controle em malha aberta é usado para os motores de passos. Já os motores DC necessitam de sistemas mais sofisticados de controle em malha fechada. Como citado em tópicos anteriores o elemento que faz essa realimentação é o encoder rotativo. Este elemento converte movimento rotativo em pulsos elétricos, com isso, ele é capaz de fornecer, quando ligado a um eixo de motor ou em uma roda, informações de distância e velocidade.
<br><br>
A principal especificação de um encoder rotativo é quanto a sua resolução, normalmente expressa em pulsos por revolução (ppr). Por exemplo, um encoder de 512ppr gera 512 pulsos quando o elemento ligado a ele (motor ou roda) executa uma volta.
 <br><br>
O encoder rotativo mais utilizado em robótica é o encoder de quadratura, pois além contar os pulsos em um determinado elemento rotativo (roda ou motor) ele também identifica o sentido do movimento. Estes encoders podem ser ópticos ou magnéticos e possuem dois sinais de saída (canais A e B) que consiste de duas ondas quadradas defasadas 90° uma da outra, a frequência destas ondas indica a velocidade do elemento que está sendo medido e o sinal da defasagem indica o sentido de giro.
<img src="https://github.com/FeoSilva/MotorComEncoder/blob/master/enc_quadratura.jpg"/>

Fonte: https://kleberufu.wixsite.com/micromousebrasil/single-post/2015/05/01/Encoders

<h2>Ligando o motor LEGO no Arduino</h2>

Para ligar os motores LEGO no Arduino você precisará de um Driver de Motor (Ponte-H) para definir o sentido do motor e de uma bateria.

Os motores LEGO do NXT e EV3 possuem 6 fios em seu conector que tem as seguintes funções:
- Preto: Positivo/Negativo do Motor (Ligar na Ponte-H)
- Branco: Positivo/Negativo do Motor (Ligar na Ponte-H)
- Vermelho: GND do Encoder (Conectar em todo GND do circuito)
- Verde: Alimentação do Encoder (Alimentação 5V do Encoder)
- Amarelo: Saída 1 do Encoder (Ligar em uma porta de interrupção no Arduino)
- Azul: Saída 2 do Encoder (Ligar em uma porta de interrupção no Arduino)

<img src="https://github.com/FeoSilva/MotorComEncoder/blob/master/lego_connector_output.gif" />

Abaixo segue foto de todo circuito para realizar os testes com o Encoder:<br>
<img src="https://github.com/FeoSilva/MotorComEncoder/blob/master/Esquematico.png" />
https://www.tinkercad.com/things/9quqieeksfp

Informações técnicas dos motores de LEGO você encontra em: <br>
http://www.philohome.com/motors/motorcomp.htm
<br>

<h2>O que são portas de <b>interrupção</b> e por que utilizá-las?</h2>
No Arduino, assim como em qualquer outro microcontrolador, pode-se utilizar interrupções para priorizar ou não tarefas afim de realiza-las no momento em que a interrupção for detectada.
<br><br>
As portas de interrupção ou também conhecidas como <i>interrupts</i> param a execução do código para realizar uma tarefa que pode ter sido detectada por uma ação externa (um botão pressionado, um sensor lido...) ou por detecções em software (temporizadores ou sinais na própria programação). Ao final da tarefa detectada pela interrupção, o código continua normalmente.
<br><br>
No caso de leitura de pulsos no encoders devemos usar portas de interrupção para que a leitura seja feita na mudança de estado do encoder e não atrasando todo o processamento do microcontrolador. Em muitos casos, o microcontrolador é responsável por mais de uma tarefa além da leitura dos encoders e por conta disso é indispensável a utilização do uso de portas de interrupção. É altamente recomendável utilizar um único microcontrolador somente para a leitura e controle dos motores/encoders, para não sobrecarregar as suas tarefas e conseguir rodar tranquilamente as tasks do seu robô/projeto.
<br><br>
:vibration_mode:: As portas de interrupção no Arduino UNO são as portas 2 e 3 e no Arduino Mega as portas 2, 3, 18, 19, 20, 21
<br><br>
Maiores informações de portas de interrupção e quais são elas, consulte em:<br>
https://www.arduino.cc/en/Reference/AttachInterrupt

<h2>Rodando a programação</h2>

Depois de fazer toda ligação do circuito, instale primeiro a biblioteca "Encoder.h" no seu Arduino.<br><br>
:blue_book: Link da Biblioteca: <br>
https://github.com/PaulStoffregen/Encoder<br><br>
:notebook_with_decorative_cover: Como instalar uma biblioteca no Arduino: <br>
https://www.robocore.net/tutoriais/adicionando-bibliotecas-na-ide-arduino.html

Após feita a instalação da biblioteca, abra a programação 'MotorComEncoder.ino' e teste o código :smile:
<br><br>
<b>Realização - Equipe Robonáticos:</b><br>
<a href="https://github.com/FeoSilva">- Felipe Oliveira Silva </a><br>
<a href="https://github.com/Antonio6745">- Antonio Pereira de Lima Neto </a><br>
<a href="https://github.com/giovannadiodato">- Giovanna Ferreira Diodato</a><br>
<a href="https://github.com/felipetiozo">- Felipe de Souza Tiozo</a><br>
<br>
Apoio - Equipe maxBots<br>
<a href="https://github.com/RobAmorim">- Robson Amorim</a><br><br>
<p align="center"><img src="https://github.com/FeoSilva/OBR-2017/blob/master/M%C3%ADdia/Equipe.jpg" width="600"/></p>
