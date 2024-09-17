#include "Adafruit_BMP280.h"

Adafruit_BMP280 bmp;
float temperature = 0;
float pressure = 0;

void setup() {
  Serial.begin(115200);
  delay(2000);
  if (!bmp.begin(0x77)) {
    Serial.println("Sensor not found");
    while (1){}
  }
}

void loop() {
  // Read the values
  temperature = bmp.readTemperature();
  pressure = bmp.readPressure();
  // Print to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.println();
  delay(1000);
}