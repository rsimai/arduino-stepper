#!/usr/bin/python

import serial

ser = serial.Serial('/dev/ttyACM0')
ser.baudrate = 9600

while True:
    cmd = input('Command (l,r,u,d,exit) : ')
    if cmd == "exit":
        exit()
    ser.write(cmd.encode())
    ser.write(b'\n')
    ser.flush()

ser.close()

