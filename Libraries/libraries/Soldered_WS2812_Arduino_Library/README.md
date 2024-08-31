# WS2812 Arduino library

[![Make docs and publish to GitHub Pages](https://github.com/SolderedElectronics/Soldered-WS2812-Smart-Leds-Arduino-Library/actions/workflows/make_docs.yml/badge.svg?branch=dev)](https://github.com/SolderedElectronics/Soldered-WS2812-Smart-Leds-Arduino-Library/actions/workflows/make_docs.yml)
[![Arduino Library Manager Compatibility](https://github.com/SolderedElectronics/Soldered-WS2812-Smart-Leds-Arduino-Library/actions/workflows/arduino_lint.yml/badge.svg?branch=dev)](https://github.com/SolderedElectronics/Soldered-WS2812-Smart-Leds-Arduino-Library/actions/workflows/arduino_lint.yml)


| ![Smart LED WS2812B Pixel](https://upload.wikimedia.org/wikipedia/commons/8/8f/Example_image.svg) |
| :-----------------------------------------------------------------------------------------------: |
|                [Smart LED WS2812B Pixel](https://www.solde.red/333054)                            |

| ![Smart LED WS2812B Ring7](https://github.com/SolderedElectronics/Smart-LED-WS2812B-Ring7-hardware-design/blob/main/OUTPUTS/V1.1.1/333055.jpg) |
| :--------------------------------------------------------------------------------------------------------------------------------------------: |
|                                   [Smart LED WS2812B Ring7](https://www.solde.red/333055)                                                      |

| ![Smart LED WS2812B Stick10](https://github.com/SolderedElectronics/Smart-LED-WS2812B-Stick10-hardware-design/blob/main/OUTPUTS/V1.0.0/333056.jpg) |
| :------------------------------------------------------------------------------------------------------------------------------------------------: |
|                                    [Smart LED WS2812B Stick10](https://www.solde.red/333056)                                                       |

| ![Smart LED WS2812B Ring12](https://upload.wikimedia.org/wikipedia/commons/8/8f/Example_image.svg) |
| :------------------------------------------------------------------------------------------------: |
|                   [Smart LED WS2812B Ring12](https://www.solde.red/333070)                         |

| ![Smart LED WS2812B Ring24](https://upload.wikimedia.org/wikipedia/commons/8/8f/Example_image.svg) |
| :------------------------------------------------------------------------------------------------: |
|                      [Smart LED WS2812B Ring24](https://www.solde.red/333101)                      |

| ![Smart LED WS2812B Ring24](https://upload.wikimedia.org/wikipedia/commons/8/8f/Example_image.svg) |
| :------------------------------------------------------------------------------------------------: |
|                    [WS2812B breakout with easyC](https://www.solde.red/333187)                     |

These small LEDs are not just ordinary lights - each is specific because it has a built-in small integrated circuit (IC) that is able to turn on the LED light in 16 million different colors. IC is WS2812 and it uses a single wire can control thousands of these LEDs. With a little imagination by putting these pixels, you get superior effects with a minimum effort. These lamps are easy to control with Croduino.

- Color: RGB (red/green/blue)
- Voltage: 5V
- Power: max. 60mA/pixel
- Diode type: WS2812 SMD LED (5050 LED diode with built IC)
- Dimensions: diameter of 10 mm

WS2812B is an extremely interesting LED that can emit light in red, green or blue - or any combination of these three colors, able to show a total of approximately 16 million different colors. On this board, diodes are arranged in a circle. They are controlled by a single pin with only a few lines of code from Arduino IDE. That's possible thanks to the integrated controller inside the LED itself!

- Number of LEDs: 7
- Circle diameter: 23mm
- Voltage: 5V
- LED type: WS2812B
- Current: 18mA per LED

WS2812B is an extremely interesting LED that can emit light in red, green or blue - or any combination of these three colors, able to show a total of approximately 16 million different colors. On this board, diodes are arranged in a line of 10. You can even connect these sticks in a line. They are controlled by a single pin with only a few lines of code from Arduino IDE. That's possible thanks to the integrated controller inside the LED itself!

- Number of LEDs: 10
- Voltage: 5V
- LED type: WS2812B
- Current: max 60mA per LED
- Dimensions: 80 x 10 mm

WS2812B is an extremely interesting LED that can emit light in red, green or blue - or any combination of these three colors, able to show a total of approximately 16 million different colors. On this board diodes are arranged in a circle. They are controlled by a single pin with only few lines of code from Arduino IDE. That's possible thanks to the integrated controller inside the LED itself!

- Number of LEDs: 12
- Circle outer diameter: 40mm
- Voltage: 5V
- LED type: WS2812B
- Current: 18mA per LED

WS2812B is an extremely interesting LED that can emit light in red, green or blue - or any combination of these three colors, able to show a total of approximately 16 million different colors. On this board diodes are arranged in a circle. They are controlled by a single pin with only few lines of code from Arduino IDE. That's possible thanks to the integrated controller inside the LED itself!

- Number of LEDs: 24
- Circle outer diameter: 67mm
- Voltage: 5V
- LED type: WS2812B
- Current: 18mA per LED

### Repository Contents

- **/src** - source files for the library (.h & .cpp)
- **/examples** - examples for using the library
- **_other_** - _keywords_ file highlights function words in your IDE, _library.properties_ enables implementation with Arduino Library Manager.

### Hardware design

You can find hardware design for this board in [_Smart LED WS2812B Pixel_](https://github.com/SolderedElectronics/Smart-LED-WS2812B-Pixel-hardware-design) hardware repository.

You can find hardware design for this board in [_Smart LED WS2812B Ring7_](https://github.com/SolderedElectronics/Smart-LED-WS2812B-Ring7-hardware-design) hardware repository.

You can find hardware design for this board in [_Smart LED WS2812B Stick10_](https://github.com/SolderedElectronics/Smart-LED-WS2812B-Stick10-hardware-design) hardware repository.

You can find hardware design for this board in [_Smart LED WS2812B Ring12_](https://github.com/SolderedElectronics/NAZIVPROIZVODA-hardware-design) hardware repository.

You can find hardware design for this board in [_Smart LED WS2812B Ring24_](https://github.com/SolderedElectronics/NAZIVPROIZVODA-hardware-design) hardware repository.

### Documentation

Access Arduino library documentation [here](https://SolderedElectronics.github.io/Soldered-WS2812-Smart-Leds-Arduino-Library/).

- Tutorial for using the WS2812 pixels
- Installing an Arduino library

### Board compatibility

The library is compatible with board & microcontroller families shown in green below:

[![Compile Sketches](http://github-actions.40ants.com/SolderedElectronics/Soldered-WS2812-Smart-Leds-Arduino-Library/matrix.svg?branch=dev&only=Compile%20Sketches)](https://github.com/SolderedElectronics/Soldered-WS2812-Smart-Leds-Arduino-Library/actions/workflows/compile_test.yml)

### About Soldered

<img src="https://raw.githubusercontent.com/SolderedElectronics/Soldered-Generic-Arduino-Library/dev/extras/Soldered-logo-color.png" alt="soldered-logo" width="500"/>

At Soldered, we design and manufacture a wide selection of electronic products to help you turn your ideas into acts and bring you one step closer to your final project. Our products are intented for makers and crafted in-house by our experienced team in Osijek, Croatia. We believe that sharing is a crucial element for improvement and innovation, and we work hard to stay connected with all our makers regardless of their skill or experience level. Therefore, all our products are open-source. Finally, we always have your back. If you face any problem concerning either your shopping experience or your electronics project, our team will help you deal with it, offering efficient customer service and cost-free technical support anytime. Some of those might be useful for you:

- [Web Store](https://www.soldered.com/shop)
- [Tutorials & Projects](https://soldered.com/learn)
- [Community & Technical support](https://soldered.com/community)

### Original source


This library is possible thanks to original [Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) library. Thank you, Adafruit.

### Open-source license

Soldered invests vast amounts of time into hardware & software for these products, which are all open-source. Please support future development by buying one of our products.

Check license details in the LICENSE file. Long story short, use these open-source files for any purpose you want to, as long as you apply the same open-source licence to it and disclose the original source. No warranty - all designs in this repository are distributed in the hope that they will be useful, but without any warranty. They are provided "AS IS", therefore without warranty of any kind, either expressed or implied. The entire quality and performance of what you do with the contents of this repository are your responsibility. In no event, Soldered (TAVU) will be liable for your damages, losses, including any general, special, incidental or consequential damage arising out of the use or inability to use the contents of this repository.

## Have fun!

And thank you from your fellow makers at Soldered Electronics.
