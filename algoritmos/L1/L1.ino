/*
    Tecnológico de Costa Rica
    Escuela de Física
    Instrumentación I
    Práctica 1           

    Dr.-Ing Juan J. Rojas
*/

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  while (!Serial){
    ;
  }
  Serial.println("Practica 1");
}

int a0value = 0;
float vmeas = 0;
float cmeas = 0;

void loop() {
  a0value = analogRead(A0);

  Serial.print("A0 (10bits): ");
  Serial.println(a0value);
}
