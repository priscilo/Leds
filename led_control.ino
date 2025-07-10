// led_control.ino

#define cantidadLed 5
const int pinLed[cantidadLed] = {2, 3, 4, 5, 6};
const long tiempoLed[cantidadLed] = {300, 1000, 400, 1500, 1200};
long ultimaVez[cantidadLed] = {0};
bool estadoLed[cantidadLed] = {false};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < cantidadLed; i++) {
    pinMode(pinLed[i], OUTPUT);
  }
}

void loop() {
  long ahora = millis();
  for (int i = 0; i < cantidadLed; i++) {
    if (ahora - ultimaVez[i] >= tiempoLed[i]) {
      estadoLed[i] = !estadoLed[i];
      digitalWrite(pinLed[i], estadoLed[i] ? HIGH : LOW);
      ultimaVez[i] = ahora;
    }
  }
}
