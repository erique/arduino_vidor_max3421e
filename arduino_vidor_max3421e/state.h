#pragma once
#include <stdint.h>

void StateUsbJoySet(uint8_t usbjoy, uint8_t usbextra, uint8_t joy_num);
void StateUsbIdSet(uint16_t vid, uint16_t pid, uint8_t num_buttons, uint8_t joy_num);
uint8_t StateUsbJoyGet(uint8_t joy_num);
uint8_t StateUsbJoyGetExtra(uint8_t joy_num);
uint8_t StateUsbGetNumButtons(uint8_t joy_num);
uint16_t StateUsbVidGet(uint8_t joy_num);
uint16_t StateUsbPidGet(uint8_t joy_num);


// State of first (virtual) internal joystisk i.e. after mapping
void StateJoySet(uint8_t c, uint8_t joy_num);
void StateJoySetExtra(uint8_t c, uint8_t joy_num);
uint8_t StateJoyGet(uint8_t joy_num);
uint8_t StateJoyGetExtra(uint8_t joy_num);



// Keep track of connected sticks
uint8_t StateNumJoysticks();
void StateNumJoysticksSet(uint8_t num);
