#include <SPI.h>
#include <Ethernet.h>
 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//indirizzo server web (locale)
IPAddress server(192, 168, 1, 4);// ho inserito l' ip del pc su cui ho installato xampp (server apache 127.0.0.1 porta 80)
 
//indirizzo ip dell'Arduino
IPAddress ip(192, 168, 1, 177);
 
EthernetClient client;
 
String strURL = "";
 
void setup()
{
Serial.begin(9600);
 
if (Ethernet.begin(mac) == 0)
{
Serial.println("Configurazione DHCP fallita!");
Ethernet.begin(mac, ip);
}
 
delay(1000);
 
}
 
void loop()
{
UpdateTemp();
 
while(client.available())
{
char c = client.read();
Serial.print(c);
}
 
if (!client.connected())
{
Serial.println();
Serial.println("Disconnesso.");
client.stop();
}
 
//esegui la richiesta ogni 10 secondi
delay(10000);
}
 
void UpdateTemp()
{
Serial.println("Connessione...");
 
if (client.connect(server, 80))
{
Serial.println("Connesso");
 
//creo l'url utilizzando una stringa
strURL = "GET /arduino/index.php?valore=3 HTTP/1.1";
 
//invio la richiesta al server
client.println(strURL);
client.println("Host: arduino");
client.println("Connection: close");
client.println();
//chiudo la connessione
client.stop();
}
else
{
Serial.println("Errore Connessione");
}
