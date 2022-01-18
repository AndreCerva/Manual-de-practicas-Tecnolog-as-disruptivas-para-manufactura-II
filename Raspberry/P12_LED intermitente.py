#Programa para realiza el Hola mundo en una Raspberry con Python
import RPi.GPIO as GPIO #Importamos la libreria para hacer uso de una Raspberry en Python 
import time #Libreria para dar tiempo de espera entre instrucciones
GPIO.setmode(GPIO.BOARD)#Forma en la que estamos viendo los pines de la Raspberry(BOARD)
LED=7 #Indicamos en que pin vamos a conectar el positivo del diodo LED
GPIO.setup(LED, GPIO.OUT)#configuramos el pin que vamos a utilizar como una salida para poder manipular el estado del led
while True: #Ciclo while para que se este ejecutando las instrucciónes hasta terminar el programa
    GPIO.output(LED,GPIO.HIGH)#Encendemos el LED
    time.sleep(1)#Esperamos 1 segundo con nuestro estado actual
    GPIO.output(LED,GPIO.LOW)#Apagamos el LED
    time.sleep(1)#Esperamos un segundo con nuestro estado actual
    #Se repite el ciclo hasta que se deje de ejecutar el codigo