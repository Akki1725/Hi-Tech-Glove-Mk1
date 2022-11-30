
import serial
import pyautogui
import time

s = serial.Serial("COM7", 9600)
SCREEN_DIMENSIONS = (1366, 768)

def refine(data):
    data = str(data)
    data = data.replace("b", "")
    data = data.replace("'", "")
    data = data.replace("r", "")
    data = data.replace("n", "")
    data = data.replace("\\", "")
    return data

def to_pixel_coords(relative_coords):
    return tuple(round(coord * dimension) for coord, dimension in zip(relative_coords, SCREEN_DIMENSIONS))

while True:
    data = s.readline()
    data = refine(data)
    info = list(data.split(" "))

    try:
        xStr = info[0]
        yStr = info[1]
        zStr = info[2]
        leftBtn = info[3]
        rightBtn = info[4]
        x = int(float(xStr))
        y = int(float(yStr))
        sw = int(float(info[5]))

        if y <= -35:
            pyautogui.move(0, -30)
        elif y >= 80:
            pyautogui.move(0, 30)
        elif x >= 75:
            pyautogui.move(-30, 0)
        elif x <= -60:
            pyautogui.move(30, 0)
        if (sw == 0):
            pyautogui.leftClick()

        print(x, y)
        s.flushInput()

    except:
        None