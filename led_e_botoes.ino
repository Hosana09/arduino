// portas dos botões
int botao_aumenta = 3;
int botao_diminui = 2;

// portas dos leds
int led_vermelho = 13;
int led_laranja = 12;
int led_azul = 11;

// variáveis que verifica se o botão foi pressionado
int aumenta = 0;
int diminui = 0;

// contagem
int led = 0;

void setup()
{
  // inicia a comunicação serial
  Serial.begin(9600);
  // modo de operação dos pinos digitais
  pinMode(botao_aumenta, INPUT);
  pinMode(botao_diminui, INPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_laranja, OUTPUT);
  pinMode(led_azul, OUTPUT);
}

void loop()
{
  // apaga todos os leds para iniciar
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_laranja, LOW);
  digitalWrite(led_azul, LOW);
  
  // lê os botões
  aumenta = digitalRead(botao_aumenta);
  diminui = digitalRead(botao_diminui);
  
  // aumenta ou diminui a contagem
  if (aumenta == 1) {
  	led++;
    delay(1000);
    Serial.println(led);
  }
  
  if (diminui == 1) {
  	led--;
    delay(1000);
    Serial.println(led);
  }
  
  // ascende os leds conforme cada regra
  if (led % 2 == 0) {
  	digitalWrite(led_vermelho, HIGH);
  } 
  
  if (led % 3 == 0) {
  	digitalWrite(led_laranja, HIGH);
  } 
  
  if (led % 5 == 0) {
  	digitalWrite(led_azul, HIGH);
  }
}
