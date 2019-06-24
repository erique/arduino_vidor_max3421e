[![Build Status](https://travis-ci.org/erique/arduino_vidor_max3421e.svg?branch=master)](https://travis-ci.org/erique/arduino_vidor_max3421e)

USB Host test code for MKR Vidor 4000 and the MAX3421E via SPI, using the MIST USB code.

( based on https://github.com/mist-devel/mist-firmware/tree/master/usb )

MAX3421E uses pin 7 as CS, and usual SPI pins (8,9,10).
All debug logging is sent to Serial1 aka SERCOM5 (pin 13/14)
