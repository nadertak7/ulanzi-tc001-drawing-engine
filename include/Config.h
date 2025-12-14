#pragma once
#include <Arduino.h>

// Pins
const uint8_t PIN_BUZZER = 15;
const uint8_t PIN_BUTTON_LEFT = 26;
const uint8_t PIN_BUTTON_MIDDLE = 27;
const uint8_t PIN_BUTTON_RIGHT = 14;
const uint8_t PIN_LED_MATRIX = 32;

// LED interface
const uint8_t LED_PIXEL_WIDTH = 32;
const uint8_t LED_PIXEL_HEIGHT = 8;
const uint16_t NUM_LEDS = LED_PIXEL_WIDTH * LED_PIXEL_HEIGHT;

// Display
const uint8_t DEFAULT_BRIGHTNESS = 10;