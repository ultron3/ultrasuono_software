import serial
import time

# Configura la porta seriale, sostituisci 'COM3' con la porta seriale a cui è collegato Arduino
ser = serial.Serial('COM3', 5, timeout=1)

try:
    while True:
        # Leggi una linea dalla porta seriale
        line = ser.readline().decode('utf-8').strip()

        # Stampa i dati ricevuti da Arduino
        print(f"Dati da Arduino: {line}")

        # Puoi fare ulteriori elaborazioni o analisi dei dati qui

        # Aggiungi un ritardo per evitare letture troppo frequenti
        time.sleep(1)

except KeyboardInterrupt:
    # Chiudi la porta seriale quando l'applicazione viene interrotta
    ser.close()
    print("Connessione chiusa.")
