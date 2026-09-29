#include "DHT.h"

#define SENSOR 2     // Pin DATA del DHT22 conectado al pin digital 2

DHT dht(SENSOR, DHT22); // Inicialización del objeto DHT22

float TEMPERATURA;
float HUMEDAD;

void setup() {
  Serial.begin(9600);
  dht.begin(); // Inicialización del sensor
}

void loop() {
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();

  // Verificar si la lectura falló
  if (isnan(TEMPERATURA) || isnan(HUMEDAD)) {
    Serial.println("Error al leer el sensor DHT22");
    delay(2000);
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(TEMPERATURA);
  Serial.print(" °C  -  Humedad: ");
  Serial.print(HUMEDAD);
  Serial.println(" %");

  delay(2000); // El DHT22 requiere 2 segundos entre lecturas
}