# Nixie Tube Clock Documentation
Here is the documentation of how the project was created.

This project was heavily based on a youtuber's nixie tube clock.

Credit: GreatScott!
https://www.youtube.com/watch?v=ObgmVNV1Kfg 

## Process of Designing
First steps I started with creating a PCB which was essentially GreatScott's PCB but then retrofitted so that it fits with the parts that I have at hand.
![Image of the Schematic](Schematics&Pictures/Schematic_Nixie-Tube_2024-09-21.png)
From this original schematic there were a couple changes that I had to make while designing the PCB. I had changed a couple of the outputs for the IC drivers so that routing for the PCB was a lot easier, and I had also changed the resistors for the nixie tubes to be 20K ohms, so that it can sustain the 2.5mA as 10K actually provides it way too much current. Also in the final design, I decided for better visability, I connected the filtering capacitors to ground and to the input/output just so that following the schematic would be easier.

After Completing the Schematic I then started with designing the PCB and placing them in the correct spots.
![Image of unfinished PCB](Schematics&Pictures/PCBDesign.png)
Here is the raw PCB without traces, copper layers added, and correct measurements or placement for the parts. 

This is what the PCB looks like after I have routed all of the traces.
![Image of routed PCB](Schematics&Pictures/RoutedPcb.png)

After which I then added the copper layers for GND net and 5V net
![Image of routed PCB with copper layers](Schematics&Pictures/Copperlayered.png)
## Building the Physical Circuit

I then started to test the components to make sure they work. In this picture I built a simple circuit to test the bulb by using my step up voltage converter to bring my 12V DC power supply to 170V. I also soldered on a 10K resistor as the operating voltage of the bulb needs to be a minimum 120V while the firing voltage is 170V. The resistor there is to save some power, as I don't constantly want to use 170V to save on power.  
![Image of bulbs powered](Schematics&Pictures/5.png) 
![Image of bulbs powered](Schematics&Pictures/6.png)
![Image of bulbs powered](Schematics&Pictures/7.png)

I also tested to see if the K155ID1 driver ICs were working, which I hooked up my arduino to the IC, then programmed it to test if selecting the number 1 worked, which it did as I saw that on that pin it drove the voltage down. The way that I can select numbers is based off of a truth table as seen below.

![Image of IC truth table](Schematics&Pictures/truth.png)

Then after I received the PCB from JLCPCB, I started to solder on all of the components.

![Image of soldering the PCB](Schematics&Pictures/Building.jpg)

Here you can see how I soldered on the capacitors, the resistors, the voltage regulator. the 12V power supply, and the pins to the arduino. The capacitors are way out of place because I ended up ordering the wrong capacitors, which I have the 1206 capacitors while my schematic has 0603 capacitors. I tested out the voltage levels to ensure that I am getting the correct voltages across the capacitors, and the 12V regulator. I then started to solder everything else on the board

![Image of finished product](Schematics&Pictures/CircuitBuilt.jpg)

Here is the front side of the PCB, which I have finished soldering on all of the other components, which then I uploaded the code for reading time and displaying which it came out perfectly. I was a little concerned about the fittings of the holes in my PCB, which next time I work on a PCB I will definitely make sure the clearance isn't so close for things like wire gauges. Other than that I used sockets for the bulbs so that it has a lot more clearance, which now I can call this product almost complete.

## Finished Product

After soldering and testsing the PCB, I then began with a housing for the clock, then I will call this complete.


## List of items used
K155ID1 IC nixie tube drivers
IN-12A Nixie Tubes
Arduino Pro Mini
DS1307 RTC 
LM7805 Voltage Regulator
1206 SMD capacitors
20K Ohm Resistors
NCH6100HV step-up voltage converter
12V DC power supply




