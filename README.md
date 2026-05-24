# Megadrive Tiny Switchless region mod

The mod uses Arduino framework and could be used with various devices that supports it.

To build this and flash to the IC you'll need *Arduino IDE*.

The current configuration is for **AtTiny13A**.

![schematic](attiny13A.jpg)

For the Megadrive I you need to cut traces that connect JP3/JP4 and JP1/JP2 to ground or 5V(depending on region)
Also trace that connects reset button to the cpu also needs to be cut.

To flash the program to IC you can use Arduino Uno connected like this:

![Arduino uno attiny13A](ArduinoUnoConnected.jpg)

More info how to use Arduino Uno as attiny programmer here:
https://www.instructables.com/Updated-Guide-on-How-to-Program-an-Attiny13-or-13a/ 
