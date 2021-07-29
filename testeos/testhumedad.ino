float humedad_leida = 0;

void setup () {
    Serial.begin(9600);

}

void loop() {
    humedad_leida = analogRead(A0);
    Serial.println(humedad_leida);
    delay(5000);
}