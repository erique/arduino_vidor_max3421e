#include <Arduino.h>
#include <SPI.h>

static SPISettings settings;
static const uint8_t MAX_CS = (7u);

extern "C" {

void spi_init()
{
    pinMode(MAX_CS, OUTPUT);
    digitalWrite(MAX_CS, HIGH);

    SPI.begin();
    settings = SPISettings(250000, MSBFIRST, SPI_MODE0);    
}

void spi_max_start()
{
    SPI.beginTransaction(settings);
    digitalWrite(MAX_CS, LOW);
}

void spi_max_end()
{
    digitalWrite(MAX_CS, HIGH);
    SPI.endTransaction();
}

unsigned char spi8(unsigned char outByte)
{
    return SPI.transfer(outByte);
}

unsigned char spi_in()
{
    return spi8(0x00);
}

void spi_read(char *addr, uint16_t len)
{
    uint8_t* p = (uint8_t*)addr;

    for (int i = 0; i < len; ++i) {
        *p++ = spi8(0x00);
    }
}

void spi_write(char *addr, uint16_t len)
{
    uint8_t* p = (uint8_t*)addr;

    for (int i = 0; i < len; ++i) {
        spi8(*p++);
    }
}

} // extern "C"
