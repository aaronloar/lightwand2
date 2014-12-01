#include <WS2812B.h>

#define PIN 6

#define __RED       0x00FF0000
#define __BLUE      0x000000FF
#define __WHITE     0x00FFFFFF


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB Bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB Bitstream (v1 FLORA pixels, not v2)
NeoPixel strip = NeoPixel(60, PIN, NEO_GRB + ARD_8MHZ);

int powerLight = 4;

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.


           //0  1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9  
static uint32_t flagFieldArray[][20] = {
            {__BLUE, __BLUE, __BLUE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE}
            
  };



void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(255);
  //pinMode(0, INPUT);
  attachInterrupt(1, userButtonHandler, LOW );

  pinMode(powerLight, OUTPUT);
  
  powerButtonLight();



  
  

  
}

void loop() {
  

  /*
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0),   20); // Red
  colorWipe(strip.Color(255, 100, 0), 20); // Orange
  colorWipe(strip.Color(255, 255, 0), 20); // Yellow
  colorWipe(strip.Color(128, 255, 0), 20); // Chartreuse
  colorWipe(strip.Color(0, 255, 0),   20); // Green
  colorWipe(strip.Color(0, 255, 128), 20); // Teal
  colorWipe(strip.Color(0, 0, 255),   20); // Blue
  //colorWipe(strip.Color(128, 0, 255), 20); // Light Purple
  colorWipe(strip.Color(255, 0, 255), 20); // Purple
  colorWipe(strip.Color(255, 0, 128), 20); // Violet
  //colorWipe(strip.Color(255, 255, 255), 20); // White
  /*
  // Hold on a color
  colorHold(strip.Color(255, 0, 0),   1);  // Red
  colorHold(strip.Color(0, 255, 0),   1);  // Green
  colorHold(strip.Color(0, 0, 255),   1);  // Blue
  colorHold(strip.Color(255, 255, 255),   3); // White
  

  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127,   0,   0), 50); // Red
  theaterChase(strip.Color(  0,   0, 127), 50); // Blue



   rainbowCycle(20);

*/
  // theaterChaseRainbow(50);

  singlePixelRainbowCycle(20);
  //singlePixelRainbowCycle(20);
  
  
  for(int i = 0; i < 3; i++) {
    singlePixelRainbowCycle(20);
  }
  
  for (int i = 0; i < 300; i++) {
    stripeThin(strip.Color(255, 0 , 0), 5);
  }
  
  for (int i = 0; i < 255; i++) {
    stripeThick(Wheel(i), 5);
  }
  
  for (int i = 0; i < 255; i++) {
    stripeSuperThick(Wheel(i), 20);
  }
  
  for (int i = 0; i < 240; i++) {
    americanFlag(i, 5);
  }
  
  
  //Serial.println("loop");
  //colorHold(strip.Color(255, 0, 0),   1);  // Red
  //colorHold(strip.Color(255, 255, 255),   3);  // White

  //rainbowCycle(20);

  //colorHold(strip.Color(255, 0, 0),   1);  // Red
  //longRainbowCycle(20);
  longRainbowCycle(20);
  


}



// 2 pixels on, 3 off, solid color
void stripeThin(uint32_t c, uint8_t wait) {
  
  for(uint16_t i=0; i< strip.numPixels(); i = i+5) {
    uint8_t j = 0;
    for(; j < 3; j++) {
      strip.setPixelColor(i + j, 0);
    }
    for(; j < 5; j++) {
      strip.setPixelColor(i + j, c);
    }
  }
      strip.show();
      delay(wait);
}

// 5 pixels on, 5 off, solid color
void stripeThick(uint32_t c, uint8_t wait) {
  
  for(uint16_t i=0; i< strip.numPixels(); i = i+10) {
    uint8_t j = 0;
    for(; j < 5; j++) {
      strip.setPixelColor((i + j), 0);
    }
    for(; j < 10; j++) {
      strip.setPixelColor((i + j), c);
    }
  }
      strip.show();
      delay(wait);
}


// 5 pixels on, 5 off, solid color
void stripeSuperThick(uint32_t c, uint8_t wait) {
  uint8_t j = 0;
    for(; j < 12; j++) {
      strip.setPixelColor(j, c);
    }
        for(; j < 24; j++) {
      strip.setPixelColor(j, 0);
    }
        for(; j < 36; j++) {
      strip.setPixelColor(j, c);
    }
        for(; j < 48; j++) {
      strip.setPixelColor(j, 0);
    }
        for(; j < 60; j++) {
      strip.setPixelColor(j, c);
    }
      strip.show();
      delay(wait);
}

void americanFlag(int counter, uint8_t wait) {
   for(int i = 0; i < 20; i++) {
     strip.setPixelColor(i+40, flagFieldArray[counter % 16][i]);
   }
   uint8_t j = 0;
    for(; j < 8; j++) {
      strip.setPixelColor(j, __RED);
    }
    for(; j < 16; j++) {
      strip.setPixelColor(j, __WHITE);
    }
    for(; j < 24; j++) {
      strip.setPixelColor(j, __RED);
    }
    for(; j < 32; j++) {
      strip.setPixelColor(j, __WHITE);
    }
    for(; j < 40; j++) {
      strip.setPixelColor(j, __RED);
    }
    
    strip.show();
    delay(wait);
  
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {

  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void colorHold(uint32_t c, uint8_t wait) {

  for (int16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(wait);
}


void rainbow(uint8_t wait) {

  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Single color over whole wand
void singleColorWand(uint32_t c, uint8_t wait) {

  uint16_t i, j;

  for(i=0; i< strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(wait);
}



// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {

  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Single pixel bounces through the colors, end to end, 5 times
void singlePixelRainbowCycle(uint8_t wait) {

  uint16_t i, j, k;
  for(k = 0; k < 1; k++) {
    for(i=0; i< strip.numPixels(); i++) {
      for (j = 0; j < strip.numPixels(); j++) {
        strip.setPixelColor(j, 0);
      }
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      strip.show();
      delay(wait);
    }
    for(i=0; i< strip.numPixels(); i++) {
      for (j = 0; j < strip.numPixels(); j++) {
        strip.setPixelColor(j, 0);
      }
      strip.setPixelColor((strip.numPixels() - i), Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      strip.show();
      delay(wait);
    }
  }

}

void longRainbowCycle(uint8_t wait) {

  uint16_t i, j;
  
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i=i+5) {
      strip.setPixelColor(i, Wheel(((i * 256 / (strip.numPixels()*5)) + j) & 255));
      strip.setPixelColor(i+1, Wheel(((i * 256 / (strip.numPixels()*5)) + j) & 255));
      strip.setPixelColor(i+2, Wheel(((i * 256 / (strip.numPixels()*5)) + j) & 255));
      strip.setPixelColor(i+3, Wheel(((i * 256 / (strip.numPixels()*5)) + j) & 255));
      strip.setPixelColor(i+4, Wheel(((i * 256 / (strip.numPixels()*5)) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
  


//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {

  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {

  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

// Flash power light on power up.
void powerButtonLight() {

  for(int powerUp = 0;powerUp < 3; powerUp++){
    digitalWrite(powerLight, HIGH);
    delay(100); 
    digitalWrite(powerLight, LOW);
    delay(100); 
  }
}

// Button interrupt handler
void userButtonHandler () {
  strip.setBrightness(0);
}





