long distancia; //Variable auxiliar para almacenar la distancia recorrida por el ultrasonido hasta regresar
long tiempo; //Variable auxiliar para almacenar el tiempo que se tardo en ir y regresar el ultrasonido
void setup(){
Serial.begin(9600);
pinMode(9, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
pinMode(8, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
}
void loop(){
digitalWrite(9,LOW); /* Por cuestión de estabilización del sensor*/
delayMicroseconds(5); //Dados por el manual del fabricante
digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/
delayMicroseconds(10); //Dados por el manual del fabricante
tiempo=pulseIn(8, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío del pulso ultrasónico y 
cuando el sensor recibe el rebote, es decir: desde que el pin 8 empieza a recibir el rebote, HIGH, hasta que deja de hacerlo, LOW, la longitud del pulso entrante*/
distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/ /*Monitorización en centímetros por el monitor serial*/
Serial.print("Distancia "); //se imprimen los datos obtenidos
Serial.print(distancia);
Serial.println(" cm");
delay(1000); //Se repite ciclo cada segundo
}
