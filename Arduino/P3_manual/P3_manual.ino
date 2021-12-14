int LDR_Pin = 0; //pin conectado al fotoresistor LDR
int ledPin=9; //pin conectado al led
int luminosidad; // variable para registrar la lectura del LDR
int umbral=330; // valor umbral de luminosidad
void setup()
{
Serial.begin(9600); //Begin serial communcation
pinMode(ledPin, OUTPUT );// Lo usaremos para ver la lectura real
digitalWrite(ledPin,0);// y ajustar si necesario
}
void loop()
{
luminosidad= analogRead(LDR_Pin);
Serial.println(luminosidad); //Escribimos el valor en monitor serie
//monitorizando este valor podemos ajustar el umbral para encender el led en función de la luminosidad
if (luminosidad > umbral)// valor experimental
{
digitalWrite(ledPin,LOW);// si la luminosidad es mayor apagamos el led
}
else
{
digitalWrite(ledPin,HIGH);// en caso contrario encendemos el led
}
delay(10); // A mayor valor mas lenta sera la respuesta a los cambios de luminosidad
}
