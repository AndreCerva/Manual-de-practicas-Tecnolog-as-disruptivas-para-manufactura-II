int TRIG = 10;// TRIG pin 10
int ECHO = 9;// ECHO pin 9
int pBuzzer = 5;  // BUZZER pin 5
int TIEMPO;// variable para el tiempo
int DISTANCIA;//variable para la distancia
void setup()
{
  pinMode(TRIG, OUTPUT);  // TRIG como salida
  pinMode(ECHO, INPUT);    // ECHO como entrada
  pinMode(pBuzzer, OUTPUT);   // BUZZER como salida
  Serial.begin(9600);     // inicializacion de comunicacion serial a 9600 bps
}
void loop()
{
  digitalWrite(TRIG, HIGH);     // generamos el pulso a enviar
  delay(1);       // Esperamos un milisegundo
  digitalWrite(TRIG, LOW);    // y lo apagamos
  TIEMPO = pulseIn(ECHO, HIGH);  // recibimos el pulso enviado con trig y lo igualamoms a la variable TIEMPO
  DISTANCIA = TIEMPO / 58.2;    // lo dividimos entre la constante 58.2, constante dada por el fabricante y obtenemos la distancia en centimetros
  Serial.print("Distancia: ");
  Serial.print(DISTANCIA);    // envio de valor de distancia por monitor serial
  Serial.println("cm");
  delay(100);       // demora entre datos
  if (DISTANCIA <= 30 && DISTANCIA > 25) { // si distancia entre 25 y 30 cms.
    delay(DISTANCIA * 10);      // demora proporcional a la distancia
    analogWrite(pBuzzer, 100); // pitido de buzzer
    delay(100);
    analogWrite(pBuzzer, LOW);
  }
  if (DISTANCIA <= 25 && DISTANCIA > 20) { // si distancia entre 25 y 20 cms.
    delay(DISTANCIA * 10);      // demora proporcional a la distancia
    analogWrite(pBuzzer, 350); // pitido de buzzer
    delay(100);
    analogWrite(pBuzzer, LOW);
  }
  if (DISTANCIA <= 20 && DISTANCIA > 15) { // si distancia entre 20 y 15 cms.
    delay(DISTANCIA * 10);      // demora proporcional a la distancia
    analogWrite(pBuzzer, 500); // pitido de buzzer
    delay(100);
    analogWrite(pBuzzer, LOW);
  }
  if (DISTANCIA <= 15 && DISTANCIA > 10) { // si distancia entre 15 y 10 cms.
    delay(DISTANCIA * 10);      // demora proporcional a la distancia
    analogWrite(pBuzzer, 800); // pitido de buzzer
    delay(100);
    analogWrite(pBuzzer, LOW);
  }
  if (DISTANCIA <= 10 && DISTANCIA > 0) { // si distancia entre 10 y 0 cms.
    delay(DISTANCIA * 10);      // demora proporcional a la distancia
    analogWrite(pBuzzer, 1200); // pitido de buzzer
    delay(100);
    analogWrite(pBuzzer, LOW);
  }
}
