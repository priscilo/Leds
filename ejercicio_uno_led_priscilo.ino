/* Librería, constantes y variables */
const int led01 = 2;
const int led02 = 3;

void setup() {
  // Configurar los pines como salidas
  pinMode(led01, OUTPUT);
  pinMode(led02, OUTPUT);
}

void loop() {
  // Encender LED 1
  digitalWrite(led01, HIGH);
  delay(2000);

  // Apagar LED 1
  digitalWrite(led01, LOW);
  delay(1000);

  // Encender LED 2
  digitalWrite(led02, HIGH);
  delay(2000);

  // Apagar LED 2
  digitalWrite(led02, LOW);
  delay(1000);
}
