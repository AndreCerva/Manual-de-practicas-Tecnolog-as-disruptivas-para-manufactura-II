#include <DHT.h>//Libreria para hacer uso del sensor DHT 11 o 22
#define Type DHT11//11 por ser el DHT11
int DHTpin=2;//pin al que se conectara
DHT dht(DHTpin,Type);// dht como nombre de la variable
float humedad;//Variable auxiliar para la humedad
float temperatura;//Para la temperatura, la mediremos en celsius
void setup() {
Serial.begin(9600);//Inicializamos nuestra comunicación serial
dht.begin();//inicializamos nuestro sensor
}
void loop() {
humedad = dht.readHumidity();//metodo de la libreria DHT para leer la humedad
temperatura = dht.readTemperature();//Metodo de la temperatura para leer temperatura
// Comprobamos si las lecturas pueden dar algún fallo mediante la función isnan()
// Esta función devuelve un 1 en caso de que el valor no sea numérico
// Los caracteres || son como un OR. Si se cumple una de las dos condiciones mostramos error
if (isnan(humedad) || isnan(temperatura)) {
Serial.println("Fallo al leer el sensor DHT11");
return;
}
Serial.print("temperatura=");
Serial.print(temperatura);
Serial.print("&humedad=");
Serial.println(humedad);
delay(1000);
}
