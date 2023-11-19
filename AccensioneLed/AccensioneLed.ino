
#include <SPI.h>
#include <WiFi101.h>

// Costanti per la connessione WiFi
char ssid[] = "IlTuoSSID";
char password[] = "LaTuaPassword";

WiFiClient client;

// Indirizzo IP e porta del server socket
IPAddress serverIP(192, 168, 1, 100);  // Sostituisci con l'indirizzo IP del tuo server socket
int serverPort = 5500;  // Sostituisci con la porta del tuo server socket

// Dichiarazione dei pin a cui sono connessi i LED
const int pinLed1 = 2;
const int pinLed2 = 3;
const int pinLed3 = 4;
const int pinLed4 = 5;

// Tempo in millisecondi tra l'accensione di ogni LED
const int delayBetweenLEDs = 5000;

void setup() {
  // Inizia la connessione WiFi
  while (WiFi.begin(ssid, password) != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connessione in corso...");
  }

  Serial.println("Connesso!");

  // Imposta i pin dei LED come OUTPUT
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);

  delay(2000); // Attendi 2 secondi
}

void loop() {
  // Array di byte con le posizioni dei LED
  byte ledPattern[] = {B0001, B0010, B0100, B1000};

  // Ciclo attraverso gli elementi dell'array
  for (int i = 0; i < sizeof(ledPattern); i++) {
    // Accendi/spegni i LED in base al pattern
    digitalWrite(pinLed1, bitRead(ledPattern[i], 0));
    digitalWrite(pinLed2, bitRead(ledPattern[i], 1));
    digitalWrite(pinLed3, bitRead(ledPattern[i], 2));
    digitalWrite(pinLed4, bitRead(ledPattern[i], 3));

    // Verifica se il socket è connesso e invia una notifica
    if (client.connect(serverIP, serverPort)) {
      Serial.println("LED acceso! Notifica inviata al socket.");

      // Invia una notifica al socket
      String notificationMessage = "LED acceso!";
      client.println(notificationMessage);

      client.stop();
    }

    delay(1000); // Attendi 1 secondo
  }

  // Attendi 5 secondi prima di accendere il prossimo LED
  delay(delayBetweenLEDs);
}
