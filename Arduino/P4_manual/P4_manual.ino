#include <Servo.h>
Servo SR04; //Indicamos variable como un servomotor rotacion continua
int PinLectura=0;//Creamos dos variables auxiliares para la lectura del potenciometro
int potentiometro=0;
void setup()
{
SR04.attach(9);// servo connectado al pin 9
pinMode(A0,INPUT);//A0 entrada analogica en la que se hara la lectura del potenciometro
}
void loop()
{
PinLectura=analogRead(A0);//Se lee la entrada analogica recibiendo la señal del potenciometro
delay(10);//10 milisegundos 
potentiometro=map(PinLectura,0,1023,0,360);//mapeo del rango de valores de 0-1023 a 0-180
potentiometro=constrain(potentiometro,0,360);//asegurarnos de que estrictamente los valores se encuentren entre 0-180
SR04.write(potentiometro);//Pasar al servomotor la lectura que se está recibiendo
delay(50);//tiempo de 50milisegundos
}
