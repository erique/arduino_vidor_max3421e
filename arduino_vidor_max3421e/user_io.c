#include "user_io.h"
#include "debug.h"

// hooks from the usb layer
void user_io_mouse(unsigned char b, char x, char y) { debugf("%s : %d,%d,%d",__FUNCTION__,b,x,y); }
void user_io_kbd(unsigned char m, unsigned char *k, uint8_t priority, unsigned short vid, unsigned short pid) {
	debugf("%s : [%04x/%04x] ; [ %02x, %02x, %02x, %02x ] ; %02x, %d",__FUNCTION__, vid,pid, k[0],k[1],k[2],k[3], m, priority);
}
char user_io_create_config_name(char *s) { (void)s; return 0; }
void user_io_digital_joystick(unsigned char joystick, unsigned char map) { (void)joystick; (void)map; }
void user_io_digital_joystick_ext(unsigned char joystick, uint16_t map) { (void)joystick; (void)map;}
void user_io_analog_joystick(unsigned char joystick, char valueX, char valueY) {(void)joystick; (void)valueX; (void)valueY;}
char user_io_osd_is_visible(){ return 0; }
void user_io_send_buttons(char force) {(void)force;}

char user_io_serial_status(serial_status_t *status_in, uint8_t status_out) { (void) status_in; (void) status_out; return 0; }
void user_io_serial_tx(char *buf, uint16_t len) { (void)buf; (void)len; }

void user_io_eth_send_mac(uint8_t * mac) { (void) mac; }
uint32_t user_io_eth_get_status(void) { return 0; }
void user_io_eth_send_rx_frame(uint8_t * buf, uint16_t len) { (void)buf; (void)len; }
void user_io_eth_receive_tx_frame(uint8_t * buf, uint16_t len) { (void)buf; (void)len; }

void tos_update_sysctrl(unsigned long mask) { (void)mask; }
unsigned long tos_system_ctrl(void) { return 0; }


