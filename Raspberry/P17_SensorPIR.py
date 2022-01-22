import RPi.GPIO as GPIO#Importamos libreria para hacer uso de la raspberri
import time#Libreria para el tiempo de espera
GPIO.setmode(GPIO.BOARD)#Enumeración de los pines de la rasp mediante el metodo BOARD
PIR_PIN = 7#Pin de entrada de la senal
GPIO.setup(PIR_PIN, GPIO.IN)#Configuramos el pin como una entrada a la rasp
time.sleep(2)#Damos 2s de espera
while True:#Entramos a ciclo while para ejecutar continuamente las instrucciones siguientes
    if GPIO.input(PIR_PIN):#Si recibe una señal de entrada en el pin que indicamos
        print("Presencia detectada")#Mandamos mensaje de que se ha detectado
        time.sleep(1)#Esperamos un segundo antes de volver a consultar la entrada