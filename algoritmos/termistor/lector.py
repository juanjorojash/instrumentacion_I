import serial
import matplotlib.pyplot as plt
from drawnow import drawnow

#Serial takes these two parameters: serial device and baudrate
ser = serial.Serial('COM8', 9600)

file = open("data.csv","w")
header = "timestamp,temperature\n"
file.write(header)

time_data = []
T_data = []

def data_fig():
    plt.plot(time_data,T_data)

with open("data.csv", "a", buffering=1) as file:
    while True:
        rawdata = (ser.readline().decode('ascii').strip('\n'))
        hou = int(rawdata[0:2])
        min = int(rawdata[3:5])
        sec = int(rawdata[6:8])
        time = hou*3600 + min*60 + sec
        T = float(rawdata[9:14])
        time_data.append(time)
        T_data.append(T)
        file.write(rawdata)
        print(rawdata)
        drawnow(data_fig)