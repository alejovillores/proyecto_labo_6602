#include <Wire.h>
#include "SparkFunBME280.h"

// Constantes y declaraciones de variables del programa
const long HORA = 1800000; // 30 minutos
const float TEMPERATURA_RIEGO = 25.0;
const float HUMEDAD_RIEGO = 0.0;
const float PRESION_RIEGO = 0.0;
const int TIEMPO = 180000; // 3 minutos

bool yaSeRego = false;
float tempCelsius = 0;
float humedadMedida = 0;
float humedadPorcentual = 0.0;
float presionMedida = 0;

BME280 bme280Sensor;


void setup() {
  Serial.begin(9600);
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
  tempCelsius = bme280Sensor.readTempC();

  return tempCelsius >= TEMPERATURA_RIEGO;
}

// Evalua la humedad actual con la que se determina con la constante
bool humedadDeRiego(){
  humedadMedida = analogRead(A0);
  humedadPorcentual =

  return humedadMedida >= HUMEDAD_RIEGO;
}
// Evalua la presion actual con la que se determina con la constante
bool presionDeRiego(){
  presionMedida = bme280Sensor.readFloatPressure();

  return presionMedida >= PRESION_RIEGO;
  }

// Activa el regador si no se ha regado durante los ultimos 30 min
void activarRegador(){
  if (!yaSeRego){
    
    yaSeRego = true;
    desactivarEstado();
  }
}

// Desactiva el estado despues de 30 min
void desactivarEstado(){
  delay(HORA);
  yaSeRego = false;
}
