#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void debug_puts(const char* str);

int debugf( const char * format, ... );
int hid_debugf( const char * format, ... );
int hidp_debugf( const char * format, ... );
int usbrtc_debugf( const char * format, ... );
int pl2303_debugf( const char * format, ... );
int asix_debugf( const char * format, ... );
int storage_debugf( const char * format, ... );

void hexdump(void *data, uint16_t size, uint16_t offset);

#ifdef __cplusplus
}
#endif
