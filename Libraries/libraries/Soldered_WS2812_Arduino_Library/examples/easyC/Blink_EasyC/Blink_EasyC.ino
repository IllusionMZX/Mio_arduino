/**
 **************************************************
 * @file        Blink_EasyC.ino
 * @brief       Simple example of controlling the WS2812B LED pixel breakout with easyC.
 *              Connect WS2812B breakout with easyC to Dasduino or Inkplate board with easyC cable.
 *
 *              Don't have Dasduino/Inkplate/easyC? Get it here:
 *              Dasduino: https://soldered.com/categories/dasduino-arduino/
 *              Inkplate: https://soldered.com/categories/inkplate/
 *              easyC:    https://soldered.com/product/easyc-cable-20cm/
 *
 *              Looking to get support? Write on our forums: https://forum.soldered.com/
 *
 * @link        www.solde.red/333187
 * @authors     Karlo Leksic for Soldered
 ***************************************************/

// Include Soldered library
#include "WS2812-SOLDERED.h"

// If the pixel is easyC, you don't need to specify any parameters
WS2812 pixel; 

void setup()
{
    // Set the default I2C address (0x30)
    pixel.begin(0x30);

    // Set the pixel brightness (0 - 255)
    pixel.setBrightness(50);
}

void loop()
{
    // Make a color variable, arguments are: r, g and b component
    uint32_t color = pixel.Color(255, 0, 150); 

    // Set the pixel color 
    pixel.setPixelColor(0, color); 

    // Delay before turning off the pixel
    delay(500);

    // Turn off the pixel (same as pixel.Color(0, 0, 0, 0);)
    pixel.clear();

    // Delay before turning on the pixel
    delay(500);
}