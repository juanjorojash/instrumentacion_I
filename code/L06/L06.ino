bool S = 0;
bool R = 0;
bool Qp = 0;
bool Qa = 0;
String input = "x";

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  while(Serial.available()) input = Serial.readStringUntil('\n');
  if (input == "s"){
    Serial.println("set");
    S = 1;
  }
  if (input == "r"){
    Serial.println("reset");
    R = 1;
  }

  Qa = (S||Qp)&&!R;

  if (Qa != Qp) {
    Serial.print("Q: ");
    Serial.println(Qa);
  }
  digitalWrite(LED_BUILTIN, Qa);  // turn the LED on (HIGH is the voltage level)

  S = 0;
  R = 0;
  input = "x";
}