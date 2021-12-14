#include <Servo.h> //Importamos la biblioteca Servo.h
Servo barrera; //Declaramos un servo y se llama barrera, con esto vamos a trabajar
int ledv = 13; //Declaramos un Led, en este caso el verde sobre el pin 13
int leda = 12; // Declaramos el led amarillo en el pin 12 
int ledr = 11; // Declaramos el Led rojo en el pin 11
void setup(){
pinMode(ledv, OUTPUT);//Establecemos el modo de función de cada led
pinMode(leda, OUTPUT);//Establecemos el modo de función de cada led
pinMode(ledr, OUTPUT);//Establecemos el modo de función de cada led
barrera.attach(9);//Asociamos el servomotor al pin 9 del Arduino
}
void loop(){
barrera.write(0); //Indicamos a nuestro servomotor que tiene que comenzar en cero grados 
digitalWrite(ledr, HIGH);//Comenzamos nuestro programa encendiendo el Led rojo ya que nuestra barrera comienza con la posición 0.
delay (5000);//Hacemos un delay de 5 segundo antes de mandarle la siguiente instruccion
digitalWrite(ledr, LOW);//Hacemos el programa para el cambio de rojo a verde pasando por el amarillo.
digitalWrite(leda, HIGH);//5 segundos parpadeando nuestro led amarillo
delay(1000);
digitalWrite(leda, LOW);
delay(1000);
digitalWrite(leda, HIGH);
delay(1000);
digitalWrite(leda, LOW);
delay(1000);
digitalWrite(leda, HIGH);
delay(1000);
digitalWrite(leda, LOW);
delay(1000);
digitalWrite(ledv, HIGH);//Una vez ha cambiado el led a verde, cambiamos la posición de la barrera.
barrera.write(90);
delay(5000); // 5 segundos en verde slido
digitalWrite(ledv, LOW); // se apaga el led verde para comenzar nuevamente con el ciclo
}
