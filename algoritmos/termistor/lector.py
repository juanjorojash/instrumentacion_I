import serial

#Serial takes these two parameters: serial device and baudrate
ser = serial.Serial('COM8', 9600)

file = open("data.csv","w")
header = "timestamp,temperature\n"
file.write(header)


with open("data.csv", "a", buffering=1) as file:
    while True:
        rawdata = (ser.readline().decode('ascii').strip('\n'))
        file.write(rawdata)
        print(rawdata)