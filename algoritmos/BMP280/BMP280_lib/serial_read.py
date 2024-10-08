import serial
from datetime import datetime

arduino = serial.Serial('COM3')

datos = []

for i in range(10):
    dato = arduino.readline()[:-2].decode('utf-8').split(',')
    datos.append([datetime.now().strftime(format="%Y-%m-%d %H:%M:%S"), float(dato[0]),float(dato[1])])

print(datos)