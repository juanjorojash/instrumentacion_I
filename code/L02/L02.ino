int azero = 0;
float v = 0;
float RT = 0;
float T = 0;
//double prev_time = 0;
int sec = 0;
int min = 0;
int hou = 0; 
char time_stamp[50];

#define R0 10240
#define BETA 4100
#define T0 298.15
#define RR 10000
#define zero 273.15

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
}

void loop() { 
  // leer el pin A0
  azero = analogRead(A0);
  // convertir en voltaje
  v = (azero/1023.0)*5;


// convertir en resistencia
  //Calcular R0/R y asignarlo a RT
  RT = (5/v) - 1;

  //Calcular R y asignarlo a RT
  RT = RR/RT;

  // convertir en temperatura con la ecuación proporcionada
  // Despejar la ecuación para T
  //  Simplificar la ecuación para obtener el numerador y denominador
  //Calcular el denominador y asignarlo a T
  T = BETA + T0 * log(RT/RR);
  // numerador/denominador y asignarlo a T
  T = (BETA * T0) / T;

  // Convertir a grados Celsius 
 T = T - zero;

  // Acá se debe incluir el código para calcular T2 e imprimir R, T1 y T2 en la terminal
}


