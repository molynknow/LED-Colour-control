//===============================================================
// hue_and_brightness_example.ino
// Marc Miller, 2015
//===============================================================

#include "FastLED.h"
#define LED_TYPE NEOPIXEL // Defining Led type, we are using NeoPixels
#define DATA_PIN 5 // Data input for the neopixel
#define NUM_LEDS 16 // number of keds 
#define Brightness 245 // sets Brightness 
CRGB leds[NUM_LEDS];

int potPinA = A0;   // Pin for potentiometer A (for hue)
int potValA;        // Variable to store potentiometer A value (for hue)
uint8_t hue;        // Hue color (0-255)


//---------------------------------------------------------------
void setup() {
  delay(2000);  // Power-up delay
  FastLED.addLeds<LED_TYPE,DATA_PIN>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(Brightness);  // Initially set the max brightness. 
  pinMode(potPinA, INPUT);  // Set pin as an input.



//---------------------------------------------------------------
void loop() {
  checkKnobs();  // Call function to check knob positions.

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, 255, 255);  // hue comes from pot A, and brightness value is scaled based on pot B.
  }
  FastLED.show();
}


//===============================================================
void checkKnobs(){
  potValA = analogRead(potPinA);  // Read potentiometer A (for hue).
  //potValA = map(potValA, 1023, 0, 0, 1023);  // Reverse reading if potentiometer is wired backwards. 
  hue = map(potValA, 0, 1023, 0, 255);  // map(value, fromLow, fromHigh, toLow, toHigh)

  FastLED.setBrightness(Brightness);  // Set master brightness based on potentiometer position.

  //Serial.print("  pot A: "); Serial.print(potValA); Serial.print("    hue: "); Serial.print(hue);
  //Serial.print("    pot B: "); Serial.print(potValB); Serial.print("    brightness: "); Serial.println(brightness);
}


//---------------------------------------------------------------
