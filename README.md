TreadmillIno
============

Arduino project to control my walking desk treadmill better than
the builtin controller.

Simply reads the required percentage of full speed via the serial port
and uses PWM on port 9 to control the motor. The LED attached to port
13 is also lit to the same value.

The requested value is stored in EEPROM so that when power is applied
the last speed is automatically set again.
