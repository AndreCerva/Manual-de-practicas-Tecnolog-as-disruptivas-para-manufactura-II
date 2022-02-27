yimport RPi.GPIO as GPIO#Importar libreria para haceruso de la Raspberry
from time import sleep#Tiempo de espera entre instrucciones
GPIO.setwarnings(False)#desactivar las advertencias
GPIO.setmode(GPIO.BOARD)#Tipo de enumeracion de la raspberry
Filas=[37,35,33,31]#Pines en donde se van a conectar las filas del teclado 
for i in range (4):#ciclo para recorrer todo el arreglo de los pines de filas
	GPIO.setup(Filas[i], GPIO.OUT)	#Configuramos todos los pines como salidas de la raspberry
Columnas=[40,38,36,32]#Pines donde conectaremos las salidas de la raspberry
for j in range (4):#ciclo para reccorer todas los elementos del arreglo columnas
	GPIO.setup(Columnas[j], GPIO.IN, pull_up_down=GPIO.PUD_DOWN)#Configuramos todas las entradas como pulldown para que se activen cuano reciban el voltaje en alto
def lectura(FILAS,CARACTERES):#función para leer las entradas del teclado
	GPIO.output(FILAS,GPIO.HIGH)#se alimentan todas las filas del teclado
	if (GPIO.input(Columnas[0])==1):#se lee la primer columna
		print(CARACTERES[0])#se imprime el valor detectado
	if (GPIO.input(Columnas[1])==1):#se lee la segunda columna
		print(CARACTERES[1])#se imprime el valor detectado
	if (GPIO.input(Columnas[2])==1):#se lee la tercer columna
		print(CARACTERES[2])#se imprime el valor detectado
	if (GPIO.input(Columnas[3])==1):#se lee la cuarta columna
		print(CARACTERES[3])#se imprime el valor detectado
	GPIO.output(FILAS,GPIO.LOW)#se pone en bajo el valor de las salidas en las filas del teclado
try:
	while True:
		lectura(Filas[0],["1","2","3","A"])#mandamos a llamar a la función para cada respectiva fila
		lectura(Filas[1],["4","5","6","B"])
		lectura(Filas[2],["7","8","9","C"])
		lectura(Filas[3],["*","0","#","D"])
		sleep(0.1)#Sensibilidad 
except KeyboardInterrupt:
	print("\nEl programa termino")
