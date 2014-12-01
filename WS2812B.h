/*--------------------------------------------------------------------
  File: WS2812B.h
  Desc:  This library is for use with the WS2812B serially 
  addressable RGB LED package. This file is a heavily modified library, 
  reduced from the NeoPixel library available on Adafruit.com.
  Modified: 19 AUG 2014 by Aaron Loar
  --------------------------------------------------------------------*/

#ifndef WS2812B_H
#define WS2812B_H

#include <Arduino.h>


// 'type' flags for LED pixels (third parameter to constructor):
#define NEO_RGB     0x00 // Wired for RGB data order
#define NEO_GRB     0x01 // Wired for GRB data order
#define NEO_COLMASK 0x01

#define ARD_16MHZ    0x00
#define ARD_8MHZ     0x02
#define ARD_SPDMASK  0x02


class NeoPixel {

 public:

  // Constructor: number of LEDs, pin number, LED type
  NeoPixel(uint16_t n, uint8_t p=6, uint8_t t=NEO_GRB + ARD_16MHZ);
  ~NeoPixel();

  void
    begin(void),
    show(void),
    setPin(uint8_t p),
    setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b),
    setPixelColor(uint16_t n, uint32_t c),
    setBrightness(uint8_t);
  uint8_t
   *getPixels(void) const;
  uint8_t
    getPort();
  uint16_t
    numPixels(void) const;
  static uint32_t
    Color(uint8_t r, uint8_t g, uint8_t b);
  uint32_t
    getPixelColor(uint16_t n) const;

 private:

  const uint16_t
    numLEDs,       // Number of RGB LEDs in strip
    numBytes;      // Size of 'pixels' buffer below
  uint8_t
    pin,           // Output pin number
    brightness,
   *pixels,        // Holds LED color values (3 bytes each)
    rOffset,       // Index of red byte within each 3-byte pixel
    gOffset,       // Index of green byte
    bOffset;       // Index of blue byte
  const uint8_t
    type;          // Pixel flags (8MHz or 16MHz, RGB vs GRB color)
  uint32_t
    endTime;       // Latch timing reference
//#ifdef __AVR__
  const volatile uint8_t
    *port;         // Output PORT register
  uint8_t
    pinMask;       // Output PORT bitmask
//#endif

};

#endif // WS2812B_H
