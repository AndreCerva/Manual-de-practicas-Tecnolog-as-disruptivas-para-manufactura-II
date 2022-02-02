import RPi.GPIO as GPIO#Libreria para hacer uso de la raspberry en python
import time#Libreria para dar tiempo de espera entre instrucciones
GPIO.setmode(GPIO.BOARD)#Tipo de enumeracion que se le da a los pines
TRIG = 16#pin al que se le conecta el trig(señal de salida de la rasp)
ECHO = 18#Pin al que se le conecta el echo(señal de entrada a la rasp) #NO ALIMENTAR CON 5V
GPIO.setup(TRIG,GPIO.OUT)#Configuramos los pines seleccionados anteriormente como salida
GPIO.setup(ECHO,GPIO.IN)#Y entrada, respectivamente
print("Distance Measurement In Progress")#Mensaje de inicio
try:#Intentamos medir distancia
    while True:#Un ciclo infinito para estar midiendo distancia constantemente
        GPIO.output(TRIG, False)#se comienza con la señal que manda el trig en bajo
        print ("Waiting For Sensor To Settle")#Mensaje indicativo de estado
        time.sleep(2)#Tiempo que indica la documentacion oficial del sensor
        GPIO.output(TRIG, True)#Indicamos la señal en alto para comenzar a medir el tiempo
        time.sleep(0.00001)#Tiempo q indica la documentación
        GPIO.output(TRIG, False)#Se termina la señal en alto
        while GPIO.input(ECHO)==0:#Se cuenta desde que el pulso de entrada está en bajo
            pulse_start = time.time()#Se almacena ese tiempo
        while GPIO.input(ECHO)==1:#Se cuenta el tiempo cuando la señal de entrada está en alto
            pulse_end = time.time()#se guarda ese tiempo
        pulse_duration = pulse_end - pulse_start#Se calcula el tiempo que se tardo en rebotar el ultrasonido
        distance = pulse_duration * 17150#Se calcula la distancia del objeto
        distance = round(distance, 2)#se redondea esa distancia a 2 decimales
        print ("Distance: ",distance,"cm")#se imprime esa distancia
except KeyboardInterrupt: # If there is a KeyboardInterrupt (when you press ctrl+c), exit the program
    print("Cleaning up!")
    GPIO.cleanup()