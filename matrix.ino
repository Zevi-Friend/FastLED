#include <FastLED.h>

// LED strip configuration
#define NUM_LEDS 512         // Number of LEDs in the strip
#define DATA_PIN 6           // Data pin connected to the LED strip

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.clear();
  Serial.begin(9600);
}
int i = 0;
void loop() {
  // FastLED.clear();
  for(int i = 0; i < 512; i++) {
    FastLED.clear();
    leds[reverse(i)] = CRGB(255, 255, 255);
    FastLED.show();
    // delay(20);
  }
  i++;
  if(i == 512) {
    i = 0;
  }
  // FastLED.show();
}

int reverse(int led) {
  int height = led / 16;

  if(height % 2 == 1) {
    led = (height * 16) + 15 - (led % 16);
  }
  return led;
}

int twoMatrix(int led, bool reverse) {
  if(led % 16 == 0) {
    int height = led / 32;
    int first = height * 32;
    int minus = first / 32;
    led = led - minus;
  }
}