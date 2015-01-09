# Neopixel60Clock


![my image](Sniffy12/Neopixel60Clock/blob/master/Clock%20Diagram.png)
Created a clock that runs on an DS1307 RealTime Clock.  
It has 4 different clock forms, selectable via button press.  
The seconds, minutes, and hour can be adjusted with button presses as well.  
This reprograms the RTC.  
A 4th button allows the use of a potentiometer to set the 
brightness of different parts of the clock (as well as choosing colors to display on the clock).  
A photoresistor also detects room brightness and adjusts the clock intensity accordingly.


The folder contains several tabs for the same sketch.  Drop the folder into your Arduino folder
and open from there.

The clock uses a small library I put together to read and set the minutes, seconds, and hours.
It is included here.

Each clock requires an initial time update and a final strip.show(), this is handled
outside of each clocks function.  Keep that in mind if you wanted to take a single clock
and repurpose it.
