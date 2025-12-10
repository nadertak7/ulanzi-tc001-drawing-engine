#include <Arduino.h>
#include <FastLED.h>

#include <PixelMapper.h>
#include <GlyphManager.h>
#include <DrawingEngine.h>

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

// Create library class instances
PixelMapper pixelMapper(LED_PIXEL_WIDTH, LED_PIXEL_HEIGHT);
DrawingEngine drawingEngine(leds, &pixelMapper);


void setup() {
    // Pin modes from https://github.com/rroels/ulanzi_tc001_hardware
    pinMode(PIN_BUZZER, INPUT_PULLDOWN);
    pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
    pinMode(PIN_BUTTON_MIDDLE, INPUT_PULLUP);
    pinMode(PIN_BUTTON_RIGHT, INPUT_PULLUP);

    initialseAsciiCharacterTable();

    // Link LED array with ulanzi hardware
    FastLED.addLeds<NEOPIXEL, PIN_LED_MATRIX>(leds, NUM_LEDS);
}

void loop() {
    drawingEngine.drawGlyph(asciiCharacterTable['A'], 1, 1, CRGB(255, 0, 255));
    drawingEngine.drawGlyph(getCustomGlyph("heart"), 6, 1, CRGB(0, 255, 255));

    FastLED.setBrightness(1);
    FastLED.show();
}
