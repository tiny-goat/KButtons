/* tiny's KButtons v1.0
 * -----------------
 *  Written by MattC.
 *  https://github.com/mattcuk/IRtranslator
 *  Arduino IR Translator. Converts incoming IR codes from one manufacturer to another set of IR codes from a different manufacturer.
 */

#include <IRremote.h> // >v3.0.0

#define PIN_RECV 11
#define PIN_SEND 3
#define SHIFTLED 6

void setup()  
{ 
  Serial.begin(115200); // initialize serial connection to print on the Serial Monitor of the Arduino IDE
  Serial.print("Initialise IrSender at Pin ");
  Serial.println(PIN_SEND);
  IrSender.begin(PIN_SEND, true); // initialise the IR sender
  Serial.print("Initialise IrReceiver at Pin ");
  Serial.println(PIN_RECV);
  IrReceiver.begin(PIN_RECV, true); // initializes the IR receiver
  
  pinMode(SHIFTLED, OUTPUT);
  delay(5300); 
  analogWrite(SHIFTLED, 15);
}  

int sendDelay = 1; // This can be adjusted (increased from 5) if you have issues with the spacing of IR transmits & your equipment seeing multiple sends as one long code
bool shiftState = false;

void loop()  {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial); 
    IrReceiver.compensateAndPrintIRResultAsCArray(&Serial, true);

          //button 1
          if (IrReceiver.decodedIRData.command == 0x1C) {
              Serial.println("Received Cancel .. sending alternative command");
              IrSender.sendNEC(0x205F34CB, 32);
              delay(sendDelay);
          //button 2
          } else if (IrReceiver.decodedIRData.command == 0x18) {
              Serial.println("Received 1 .. sending alternative command");
              IrSender.sendNEC(0x205FB847, 32);
              delay(sendDelay);
          //button 3
          } else if (IrReceiver.decodedIRData.command == 0x15) {
              Serial.println("Received 2 .. sending alternative command");
              IrSender.sendNEC(0x205F38C7, 32);
              delay(sendDelay);
          //button 4
          } else if (IrReceiver.decodedIRData.command == 0x12) {
              Serial.println("Received 3 .. sending alternative command");
              IrSender.sendNEC(0x205F649B, 32);
              delay(sendDelay);
          }
          //button 5
          else if (IrReceiver.decodedIRData.command == 0x13) {
              Serial.println("Received 4 .. sending alternative command");
              IrSender.sendNEC(0x205FA847, 32);
              delay(sendDelay);
          }
          //button 6
          else if (IrReceiver.decodedIRData.command == 0x1) {
              Serial.println("Received 5 .. sending alternative command");
              IrSender.sendNEC(0x205F28D7, 32);
              delay(sendDelay);
          }
          //button 7
          // PLUS
          else if (IrReceiver.decodedIRData.command == 0x2) {
              Serial.println("Received + .. sending alternative command");
              if (shiftState) {
              IrSender.sendNEC(0x205F48B7, 32);
              } else {
              IrSender.sendNEC(0x205F847B, 32);
              }
              delay(sendDelay);
          }
          //button 8
          // SHIFT FUNCTION HERE
          else if (IrReceiver.decodedIRData.command == 0x14) {
              Serial.println("Received Shift!");
              shiftState = !shiftState;
              shiftStatusLED();
              Serial.println("Switched state to ");
              Serial.print(shiftState ? "On" : "Off");
          }
          //button 9
          else if (IrReceiver.decodedIRData.command == 0x1B) {
              Serial.println("Received 6 .. sending alternative command");
              IrSender.sendNEC(0x205FA45B, 32);
              delay(sendDelay);
          }
          //button 10
          else if (IrReceiver.decodedIRData.command == 0x5E) {
              Serial.println("Received 7 .. sending alternative command");
              IrSender.sendNEC(0x205F00FF, 32);
              delay(sendDelay);
          }
          //button 11
          else if (IrReceiver.decodedIRData.command == 0x55) {
              Serial.println("Received 8 .. sending alternative command");
              IrSender.sendNEC(0x205FF807, 32);
              delay(sendDelay);
          }
          //button 12
          else if (IrReceiver.decodedIRData.command == 0x6) {
              Serial.println("Received 9 .. sending alternative command");
              IrSender.sendNEC(0x205FD827, 32);
              delay(sendDelay);
          }
          //button 13
          else if (IrReceiver.decodedIRData.command == 0x5D) {
              Serial.println("Received 0 (key) .. sending alternative command");
              IrSender.sendNEC(0x205F7887, 32);
              delay(sendDelay);
          }
          //button 14
          // MINUS
          else if (IrReceiver.decodedIRData.command == 0x5) {
              Serial.println("Received - .. sending alternative command");
              if (shiftState) {
              IrSender.sendNEC(0x205F22DD, 32);                
              } else {
              IrSender.sendNEC(0x205F04FB, 32);
              }
              delay(sendDelay);
          }
          //button 15
          else if (IrReceiver.decodedIRData.command == 0x8) {
              Serial.println("Received Start .. sending alternative command");
              IrSender.sendNEC(0x205F58A7, 32);
              delay(sendDelay);
          }
          //button 16
          else if (IrReceiver.decodedIRData.command == 0x1A) {
              Serial.println("Received Stop .. sending alternative command");
              IrSender.sendNEC(0x205F14EB, 32);
              delay(sendDelay);
          }
          //button 17
          else if (IrReceiver.decodedIRData.command == 0xD) {
              Serial.println("Received Melody (key) .. sending alternative command");
              IrSender.sendNEC(0x205FFC03, 32);
              delay(sendDelay);
          }
          //button 18
          else if (IrReceiver.decodedIRData.command == 0x4D) {
              Serial.println("Received BGV (key) .. sending alternative command");
              IrSender.sendNEC(0x205F50AF, 32);
              delay(sendDelay);
          }
    Serial.println("");
    Serial.flush();
    IrReceiver.resume(); // Receive the next IR signal
  }
}

void shiftStatusLED() {
  if(shiftState) {
    analogWrite(SHIFTLED, 255);
  } else {
    analogWrite(SHIFTLED, 15);
  }
}
