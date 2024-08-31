/**
 **************************************************
 * @file        Simple.ino
 * @brief       NeoPixel Ring simple sketch (c) 2013 Shae Erisson
 *              Released under the GPLv3 license to match the rest of the
 *              Adafruit NeoPixel library
 *              Original by AdaFruit Industries, modified by Soldered
 *       
 *       
 *            
 *
 * product: www.solde.red/333055, www.solde.red/333056, www.solde.red/333070, www.solde.red/333101
 * @authors     Original by Adafruit, modified by Soldered
 ***************************************************/



#include "WS2812-SOLDERED.h"

// Which pin on the Dasduino is connected to the NeoPixels?
#define PIN       6 // If you are using Dasduino Lite, you must specify that pin as PA6
#define NUMPIXELS 10

WS2812 pixels(NUMPIXELS, PIN);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup()
{
    pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop()
{
    pixels.clear(); // Set all pixel colors to 'off'

    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for (int i = 0; i < NUMPIXELS; i++)
    { // For each pixel...

        // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
        // Here we're using a moderately bright green color:
        pixels.setPixelColor(i, pixels.Color(0, 150, 0));

        pixels.show(); // Send the updated pixel colors to the hardware.

        delay(DELAYVAL); // Pause before next pass through loop
    }
}
