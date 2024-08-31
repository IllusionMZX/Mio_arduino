/**
 **************************************************
 * @file        Rainbow_EasyC.ino
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

// The variable that holds color hue
uint16_t hue = 0;

void setup()
{
    // Set the default I2C address (0x30)
    pixel.begin(0x30);

    // Set the pixel brightness (0 - 255)
    pixel.setBrightness(50);
}

void loop()
{
    // Make a color variable with custom hue
    uint32_t color = pixel.ColorHSV(hue); 

    // Set the pixel color to the color passed in the function
    pixel.setPixelColor(0, color);    

    // The delay between changing the color hue (number must be small to see changes e.g. c 20ms)    
    delay(20); 

    // The HUE values are between 0 and 65535 and this is the step of changing those values
    // When reaches 65565 it resets to 0 automatically because of the variable type (uint16_t)
    hue += 256;       
}