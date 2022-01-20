#control de servo mediante Rpi.GPIO
import Rpi.GPIO as GPIO#Importamos libreria para hacer uso de la raspberry con python
import time #Importamos la libreria para dar tiempo de espera entre instrucciones
PINsenal=11#Pin en donde vamos a mandar la señal de la raspberry
GPIO.setmode(GPIO.BOARD)#Forma en la que estamos enumerando los pines de la raspberry
GPIO.setup(PINsenal, GPIO.OUT)#Configuramos el pin donde mandaremos la señal como salida
pwm=GPIO.PWM(PINsenal,50)#Creamos objeto pwm en el pin que mandaremos la señal y con frecuencia de 50hrz
pwm.start(6)#Comenzamos el giro del servo en aproximadamente 90°
while True:#Ciclo while para que se este ciclando
    pwm.ChangeDutyCycle(6)#Empezamos en 90°
    time.sleep(1)#Esperamos un segundo antes de cambiar
    pwm.ChangeDutyCycle(7)#giro un poco más
    time.sleep(1)#Esperamos 1s
    pwm.ChangeDutyCycle(8)#giramos un poco más
    time.sleep(1)#1s de espera
    pwm.ChangeDutyCycle(9)#giramos poco mas
    time.sleep(1)#1s
    pwm.ChangeDutyCycle(10)#Un poco más
    time.sleep(1)#1s mas
    pwm.ChangeDutyCycle(11)#un poco mas
    time.sleep(1)#1s mas
    pwm.ChangeDutyCycle(12)#llegamos a 180°
    time.sleep(1)#Esperamos 1 s antes de repetir el ciclo
   