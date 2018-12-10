#define NUM_LEDS 8
#define D1_PIN 6
#define D2_PIN 7

#include <FastLED.h>
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];

byte i = 0;
byte h = 0;
byte s = 255;
byte v = 255;

void setup() {

  // Dev init
  FastLED.addLeds<WS2812B, D1_PIN, GRB>(leds1, NUM_LEDS);
  FastLED.addLeds<WS2812B, D2_PIN, GRB>(leds2, NUM_LEDS);
  FastLED.setBrightness(255);

  // Color blending init
  for (h = 0; h < 255; h++) {
    fill_solid(leds1, NUM_LEDS, CHSV(h,s,v));
    fill_solid(leds2, NUM_LEDS, CHSV(h,s,v));
    FastLED.show();
    delay(8);
  }

  h = 0;
}

void loop() {

  delay(5000);

  if (h >= 255) h = 0;
  
  for (i = 0; i < 8; i++) {
    h++;
    fill_solid(leds1, NUM_LEDS, CHSV(h,s,v));
    fill_solid(leds2, NUM_LEDS, CHSV(h,s,v));
    FastLED.show();
    delay(33);
  }

  delay(5000);

}
