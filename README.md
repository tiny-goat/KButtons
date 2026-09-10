# KButtons
__KButtons IR Translator For Karaoke__ - Converts incoming IR codes from one player manufacturer to another. You can use the Arduino source code to define the inbound IR codes you want to capture & have another IR code sent out. This lets you translate from one player manufacturer to another.

I had thoughts of this project when i realized that karaoke machine users mainly have to use a specific "Button PCB" that is obviously closed-source but is basically a hand remote but with extra steps.

Main issue is if they want to switch to another player brand, they very much have to remove the old PCB and rewire the new one all over again, and thinking about it, should it be easier if it could be just an arduino translating the IR codes instead?

# Features

KButtons has a distinguishing feature, mainly called "SHIFT". This functionality allows you to have a 2nd set of functions off of the same button, similar to a computer's keyboard.
This is a **toggle** feature, meaning you only press it once to enable the SHIFT layer, and press it once again to revert back to the original button functions. Pretty neat, right?

Another addition is an LED indicator for this new SHIFT functionality, to let you know if your system is in a SHIFT state.

## Notes

The source code currently accomodates translating from a generic IR Board to IR Commands for a MNation player. You can modify the code to further suit your needs.
There is an included IR extraction sketch to easily get your IR codes on the same arduino before you go ahead and flash the main KButtons sketch.

# Parts List

This project is pretty simple.. you can substitute the KY-005 with an IR LED and NPN transistor if you like.

1. Arduino (any should be fine.. I'm using a Nano)
2. IR receiver (VS1838, or similar)
3. IR transmitter (KY-005)
4. LED and a accompanying series resistor (for SHIFT indicator)
5. Wires & breadboard (breadboard is optional, you can hardwire everything yourself, if you so choose.)

## Wiring & Setup

This assumes that you already know how to setup an Arduino. 
If not, please refer to the original ![repo](https://github.com/mattcuk/IRtranslator/) first!

1. Connect (OUT) Pin 1 of your IR Receiver to Pin 11 of the Arduino, Then (GND) Pin 2 to GND, and (VCC) Pin 3 to Arduino's VCC
2. Connect VCC of your IR transmitter to Arduino Pin 3, then its GND to GND.
3. If you'd like, you can connect an LED with a series resistor to Pin 6.

4. Point the IR reciever to the target IR sending device, in this case, the Button PCB.
5. Point the IR transmitter to the target IR receiving device, your player.
6. Use the IR extraction sketch to extract the select buttons of both 2 target devices, and take note of the IR codes;
7. And then write those to your main KButtons sketch file and finally flash that one to your Arduino of choice.

8. If all works out, you should get functionality that would otherwise would've required you rewiring an entire button system!

## Requirements (Software)
1. Arduino IDE
2. IRremote (Please use library version 3.0.0, as v4 isnt compatible with this code.)
