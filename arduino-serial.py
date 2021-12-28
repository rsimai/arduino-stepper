#!/usr/bin/python

import serial

ser = serial.Serial('/dev/ttyACM0')
ser.baudrate = 9600

while True:
    cmd = input('Command: ')
    ser.write(cmd.encode())
    ser.flush()

ser.close()

