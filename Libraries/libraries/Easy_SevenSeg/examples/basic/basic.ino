/*
 * Basic example. Shows how to print digits and some letters on a single-digit seven-segment display
 *
 * By default the display pins corresponds to Arduino pins as following:
 *      display pin 1 == A1 on Arduino
 *      display pin 2 == A2 on Arduino
 *      display pin 4 == A4 on Arduino
 *      display pin 5 == A5 on Arduino
 *      display pin 6 == 6 on Arduino
 *      display pin 7 == 7 on Arduino
 *      display pin 9 == 9 on Arduino
 *      display pin 10 == 10 on Arduino
 *
 *      display pins 3 and 8 connect to GND via 220 Ohm resistor
 *
 *  You may setup custom pins. See the "customPins" example
 */

#include <EasySevenSeg.h>   // Include library

EasySevenSeg myDisplay;     // Initialize class

void setup() {
    // The "begin" method is required to set pinMode(OUTPUT)
    // Without arguments it uses default pins (details above)
    myDisplay.begin();

    // Just pass digit to print it
    for (int i=9; i>=0; i--) {
        myDisplay.printDigit(i);
        delay(1000);
    }

    // Just pass letter to print it
    char letters[] = "ABCDEF";
    for (int i=0; i<6; i++) {
        myDisplay.printLetter(letters[i]);
        delay(1000);
    }
}

void loop() {}
