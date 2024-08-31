/*
  EasySevenSeg.h -  Make it easy to connect and display digits/letters on a single-digit seven-segment display
  Created by Maksym Netreba, November 18, 2021.
  Released into the public domain.
*/
#ifndef EasySevenSeg_h
#define EasySevenSeg_h

#include "Arduino.h"

class EasySevenSeg
{
    public:
        EasySevenSeg();
        bool begin();
        bool begin(int bl, int bm, int br, int d, int tr, int tm, int tl, int c);
        void printDigit(int digit);
        void printLetter(char letter);
    private:
        int _bl;    // display pin 1
        int _bm;    // display pin 2
        int _br;    // display pin 4
        int _d;     // display pin 5
        int _tr;    // display pin 6
        int _tm;    // display pin 7
        int _tl;    // display pin 9
        int _c;     // display pin 10

    void _print(int segToPrint[], int arrSize);
};

#endif
