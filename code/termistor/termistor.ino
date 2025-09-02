int azero = 0;
float v = 0;
float RT = 0;
float T = 0;
//double prev_time = 0;
int sec = 0;
int min = 0;
int hou = 0; 
char time_stamp[50];

#define RR 10240
#define BETA 4100
#define T0 298.15
#define R0 10000
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
  RT = (5/v) - 1;
  RT = RR/RT;
  // convertir en temperatura
  T = BETA + T0 * log(RT/R0);
  T = (BETA * T0) / T;
  T = T - zero;
  sprintf(time_stamp,"%02d:%02d:%02d,", hou, min, sec);
  Serial.print(time_stamp);
  Serial.println(T); 
  //prev_time = millis();
  delay(1000);        // esperar un segundo 
  sec++;
  //sec += (int)((millis() - prev_time)/1000);
    if (sec >= 60){
      sec = 0;
      min++;
    }
    if (min >= 60){
      min = 0;
      hou++;
    }
}


