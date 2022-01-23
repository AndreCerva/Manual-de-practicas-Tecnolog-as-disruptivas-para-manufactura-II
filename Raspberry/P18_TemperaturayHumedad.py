#sudo pip install Adafruit_DHT
from asyncio import sleep
import Adafruit_DHT
import time
DHT11=Adafruit_DHT.DHT11
PIN=4 #GPIO 4, enumeracion BOARD=7
while True:
    Humedad,Temperatura=Adafruit_DHT.read(DHT11,PIN)
    if Humedad is not None and Temperatura is not None:
        print(f'Temperatura: {Temperatura} °C, Humedad: {Humedad} % \n')
    else:
        print('Fallo en el sensor')
    sleep(5)