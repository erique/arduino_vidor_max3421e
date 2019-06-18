#pragma once
#include <stdint.h>
#include <stdbool.h>

#define JOY_RIGHT       0x01
#define JOY_LEFT        0x02
#define JOY_DOWN        0x04
#define JOY_UP          0x08
#define JOY_BTN_SHIFT   4
#define JOY_BTN1        0x10
#define JOY_BTN2        0x20
#define JOY_BTN3        0x40
#define JOY_BTN4        0x80
#define JOY_MOVE        (JOY_RIGHT|JOY_LEFT|JOY_UP|JOY_DOWN)

// virtual gamepad buttons
#define JOY_A      JOY_BTN1
#define JOY_B      JOY_BTN2
#define JOY_SELECT JOY_BTN3
#define JOY_START  JOY_BTN4
#define JOY_X      0x100
#define JOY_Y      0x200
#define JOY_L      0x400
#define JOY_R      0x800
#define JOY_L2     0x1000
#define JOY_R2     0x2000
#define JOY_L3     0x4000
#define JOY_R3     0x8000

#define UIO_PRIORITY_KEYBOARD 0 
#define UIO_PRIORITY_GAMEPAD  1

// serial status data type returned from the core 
typedef struct {
  uint32_t bitrate;        // 300, 600 ... 115200
  uint8_t datasize;        // 5,6,7,8 ...
  uint8_t parity;
  uint8_t stopbits;
  uint8_t fifo_stat;       // space in cores input fifo
} __attribute__ ((packed)) serial_status_t; 

void user_io_mouse(unsigned char b, char x, char y);
void user_io_kbd(unsigned char m, unsigned char *k, uint8_t priority, unsigned short vid, unsigned short pid);
char user_io_create_config_name(char *s);
void user_io_digital_joystick(unsigned char, unsigned char);
void user_io_digital_joystick_ext(unsigned char, uint16_t);
void user_io_analog_joystick(unsigned char, char, char);
char user_io_osd_is_visible();
void user_io_send_buttons(char);

//uint16_t virtual_joystick_mapping (uint16_t vid, uint16_t pid, uint16_t joy_input);
//bool virtual_joystick_keyboard ( uint16_t vjoy );

char user_io_serial_status(serial_status_t *, uint8_t); 
void user_io_serial_tx(char *, uint16_t);

// io controllers interface for FPGA ethernet emulation using usb ethernet
// devices attached to the io controller (ethernec emulation)
void user_io_eth_send_mac(uint8_t *);
uint32_t user_io_eth_get_status(void);
void user_io_eth_send_rx_frame(uint8_t *, uint16_t);
void user_io_eth_receive_tx_frame(uint8_t *, uint16_t); 

// TOS

#define TOS_CONTROL_ETHERNET      0x02000000
void tos_update_sysctrl(unsigned long);
unsigned long tos_system_ctrl(void);
