#include <Servo.h> // include the servo library
Servo servoMotor;
int analogPin = 0; // Pin donde conectaremos la LDR
int servoPin = 2; // Pin de control del Servo
int analogValue = 0; // Variable que almacena el valor de la LDR
void setup()
{
servoMotor.attach(servoPin);
pinMode(analogPin,INPUT);
}
void loop()
{
analogValue = analogRead(analogPin); // lectura del valor de la LDR
if(analogValue>400)// si no detecta coche, a mayor oscuridad, mayor será el numero que se lee en la entrada analogica
{
delay(1500);// retardo de seguridad para bajar la barrera
servoMotor.write(0); // bajada de barrera
}
else// si detecta coche, a mayor luz ambiente, menor será el valor que se lee en la entrada analogica
{
servoMotor.write(90); // subida de barrera
}
delay(50); // waits for the servo to get there
}
