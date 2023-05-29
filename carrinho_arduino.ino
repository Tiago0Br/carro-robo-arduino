//Definição dos pinos de saída para os dois motores
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

//Definindo pinos para o controle de velocidade dos motores
#define ENA 7
#define ENB 12

// Definindo velocidade dos motores
#define VEL 110

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
}

// Criando funções para a movimentação dos motores
void movFrente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, VEL);
  analogWrite(ENB, VEL);
}

void movTras() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, VEL);
  analogWrite(ENB, VEL);
}

void movDireita() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, VEL);
  analogWrite(ENB, VEL);
}

void movEsquerda() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, VEL);
  analogWrite(ENB, VEL);
}

void semMov() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

char cha;

void loop() {
  if (Serial.available() > 0) {
    cha = Serial.read();
    delay(2);

    //Movimenta para frente
    if (cha == 'F') {
      movFrente();
    }

    //Movimenta para trás
    if (cha == 'B') {
      movTras();
    }

    //movimenta para direita
    if (cha == 'R') {
      movDireita();
    }

    //movimenta para esquerda
    if (cha == 'L') {
      movEsquerda();
    }

    //Sem movimento
    if (cha == '0') {
      semMov();
    }
  }
}
