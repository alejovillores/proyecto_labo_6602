#include <Wire.h>
#include "SparkFunBME280.h"

// Constantes del programa
const float TEMPERATUR_RIEGO = 25.0;

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
  if (temperaturaDeRiego) {
    if(humedadDeRiego && )
  }

}


// Evalua la temperatura actual con la que se determina con la constante
bool temperaturaDeRiego(const float TEMPERATUR_RIEGO) {
  float tempCelsius = bme280Sensor.readTempC();

  if (tempCelsius >= TEMPERATURA_RIEGO){
    return true;
  }

  return false;
}

bool humedadDeRiego(const float HUMEDAD_RIEGO){
  // code...
  // TODO: ver el sensor de humedad en la tierra
    
}

bool presionDeRiego(const float PRESION_RIEGO){}
