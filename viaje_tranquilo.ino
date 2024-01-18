#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
int vibr = 5;
int gas = 4;
int pres = 3;
int cont = 13;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(vibr,INPUT);
  pinMode(gas,INPUT);
  pinMode(pres,INPUT);
  pinMode(cont,INPUT);
}

void loop() {
  delay(2000);

  float umid = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(umid) || isnan(temp)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(umid);
  float hic = dht.computeHeatIndex(temp, umid, false);

  Serial.print("A temperatura está em ");
  Serial.print(temp);
  Serial.println("°C");
  delay(500);
  Serial.print("A umidade está em ");
  Serial.print(umid);
  Serial.println("%");
  delay(500);

  if(temp <= 23){
    Serial.println("[ATENÇÃO] O ar condicionado pode estar ligado!");
    delay(500);
  }else{
    Serial.println("O ar condicionado está desligado.");
    delay(500);
  }

  if(digitalRead(vibr) == HIGH){
    Serial.println("[ATENÇÃO] O ar condicionado está ligado!");
    delay(1000);
  }else{
    Serial.println("O ar condicionado está desligado.");
    delay(200);
  }

  if(digitalRead(gas) == HIGH){
    Serial.println("[ATENÇÃO] Você deixou o gás ligado!");
    delay(1000);
  }else{
    Serial.println("Você desligou o gás.");
    delay(1000);
  }

  if(digitalRead(pres) == HIGH){
    Serial.println("[ATENÇÃO] Tem pessoas dentro da casa!");
    delay(1000);
  }else{
    Serial.println("Não tem ninguém dentro da casa.");
    delay(1000);
  }

  if(digitalRead(cont) == HIGH){
    Serial.println("[ATENÇÃO] Você deixou a porta aberta!");
    delay(1000);
  }else{
    Serial.println("Você fechou a porta.");
    delay(1000);
  }
}