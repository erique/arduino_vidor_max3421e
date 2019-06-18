#include <Arduino.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include "debug.h"

extern void kprintstr(const char* str);

void debug_puts(const char* str) { kprintstr(str); kprintstr("\n\r"); }

#define DEBUG_VA_ARGS \
{										\
  char buffer[256];						\
  va_list args;							\
  va_start (args, format);				\
  vsnprintf (buffer,256,format, args);	\
  debug_puts(buffer);						\
  va_end (args);						\
  return strlen(buffer);				\
}

int debugf( const char * format, ... ) DEBUG_VA_ARGS

int hid_debugf( const char * format, ... ) DEBUG_VA_ARGS
int hidp_debugf( const char * format, ... ) DEBUG_VA_ARGS
int usbrtc_debugf( const char * format, ... ) DEBUG_VA_ARGS
int pl2303_debugf( const char * format, ... ) DEBUG_VA_ARGS
int asix_debugf( const char * format, ... ) DEBUG_VA_ARGS
int storage_debugf( const char * format, ... ) DEBUG_VA_ARGS
//int iprintf( const char * format, ... ) DEBUG_VA_ARGS


void hexdump(void *data, uint16_t size, uint16_t offset) {
  uint8_t i, b2c;
  uint16_t n=0;
  char *ptr = (char*)data;

  if(!size) return;

  while(size>0) {
    debugf("%04x: ", n + offset);

    b2c = (size>16)?16:size;
    for(i=0;i<b2c;i++)      debugf("%02x ", 0xff&ptr[i]);
    debugf("  ");
    for(i=0;i<(16-b2c);i++) debugf("   ");
    for(i=0;i<b2c;i++)      debugf("%c", isprint(ptr[i])?ptr[i]:'.');
    debugf("\n");
    ptr  += b2c;
    size -= b2c;
    n    += b2c;
  }
}
