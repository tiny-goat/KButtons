# KButtons
__KButtons IR Translator For Karaoke__ - Converts incoming IR codes from one player manufacturer to another. You can use the Arduino source code to define the inbound IR codes you want to capture & have another IR code sent out. This lets you translate from one player manufacturer to another.

I had thoughts of this project when i realized that karaoke machine users mainly have to use a specific "Button PCB" that is very much closed-source but is basically a hand remote but with extra steps.

Main issue is if they want to switch to another player brand, they very much have to remove the old PCB and rewire the new one all over again, and thinking about it, should it be easier if it could be just an arduino translating the IR codes instead?

# Features

KButtons has a distinguishing feature, mainly called "SHIFT". This functionality allows you to have a 2nd set of functions off of the same button, similar to a computer's keyboard.
This is a **toggle** feature, meaning you only press it once to enable the SHIFT layer, and press it once again to revert back to the original button functions. Pretty neat, right?

## Notes

The source code currently accomodates translating from a generic IR Board to IR Commands for a MNation player. You can modify the code to further suit your needs.

# Parts List

This project is pretty simple.. you can substitute the KY-005 with an IR LED and NPN transistor if you like.

1. Arduino (any should be fine.. I'm using a Nano)
2. IR receiver (VS1838, or similar)
3. IR transmitter (KY-005)
4. LED (for SHIFT indicator)
5. Wires & breadboard (breadboard is optional, you can hardwire everything yourself, if you so choose.)

# Requirements (Software)
1. Arduino IDE
2. IRremote (Please use library version 3.0.0, v4 isnt compatible with this code.)

For instructions, you can check out the original repo!
