int umidadeSolo = A0;
int rele = 2;
#define DHTPIN 13
#define DHTTYPE DHT11

#include "DHT.h"
DHT dht(DHTPIN, DHTTYPE);

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(rele, OUTPUT);
  dht.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(umidadeSolo);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1000);  // delay in between reads for stability

  if (sensorValue > 800){
    Serial.println("Solo seco");
    digitalWrite(2, HIGH); 
  } 
  else{
    Serial.println("Solo umido");
    digitalWrite(2, LOW); 
  }

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
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