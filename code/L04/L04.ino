#include "HX711_MP.h"

HX711_MP scale;

const int pinDT = 3;
const int pinSCK = 2;
const int nLecturas = 10;

void setup() {
  Serial.begin(9600);
  scale.begin(pinDT, pinSCK);
  Serial.println("=== Menú Interactivo HX711_MP ===");
  Serial.println("Comandos:");
  Serial.println("  r - Registrar punto de calibración");
  Serial.println("  p - Mostrar peso promedio");
  Serial.println("  c - Mostrar lectura cruda");
  Serial.println("  t - Tara");
  Serial.println("  l - Listar puntos de calibración");
  Serial.println("==================================");
}

void loop() {
  if (Serial.available()) {
    char opcion = Serial.read();

    switch (opcion) {
      case 'r':
        registrarPunto();
        break;
      case 'p':
        mostrarPesoPromedio();
        break;
      case 'c':
        mostrarLecturaCruda();
        break;
      case 't':
        scale.tare();
        Serial.println("Tara aplicada.");
        break;
      case 'l':
        listarPuntos();
        break;
      default:
        Serial.println("Opción no válida.");
        break;
    }
  }
}

void esperarTecla() {
  Serial.println("Presiona cualquier tecla para capturar...");
  while (!Serial.available()) {}
  Serial.read(); // Limpia el buffer
}

void registrarPunto() {
  Serial.println("Ingresa el peso real en gramos:");
  while (!Serial.available()) {}
  float peso = Serial.parseFloat();

  Serial.print("Coloca ");
  Serial.print(peso);
  Serial.println(" g sobre la celda.");
  esperarTecla(); // Espera confirmación del usuario

  long lectura = scale.read();
  scale.addCalibratePoint(lectura, peso);

  Serial.print("Registrado: ");
  Serial.print(lectura);
  Serial.print(" → ");
  Serial.print(peso);
  Serial.println(" g");
}

void mostrarPesoPromedio() {
  float suma = 0;
  for (int i = 0; i < nLecturas; i++) {
    suma += scale.getWeight();
    delay(50);
  }
  float promedio = suma / nLecturas;
  Serial.print("Peso promedio: ");
  Serial.print(promedio, 2);
  Serial.println(" g");
}

void mostrarLecturaCruda() {
  long lectura = scale.read();
  Serial.print("Lectura cruda: ");
  Serial.println(lectura);
}

void listarPuntos() {
  Serial.println("Puntos de calibración:");
  for (int i = 0; i < scale.getCalibratePoints(); i++) {
    Serial.print("  ");
    Serial.print(scale.getCalibrateRaw(i));
    Serial.print(" → ");
    Serial.print(scale.getCalibrateWeight(i));
    Serial.println(" g");
  }
}
