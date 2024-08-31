/**
 **************************************************
 *
 * @file        WS2812-SOLDERED.h
 * @brief       Header file for library functions
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Zvonimir Haramustek @ soldered.com
 ***************************************************/

#ifndef __WS2812_SOLDERED__
#define __WS2812_SOLDERED__

#include "Arduino.h"

#if defined(ARDUINO_AVR_ATtiny1604)

#include "libs/tinyNeoPixel/tinyNeoPixel.h"
class WS2812 : public tinyNeoPixel
{
  public:
    WS2812(int n, int m) : tinyNeoPixel(n, m, NEO_GRB + NEO_KHZ800)
    {
    }

    WS2812() : tinyNeoPixel(1, -1, NEO_GRB + NEO_KHZ800)
    {
        native = 0;
    }
};

#else

#include "libs/Adafruit_NeoPixel/Adafruit_NeoPixel.h"
class WS2812 : public Adafruit_NeoPixel
{
  public:
    WS2812(int n, int m) : Adafruit_NeoPixel(n, m, NEO_GRB + NEO_KHZ800)
    {
    }

    WS2812() : Adafruit_NeoPixel(1, -1, NEO_GRB + NEO_KHZ800)
    {
        native = 0;
    }
};

#endif

#endif // __WS2812_SOLDERED__
