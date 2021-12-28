#arduino-stepper

## Original idea

Camera stand that can rotate and turn up and down to capture and identify
objects anywhere in the room, through AI/ML software.

## Prototype

![prototype stand](./media/stand-prototype.jpg)
![prototype stand socket](./media/stand-prototype2.jpg)


Handcrafted from plywood, with dense wood to connect to the motor axis.
Rotor diameter is 20cm, height is approx. 16cm.

Two 4-wire stepper motors, connect to Arduno Uno via pins 2-5 (a1-4) and
6-9 (b1-4) through ULN2003 drivers. Arduino is bus powered, motors use
external 5V power supply. With the built in gear the motor requires 512
full steps for a 360° turn.

Load serial4stepper.ino into the Arduino. It should appear as /dev/ttyACM0.
Use arduino-serial.py to send commands, one per line:

* l - left
* r - right
* u - up
* d- down 
* (number) - sets the step size for all following operations
* rot - returns the hardware counter for rotation
* ele - returns the hardware counter for elevation
* reset - resets the hardware counters and returns "OK"

## Next

CAD layout and 3d-printed stand with better bearings and less play, cabling
that allows 360° turns.
