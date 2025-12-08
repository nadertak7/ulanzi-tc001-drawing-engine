#include <Arduino.h>
#include <FastLED.h>

const uint8_t PIN_BUZZER = 15;
const uint8_t PIN_BUTTON_LEFT = 26;
const uint8_t PIN_BUTTON_MIDDLE = 27;
const uint8_t PIN_BUTTON_RIGHT = 14;
const uint8_t PIN_LED_MATRIX = 32;
const uint8_t LED_PIXEL_WIDTH = 32;
const uint8_t LED_PIXEL_HEIGHT = 8;
const uint16_t NUM_LEDS = LED_PIXEL_WIDTH * LED_PIXEL_HEIGHT;

// Create an array that allows assigning RGB values to each index
CRGB leds[NUM_LEDS];

void setup() {
    // Pin modes from https://github.com/rroels/ulanzi_tc001_hardware
    pinMode(PIN_BUZZER, INPUT_PULLDOWN);
    pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
    pinMode(PIN_BUTTON_MIDDLE, INPUT_PULLUP);
    pinMode(PIN_BUTTON_RIGHT, INPUT_PULLUP);

    // Link LED array with ulanzi hardware
    FastLED.addLeds<NEOPIXEL, PIN_LED_MATRIX>(leds, NUM_LEDS);

    leds[0] = CRGB(255, 255, 255);
    FastLED.setBrightness(1);
    FastLED.show();
}

void loop() {
    if(digitalRead(PIN_BUTTON_LEFT) == LOW) {
        Serial.println("left button");
    }
}