//---------------------------------------------------------
// Buffered NeoPixel driver header
// by teachop
//

#ifndef __NEOPIXEL_H__
#define __NEOPIXEL_H__

#include "strip_config.h"

// neopixel driver interface, Adafruit library-like
interface neopixel_if {
    // update strip from driver internal buffer
    void show(void);

    // write to driver internal buffer with packed RGB 8:8:8 value
    void setPixelColor(uint32_t pixel, uint32_t color);

    // write to driver internal buffer individual 8 bit RGB values
    void setPixelColorRGB(uint32_t pixel, uint8_t r, uint8_t g, uint8_t b);

    // set scaling factor when buffer is displayed, 255 is full
    // this is non-destructive and does not change the buffer contents
    void setBrightness(uint8_t bright);

    // get the RGB 8:8:8 packed color for the given pixel
    uint32_t getPixelColor(uint32_t pixel);

    // utility function to generate packed value from individual 8 bit RGB
    uint32_t Color(uint8_t r, uint8_t g, uint8_t b);

    // get length of strip in pixels
    uint32_t numPixels(void);
};

[[combinable]] void neopixel_task(port neo, interface neopixel_if server dvr);


#endif // __NEOPIXEL_H__