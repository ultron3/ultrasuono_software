using System.IO.Ports;

namespace Arduino
{
    public class Program
    {
        public static void Main(string[] args)
        {
            // Imposta la porta seriale e la velocità di trasmissione, sostituisci "COM3" con la porta seriale a cui è collegato Arduino
            SerialPort serialPort = new SerialPort("COM3", 9600);

            try
            {
                // Apri la porta seriale
                serialPort.Open();

                // Leggi dati dalla porta seriale
                while (true)
                {
                    string data = serialPort.ReadLine().Trim();

                    // Stampa i dati ricevuti da Arduino
                    Console.WriteLine($"Dati da Arduino: {data}");

                    // Puoi fare ulteriori elaborazioni o analisi dei dati qui

                    // Aggiungi un ritardo per evitare letture troppo frequenti
                    System.Threading.Thread.Sleep(1000);
                }
            }
            catch (UnauthorizedAccessException ex)
            {
                Console.WriteLine($"Errore: {ex.Message}");
            }
            catch (ArgumentOutOfRangeException ex)
            {
                Console.WriteLine($"Errore: {ex.Message}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Errore: {ex.Message}");
            }
            finally
            {
                // Chiudi la porta seriale quando l'applicazione viene interrotta
                serialPort.Close();
                Console.WriteLine("Connessione chiusa.");
            }
        }
    }
}
