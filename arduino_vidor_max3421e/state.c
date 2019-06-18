#include "state.h"
#include "debug.h"

/*****
 * Various functions to retrieve hardware state from the State
 */

 // USB raw data for joystick
void StateUsbJoySet(uint8_t usbjoy, uint8_t usbextra, uint8_t joy_num) {(void)usbjoy;(void)usbextra;(void)joy_num;}
void StateUsbIdSet(uint16_t vid, uint16_t pid, uint8_t num_buttons, uint8_t joy_num) {(void)vid;(void)pid;(void)num_buttons;(void)joy_num;}
uint8_t StateUsbJoyGet(uint8_t joy_num) { (void)joy_num; return 0; }
uint8_t StateUsbJoyGetExtra(uint8_t joy_num) { (void)joy_num; return 0; }
uint8_t StateUsbGetNumButtons(uint8_t joy_num) { (void)joy_num; return 0; }
uint16_t StateUsbVidGet(uint8_t joy_num) { (void)joy_num; return 0; }
uint16_t StateUsbPidGet(uint8_t joy_num) { (void)joy_num; return 0; }


// State of first (virtual) internal joystisk i.e. after mapping
void StateJoySet(uint8_t c, uint8_t joy_num) { (void)c; (void)joy_num; return ; }
void StateJoySetExtra(uint8_t c, uint8_t joy_num) { (void)c; (void)joy_num; return ; }
uint8_t StateJoyGet(uint8_t joy_num) { (void)joy_num; return 0; }
uint8_t StateJoyGetExtra(uint8_t joy_num) { (void)joy_num; return 0; }



// Keep track of connected sticks
uint8_t StateNumJoysticks() { return 0; }
void StateNumJoysticksSet(uint8_t num) { (void)num; return ; }
