#Programa para la ejecución de un semaforo con LEDs, 5s en verde, 1s en amarilo y 5s en rojo
import RPi.GPIO as GPIO#Importamos libreria para hacer uso de la raspberry con python
import time#Libreria para dar tiempo de espera ente instrucciones
GPIO.setmode(GPIO.BOARD)#Indicamos como estamos contando los pines de la Raspberry/Forma fisica(BOARD)
LEDR=11#Declaramos el pin al que conectaremos el catodo del LED Rojo
LEDA=13#Declaramos el pin al que conectaremos el catodo del LED Amarillo
LEDV=15#Declaramos el pin al que conectaremos el catodo del LED Verde
GPIO.setup(LEDR, GPIO.OUT)#Indicamos el pin al que está conectado el LED Rojo como salida
GPIO.setup(LEDA, GPIO.OUT)#Indicamos el pin al que está conectado el LED Amarillo como salida
GPIO.setup(LEDV, GPIO.OUT)#Indicamos el pin al que está conectado el LED Verde como salida
while True:#Ciclo while para que se este ejecutando las intrucciones siguientes hasta terminar la ejecucción
    GPIO.output(LEDR, GPIO.HIGH)#Se inicia la ejecución del codigo con el led rojo en alto
    GPIO.output(LEDA, GPIO.LOW)#Se inicia la ejecución del codigo con el led amarillo en bajo
    GPIO.output(LEDV, GPIO.LOW)#Se inicia la ejecución del codigo con el led verde en bajo
    time.sleep(5)#Este estado anterior dura 5s
    GPIO.output(LEDR, GPIO.LOW)#Despues de los 5s se pone en bajo el rojo
    GPIO.output(LEDA, GPIO.HIGH)#Se pone en alto el amarillo
    GPIO.output(LEDV, GPIO.LOW)#El verde sigue en bajo
    time.sleep(1)#Este estado se mantiene durante 1s
    GPIO.output(LEDR, GPIO.LOW)#Se sigue mantienendo apagado el rojo despues del segundo en amarillo
    GPIO.output(LEDA, GPIO.LOW)#Se apaga el led amarillo
    GPIO.output(LEDV, GPIO.HIGH)#Se ilumina el led verde
    time.sleep(5)#Se mantiene en este estado anterior 5s
    #Se repite el ciclo hasta que dejemos de ejecutar el codigo