/*
  EasySevenSeg.cpp - Make it easy to connect and display digits/letters on a single-digit seven-segment display
  Created by Maksym Netreba, November 18, 2021.
  Released into the public domain.
*/
#include "Arduino.h"
#include "EasySevenSeg.h"

EasySevenSeg::EasySevenSeg() {}

bool EasySevenSeg::begin() {
    return begin(A1, A2, A4, A5, 6, 7, 9, 10);
}

bool EasySevenSeg::begin(int bl, int bm, int br, int d, int tr, int tm, int tl, int c)
{
    _bl = bl;
    _bm = bm;
    _br = br;
    _d = d;
    _tr = tr;
    _tm = tm;
    _tl = tl;
    _c = c;

    pinMode(_bl, OUTPUT);
    pinMode(_bm, OUTPUT);
    pinMode(_br, OUTPUT);
    pinMode(_d, OUTPUT);
    pinMode(_tr, OUTPUT);
    pinMode(_tm, OUTPUT);
    pinMode(_tl, OUTPUT);
    pinMode(_c, OUTPUT);

    return true;
}

void EasySevenSeg::_print(int segToPrint[], int arrSize)
{
    const int NUM_OF_SEG = 7 + 1;
    int ALL_SEGMENTS[NUM_OF_SEG] = {_bl, _bm, _br, _d, _tr, _tm, _tl, _c};

    for (int i = 0; i < arrSize; i++) {
        digitalWrite(segToPrint[i], HIGH);
    }

    const int remainderArrSize = NUM_OF_SEG - arrSize;
    int remainderSeg[remainderArrSize];
    int counter = 0;

    for (int i = 0; i < NUM_OF_SEG; i++) {
        bool isSegmentFound = false;

        for (int j = 0; j < arrSize; j++) {
            if (ALL_SEGMENTS[i] == segToPrint[j]) {
                isSegmentFound = true;
                break;
            }
        }

        if (isSegmentFound) continue;

        remainderSeg[counter] = ALL_SEGMENTS[i];
        counter += 1;
    }

    for (int i = 0; i < remainderArrSize; ++i) {
        digitalWrite(remainderSeg[i], LOW);
    }
}

void EasySevenSeg::printDigit(int digit)
{
    int _digitZero[6] = {_bl, _bm, _br, _tr, _tm, _tl};
    int _digitOne[2] = {_br, _tr};
    int _digitTwo[6] = {_bl, _bm, _d, _tr, _tm, _c};
    int _digitThree[6] = {_bm, _br, _d, _tr, _tm, _c};
    int _digitFour[4] = {_br, _tr, _tl, _c};
    int _digitFive[6] = {_br, _bm, _d, _tl, _tm, _c};
    int _digitSix[7] = {_bl, _bm, _br, _d, _tm, _tl, _c};
    int _digitSeven[3] = {_br, _tr, _tm};
    int _digitEight[7] = {_bl, _bm, _br, _tr, _tm, _tl, _c};
    int _digitNine[7] = {_bm, _br, _d, _tr, _tm, _tl, _c};

    switch (digit) {
        case 0:
            _print(_digitZero, sizeof(_digitZero) / sizeof(_digitZero[0]));
            break;
        case 1:
            _print(_digitOne, sizeof(_digitOne) / sizeof(_digitOne[0]));
            break;
        case 2:
            _print(_digitTwo, sizeof(_digitTwo) / sizeof(_digitTwo[0]));
            break;
        case 3:
            _print(_digitThree, sizeof(_digitThree) / sizeof(_digitThree[0]));
            break;
        case 4:
            _print(_digitFour, sizeof(_digitFour) / sizeof(_digitFour[0]));
            break;
        case 5:
            _print(_digitFive, sizeof(_digitFive) / sizeof(_digitFive[0]));
            break;
        case 6:
            _print(_digitSix, sizeof(_digitSix) / sizeof(_digitSix[0]));
            break;
        case 7:
            _print(_digitSeven, sizeof(_digitSeven) / sizeof(_digitSeven[0]));
            break;
        case 8:
            _print(_digitEight, sizeof(_digitEight) / sizeof(_digitEight[0]));
            break;
        case 9:
            _print(_digitNine, sizeof(_digitNine) / sizeof(_digitNine[0]));
            break;
    }
}

void EasySevenSeg::printLetter(char letter)
{
    int _letterA[6] = {_bl, _br, _tr, _tm, _tl, _c};
    int _letterB[5] = {_bl, _br, _bm, _tl, _c};
    int _letterC[4] = {_bl, _bm, _tm, _tl};
    int _letterD[5] = {_bl, _bm, _br, _tr, _c};
    int _letterE[5] = {_bl, _bm, _tm, _tl, _c};
    int _letterF[4] = {_bl, _tm, _tl, _c};

    switch (letter) {
        case 'A':
        case 'a':
            _print(_letterA, sizeof(_letterA) / sizeof(_letterA[0]));
            break;
        case 'B':
        case 'b':
            _print(_letterB, sizeof(_letterB) / sizeof(_letterB[0]));
            break;
        case 'C':
        case 'c':
            _print(_letterC, sizeof(_letterC) / sizeof(_letterC[0]));
            break;
        case 'D':
        case 'd':
            _print(_letterD, sizeof(_letterD) / sizeof(_letterD[0]));
            break;
        case 'E':
        case 'e':
            _print(_letterE, sizeof(_letterE) / sizeof(_letterE[0]));
            break;
        case 'F':
        case 'f':
            _print(_letterF, sizeof(_letterF) / sizeof(_letterF[0]));
            break;
    }
}