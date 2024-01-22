int umidadeSolo = A0;
int rele = 2;
#define DHTPIN 13
#define DHTTYPE DHT11

#include "DHT.h"
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(rele, OUTPUT);
  dht.begin();
}

void loop() {
  int sensorValue = analogRead(umidadeSolo);
  Serial.println(sensorValue);
  delay(1000);

  if (sensorValue > 800){
    Serial.println("Solo seco");
    digitalWrite(2, HIGH); 
  } 
  else{
    Serial.println("Solo umido");
    digitalWrite(2, LOW); 
  }

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}