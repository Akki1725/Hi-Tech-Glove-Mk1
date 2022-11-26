import serial

s = serial.Serial("COM7", 9600)

while True:
    s.flushInput()
    s.flush()
    s.flushOutput()
    a = s.readline()
    print(a)