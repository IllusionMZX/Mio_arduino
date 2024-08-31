/**
 **************************************************
 * @file        Simple_New_Operator.ino
 * @brief       NeoPixel Ring simple sketch (c) 2013 Shae Erisson
 *              Released under the GPLv3 license to match the rest of the
 *              Adafruit NeoPixel library
 *              This sketch shows use of the "new" operator with Adafruit_NeoPixel.
 *              It's helpful if you don't know NeoPixel settings at compile time or
 *              just want to store this settings in EEPROM or a file on an SD card.
 *       
 *       
 *            
 *
 * product: www.solde.red/333055, www.solde.red/333056, www.solde.red/333070, www.solde.red/333101
 * @authors     Original by Adafruit, modified by Soldered
 ***************************************************/

#include "WS2812-SOLDERED.h"

// Which pin on the Dasduino is connected to the NeoPixels?
int pin = 6; // If you are using Dasduino Lite, you must specify that pin as PA6

// How many NeoPixels are attached to the Dasduino?
int numPixels = 10; // Popular NeoPixel ring size


// Rather than declaring the whole NeoPixel object here, we just create
// a pointer for one, which we'll then allocate later...
WS2812 *pixels;

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup()
{
    // Right about here is where we could read 'pin', 'numPixels' and/or
    // 'pixelFormat' from EEPROM or a file on SD or whatever. This is a simple
    // example and doesn't do that -- those variables are just set to fixed
    // values at the top of this code -- but this is where it would happen.

    // Then create a new NeoPixel object dynamically with these values:
    pixels = new WS2812(numPixels, pin);

    // Going forward from here, code works almost identically to any other
    // NeoPixel example, but instead of the dot operator on function calls
    // (e.g. pixels.begin()), we instead use pointer indirection (->) like so:
    pixels->begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
                     // You'll see more of this in the loop() function below.
}

void loop()
{
    pixels->clear(); // Set all pixel colors to 'off'

    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for (int i = 0; i < numPixels; i++)
    { // For each pixel...

        // pixels->Color() takes RGB values, from 0,0,0 up to 255,255,255
        // Here we're using a moderately bright green color:
        pixels->setPixelColor(i, pixels->Color(0, 150, 0));

        pixels->show(); // Send the updated pixel colors to the hardware.

        delay(DELAYVAL); // Pause before next pass through loop
    }
}
