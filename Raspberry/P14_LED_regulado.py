import RPi.GPIO #Libreria para hacer uso de la raspberry en python
import time #Libreria para el tiempo de espera
LEDPIN=7#Declaramos el pin en donde vamos a conectar el LED
GPIO.Setmode(GPIO.BOARD)#Indicamos como estamos enumerando los pines de la raspberry
GPIO.Setup(LEDPIN,GPIO.OUT)#Indicamos el pin del led como salida para poder encenderlo y apagarlo
LED=GPIO.PWM(LEDPIN,100)#Creamos un objeto PWM almacenado en LED con una frecuencia de 100hhz
while True:#Ciclo while para que se ejecute constantemente las instrucciones en el ciclo
    LED.start(0)#Comenzamos el led con 0 de intensidad
    for cycle in range(0,100,25):#ciclo for para ir cambiando la intensidad del led de 25 en 25
        LED.ChangeDutyCycle(cycle)#Le damos al led el valor del ciclo cada que cambia este
        time.sleep(0.5)#Esperamos medio segundo antes de volver a ejecutar las instrucciones del for
        #Se repite el ciclo for constantemente por estar en el while