// Sistema automático de ventilación que active un motor cuando lleguemos a una determinada temperatura
const int sensorPin = A0; //conectamos el sensor a la entrada analógica A0
const int motorPin = 9; //conectamos el motor a la salida PWM 9
void setup()
{
Serial.begin(9600);// abre la comunicación serial para mostrarla por el monitor
pinMode(motorPin,OUTPUT); //definimos el pin 9 como SALIDA
digitalWrite(motorPin,0); //hacemos que el motor este apagado por defecto
}
void loop(){
int sensorVal = analogRead(sensorPin);// leemos el valor del sensor en la entrada analógica A0 y lo almacenamos en la variable sensorVal
// convertimos la señal del sensor con el DAC interno de cada entrada analógica
float voltage = (sensorVal*5)/1023.0; // 1023 porque es la resolución de la entrada del DAC // 5 porque es la tensión a la que está alimentado el sensor
float temperature = (voltage * 100)-0.5;//Escalamos el voltaje en temperatura
Serial.print(temperature);
Serial.println(" grados C° ");
if(temperature>30)//comparamos la Ta con la de referencia
{
digitalWrite(motorPin,1);//enciende ventilador
}
else
{
digitalWrite(motorPin,0);//apaga ventilador
}
delay(1000);//hace una lectura del sensor cada segundo
}
