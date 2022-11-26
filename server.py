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

def translate(value, leftMin, leftMax, rightMin, rightMax):
    # Figure out how 'wide' each range is
    leftSpan = leftMax - leftMin
    rightSpan = rightMax - rightMin

    # Convert the left range into a 0-1 range (float)
    valueScaled = float(value - leftMin) / float(leftSpan)

    # Convert the 0-1 range into a value in the right range.
    return rightMin + (valueScaled * rightSpan)


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
        left = int(leftBtn)
        right = int(rightBtn)

        if y <= -35:
            pyautogui.move(0, -30)
        elif y >= 80:
            pyautogui.move(0, 30)
        elif x >= 75:
            pyautogui.move(-30, 0)
        elif x <= -60:
            pyautogui.move(30, 0)

        if left == 0:
            pyautogui.leftClick()
        elif right == 0:
            pyautogui.rightClick()

        print(x, y, left, right)
        s.flushInput()

    except:
        None