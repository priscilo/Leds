#include <DHT.h>
#include <LiquidCrystal.h>
// Definiciones de pines
#define DHTPIN 9          // Pin donde está conectado el DHT11
#define DHTTYPE DHT11     // Tipo de sensor DHT
#define LED_ROJO 6        // Pin del LED rojo
#define LED_AMARILLO 7    // Pin del LED amarillo
#define LED_VERDE 8       // Pin del LED verde
#define BOCINA 10          // Pin de la bocina
// Inicialización del sensor DHT
DHT dht(DHTPIN, DHTTYPE);
// Inicialización del LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const char scrollText[] = "BC TECH, de Tito BC    "; // Texto para scroll con espacios para la animación
const int lcdWidth = 16; // Ancho del LCD

int scrollPos = 0; // Posicion actual del scroll

unsigned long lastScrollTime = 0;
const unsigned long scrollInterval = 300; // Intervalo de scroll en ms
void setup() {
  // Inicializar el LCD
  lcd.begin(16, 2);  
  // Inicializar el DHT
  dht.begin();  
  // Configurar pines de LEDs y bocina como salida
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(BOCINA, OUTPUT);  
  // Mensaje inicial en el LCD
  lcd.print("Iniciando...");
  delay(2000);
}

void loop() {
  // Leer la temperatura en grados Celsius
  float temperatura = dht.readTemperature();
 
  // Verificar si la lectura falló
  if (isnan(temperatura)) {
    lcd.clear();
    lcd.print("Error en DHT");
    return;
  }
 
  // Mostrar la temperatura en el LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C");
  /*
  lcd.setCursor(0,1);
  lcd.print(" BC TECH ");
  */
  // Desplazamiento texto segunda línea
 
  unsigned long currentMillis = millis();
  if (currentMillis - lastScrollTime >= scrollInterval) {
    lastScrollTime = currentMillis;
    lcd.setCursor(0, 1); // Segunda línea

    // Construir la porción visible
    char displayLine[17]; // 16 chars + terminador de cadena

    for (int i = 0; i < lcdWidth; ++i) {
      int charIndex = (scrollPos + i) % (sizeof(scrollText) - 1);
      displayLine[i] = scrollText[charIndex];
    }
    displayLine[lcdWidth] = '\0';

    lcd.print(displayLine);

    scrollPos = (scrollPos + 1) % (sizeof(scrollText) - 1);
  }

  // Controlar LEDs y bocina según la temperatura
  if (temperatura >= 26) {
    digitalWrite(LED_ROJO, HIGH);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_VERDE, LOW);
    //lcd.setCursor(0,1);
    //lcd.print(" LO amas ");
    digitalWrite(BOCINA, HIGH); // Encender bocina
  } else if (temperatura >=24) {
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AMARILLO, HIGH);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(BOCINA, LOW); // Apagar bocina
    //lcd.setCursor(0,1);
    //lcd.print(" NO LO amas ");
  } else {
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(BOCINA, LOW); // Apagar bocina
    //lcd.setCursor(0,1);
    //lcd.print(" talvez lo amas ");
  }
 
  delay(2000); // Esperar 2 segundos antes de la siguiente lectura
}

*** En caso este correo llegue a tu bandeja de entrada, fuera de tu jornada diaria laboral, deberás revisarlo al día hábil siguiente ***