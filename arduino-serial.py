#!/usr/bin/python

import serial

ser = serial.Serial('/dev/ttyACM0',timeout=1)
ser.baudrate = 9600

while True:
    cmd = input('Command ([number],l,r,u,d,rot,ele,reset,exit) : ')
    if cmd == "exit":
        exit()
    ser.write(cmd.encode())
    ser.write(b'\n')
    ser.flush()
    if ( cmd == "rot" ) or ( cmd == "ele" ) or ( cmd == "reset" ):
        line = ser.readline().decode('utf-8').rstrip()
        print (line)
ser.close()

