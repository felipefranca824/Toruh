int hPWM_B = 6;//horario
int aPWM_B = 5;// anti-horario

int aPWM_A = 9;//anti - horario
int hPWM_A = 10;// horario

int vel1 = 100,
    vel2 = 140,
    vel3 = 180,
    vel4 = 220,
    vel5 = 250;

int cor_d, cor_e;
int sensor_LA = 11, sensor_LB = 12;
int sensor_FA = A0, sensor_FB = A1;
int sensor_cor_A = A3 , sensor_cor_B = A2;

int d_min_deteccao  = 30;
int quant = 20;
int ultima_busca = 0;

int estado_FB ;
int estado_FA ;
int estado_LA ;
int estado_LB;

int led = 13;
int chave = 7;

int k = 0;

void setup() {
  pinMode(hPWM_A, OUTPUT);
  pinMode(aPWM_A, OUTPUT);

  pinMode(hPWM_B, OUTPUT);
  pinMode(aPWM_B, OUTPUT);

  pinMode(sensor_LA, INPUT);
  pinMode(sensor_LB, INPUT);

  pinMode(led, OUTPUT);
  pinMode(chave, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  int estado_chave = digitalRead(chave);

  if (estado_chave == 1) {
    tornado();
  }
  else {
    busca_aleatoria();
  }

  //


  //aceleracao();

  /*
    frente(2000, 150, 150);
    frente(2000, 200, 200);
    frente(2000, 250, 250);
    frente(2000, 200, 200);
    frente(2000, 150, 150);

  */

}

void aceleracao() {

  for (int g = 0; g < 250; ) {
    Serial.println(g);
    frente(1500, g, g);
    g = g + 20;
  }


}

void tornado()
{
  if (k == 0) {
    descer_rampa();
    k = 1;
  }

  cor_2_leituras();

  if (cor_d == 1 && cor_e == 1)
  {
    estado_FB = media(sensor_FB);
    estado_FA = media(sensor_FA);
    estado_LA = !digitalRead(sensor_LA);
    estado_LB = !digitalRead(sensor_LB);

    if (estado_FB == 1 && estado_FA ==  1 && estado_LA == 0 && estado_LB == 0) {
      frente(1, vel5, vel5);
      //parar(1);
    }

    else if (estado_FB == 1 && estado_FA ==  0 && estado_LA == 0 && estado_LB == 0) {
      frente(1, 0, vel4);
    }
    else if (estado_FB == 0 && estado_FA ==  1 && estado_LA == 0 && estado_LB == 0) {
      frente(1, vel4, 0);
    }

    else if (estado_FB == 0 && estado_FA ==  0 && estado_LA == 1 && estado_LB == 0) {
      direita(1, vel3, vel3);
    }
    else if (estado_FB == 0 && estado_FA ==  0 && estado_LA == 0 && estado_LB == 1) {
      esquerda(1, vel3, vel3);
    }

    else if (estado_FB == 0 && estado_FA ==  1 && estado_LA == 1 && estado_LB == 0) {
      direita(1, vel3, vel3);
    }
    else if (estado_FB == 1 && estado_FA ==  0 && estado_LA == 0 && estado_LB == 1) {
      esquerda(1, vel3, vel3);
    }

    else if (estado_FB == 0 && estado_FA ==  0 && estado_LA == 0 && estado_LB == 0) {
      direita(1, vel3, vel3);
      //parar(1);
    }

    else {
      parar(1);
      digitalWrite(led, 1);
      delay(200);
      digitalWrite(led, 0);
      delay(200);
    }


  }
  else if (cor_d == 0 && cor_e == 1) {
    re(500, vel2, 0);
    esquerda(300, vel5, vel5);
  }
  else if (cor_d == 1 && cor_e == 0) {
    re(500, 0, vel2);
    direita(300, vel5, vel5);
  }
  else {
    parar_branco();
  }
}

void tornado_xau()
{
  cor();

  if (cor_d == 1 && cor_e == 1)
  {
    estado_FB = media(sensor_FB);
    estado_FA = media(sensor_FA);
    estado_LA = !digitalRead(sensor_LA);
    estado_LB = !digitalRead(sensor_LB);

    if (estado_FB == 1 && estado_FA ==  1 && estado_LA == 0 && estado_LB == 0) {
      frente(1, vel5, vel5);
    }
    else if (estado_FB == 1 && estado_FA ==  0 && estado_LA == 0 && estado_LB == 0) {
      frente(1, vel5, vel4);
      ultima_busca == 1;
    }
    else if (estado_FB == 0 && estado_FA ==  1 && estado_LA == 0 && estado_LB == 0) {
      frente(1, vel4, vel5);

    }
    else if (estado_FB == 0 && estado_FA ==  0 && estado_LA == 1 && estado_LB == 0) {
      direita(1, vel5, vel5);
    }
    else if (estado_FB == 0 && estado_FA ==  0 && estado_LA == 0 && estado_LB == 1) {
      esquerda(1, vel5, vel5);
      ultima_busca == 1;
    }
    else {
      if (ultima_busca == 1) {
        esquerda(1, vel3, vel3);

      }
      else {
        direita(1, vel3, vel3);
      }

    }



  }
  else if (cor_d == 0 && cor_e == 1) {
    re(500, vel5, 0);
    esquerda(400, vel5, vel5);
  }
  else if (cor_d == 1 && cor_e == 0) {
    re(500, 0, vel5);
    direita(400, vel5, vel5);
  }
  else {
    parar_branco();
  }
}
void busca_aleatoria()
{

  if (k == 0) {
    descer_rampa();
    k = 1;
  }

  cor_2_leituras();

  if (cor_d == 1 && cor_e == 1)
  {
    estado_FB = media(sensor_FB);
    estado_FA = media(sensor_FA);
    estado_LA = !digitalRead(sensor_LA);
    estado_LB = !digitalRead(sensor_LB);

    if (estado_FB == 1 && estado_FA ==  1 && estado_LA == 0 && estado_LB == 0) {
      frente(1, vel5, vel5);
      //parar(1);
    }

    else if (estado_FB == 1 && estado_FA ==  0 && estado_LA == 0 && estado_LB == 0) {
      frente(1, 0, vel4);
    }
    else if (estado_FB == 0 && estado_FA ==  1 && estado_LA == 0 && estado_LB == 0) {
      frente(1, vel4, 0);
    }

    else if (estado_FB == 0 && estado_FA ==  0 && estado_LA == 1 && estado_LB == 0) {
      direita(1, vel3, vel3);
    }
    else if (estado_FB == 0 && estado_FA ==  0 && estado_LA == 0 && estado_LB == 1) {
      esquerda(1, vel3, vel3);
    }

    else if (estado_FB == 0 && estado_FA ==  1 && estado_LA == 1 && estado_LB == 0) {
      direita(1, vel3, vel3);
    }
    else if (estado_FB == 1 && estado_FA ==  0 && estado_LA == 0 && estado_LB == 1) {
      esquerda(1, vel3, vel3);
    }

    else if (estado_FB == 0 && estado_FA ==  0 && estado_LA == 0 && estado_LB == 0) {
      frente(1, vel3, vel3);
      //parar(1);
    }

    else {
      parar(1);
      digitalWrite(led, 1);
      delay(200);
      digitalWrite(led, 0);
      delay(200);
    }


  }
  else if (cor_d == 0 && cor_e == 1) {
    re(500, vel2, 0);
    esquerda(300, vel5, vel5);
  }
  else if (cor_d == 1 && cor_e == 0) {
    re(500, 0, vel2);
    direita(300, vel5, vel5);
  }
  else {
    parar_branco();
  }
}
void frente(int tempo, int velA, int velB) {
  analogWrite(hPWM_A, velA);
  analogWrite(aPWM_A, 0);


  analogWrite(hPWM_B, velB);
  analogWrite(aPWM_B, 0);
  delay(tempo);
}
void re(int tempo, int velA, int velB) {
  analogWrite(hPWM_A, 0);
  analogWrite(aPWM_A, velA);


  analogWrite(hPWM_B, 0);
  analogWrite(aPWM_B, velB);
  delay(tempo);
}
void esquerda(int tempo, int velA, int velB) {
  analogWrite(hPWM_A, 0);
  analogWrite(aPWM_A, velA);


  analogWrite(hPWM_B, velB);
  analogWrite(aPWM_B, 0);
  delay(tempo);
}
void  direita(int tempo, int velA, int velB) {
  analogWrite(hPWM_A, velA);
  analogWrite(aPWM_A, 0);


  analogWrite(hPWM_B, 0);
  analogWrite(aPWM_B, velB);
  delay(tempo);
}
void  parar(int tempo) {
  analogWrite(hPWM_A, 0);
  analogWrite(aPWM_A, 0);


  analogWrite(hPWM_B, 0);
  analogWrite(aPWM_B, 0);
  delay(tempo);
}

void cor_2_leituras()
{
  int cor_d2, cor_e2;

  int estado_cor_A = analogRead(sensor_cor_A);

  if (estado_cor_A > 700)
  {
    cor_d = 0; // branco
  }
  else {
    cor_d = 1; // branco
  }

  delay(10);
  estado_cor_A = analogRead(sensor_cor_A);
  //int estado_cor_B = analogRead(sensor_cor_B);

  if (estado_cor_A > 700)
  {
    cor_d2 = 0; // branco
  }
  else {
    cor_d2 = 1; // branco
  }

  if (cor_d != cor_d2) {
    delay(10);
    estado_cor_A = analogRead(sensor_cor_A);
    if (estado_cor_A > 700)
    {
      cor_d = 0; // branco
    }
    else {
      cor_d = 1; // branco
    }
  }


  //-------------------- sensor de cor esquerda-----------------


  int estado_cor_B = analogRead(sensor_cor_B);

  if (estado_cor_B > 700)
  {
    cor_e = 0; // branco
  }
  else {
    cor_e = 1; // branco
  }

  delay(10);
  estado_cor_B = analogRead(sensor_cor_B);

  if (estado_cor_B > 700)
  {
    cor_e2 = 0; // branco
  }
  else {
    cor_e2 = 1; // branco
  }

  if (cor_e != cor_e2) {
    delay(10);
    estado_cor_B = analogRead(sensor_cor_B);
    if (estado_cor_B > 700)
    {
      cor_e = 0; // branco
    }
    else {
      cor_e = 1; // branco
    }
  }
}

void cor()
{

  int estado_cor_A = analogRead(sensor_cor_A);
  int estado_cor_B = analogRead(sensor_cor_B);

  if (estado_cor_A > 700)
  {
    cor_d = 0; // branco
  }
  else {
    cor_d = 1; // branco
  }

  //-------------------- sensor de cor esquerda-----------------
  if (estado_cor_B > 700)
  {
    cor_e = 0;
  }
  else {
    cor_e = 1;
  }


}
int media(int pin) {
  float soma = 0;
  float menor = 0, maior = 0;
  float distancia[quant];
  int achou;

  for (int i = 0; i < quant ; i++) {
    float sensorValue = analogRead(pin);
    float dist_cm = (6762 / (sensorValue - 9)) - 4;
    distancia[i] = dist_cm;


    soma = soma + distancia[i];

  }


  menor = distancia[0];

  for (int j = 0; j <= quant - 1 ; j++) {
    if (distancia[j] > maior) {
      maior = distancia[j];
    }
    if (distancia[j] < menor) {
      menor = distancia[j];
    }
  }

  soma = soma - maior - menor;

  float media = soma / (quant - 2);

  if ((media > 0) && (media <= d_min_deteccao)) {
    achou = 1;
  }
  else {
    achou = 0;
  }

  return (achou);
}
void parar_branco() {
  int aleatorio = random(2);
  parar(10);
  re(500, vel1, vel1);
  parar(10);
  if (aleatorio == 1)
  {
    esquerda(450, vel5, vel5);
  }
  else {
    direita(450, vel5, vel5);

  }
  parar(10);
}
void descer_rampa()
{
  frente(50, 250, 250);
  parar(5);
  re(50, 250, 250);
  parar(5);
}
