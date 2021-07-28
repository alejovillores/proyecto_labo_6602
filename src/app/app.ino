#include <Wire.h>
#include "SparkFunBME280.h"

// Constantes del programa
const float TEMPERATURA_RIEGO = 25.0;
const float HUMEDAD_RIEGO = 0.0;
const float PRESION_RIEGO = 0.0;
const int TIEMPO = 180000;

BME280 bme280Sensor;


void setup() {
  Serial.begin(115200);
  Serial.println("Lecturas del sensor BME280");

  Wire.begin();

  if (mySensor.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("El sensor no respondió. Controlar el cableado.");
    while(1); //Freeze
  }

}

void loop() {
  if (humedadDeRiego()) {
    if( temperaturaDeRiego() || presionDeRiego()) {
      activarRegador(TIEMPO);
    }
  }
  // Delay de 10 min
  delay(600000)
}


// Evalua la temperatura actual con la que se determina con la constante
bool temperaturaDeRiego() {
  float tempCelsius = bme280Sensor.readTempC();
  return tempCelsius >= TEMPERATURA_RIEGO;
}

// Evalua la humedad actual con la que se determina con la constante
bool humedadDeRiego(){
  float humedadMedida = analogRead(A0);
 
  return humedadMedida >= HUMEDAD_RIEGO;
}
// Evalua la presion actual con la que se determina con la constante
bool presionDeRiego(){
  float presionMedida = bme280Sensor.readFloatPressure();
  return presionMedida >= PRESION_RIEGO;
  }

void activarRegador(const int TIEMPO){
  // code...
}
