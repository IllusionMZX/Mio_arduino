/*
 * Example shows how to setup custom Arduino pins for a single-digit seven-segment display
 */

#include <EasySevenSeg.h>   // Include library

EasySevenSeg myDisplay;     // Initialize class

void setup() {
    // The "begin" method is required to set pinMode(OUTPUT)
    // To setup custom pins provide pin numbers that correspond to display pins from 1 to 10
    // Display pin #1 is bottom left one. Display pin #6 in top right one
    // Should be 8 arguments in sum. DISPLAY PINS 3 AND 8 ARE OMITTED, SINCE THEY ARE GND
    myDisplay.begin(2,3,4,5,6,7,8,9);

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
