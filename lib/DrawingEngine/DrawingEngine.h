#pragma once

#include <Arduino.h>
#include <FastLED.h>

#include <PixelMapper.h>
#include <GlyphManager.h>

class DrawingEngine {
public:
    DrawingEngine(CRGB* led_array, PixelMapper* pixel_mapper);

    void drawPixel(int x, int y, CRGB colour);

    void drawGlyph(const Glyph* glyph, int x, int y, CRGB colour);

    void drawText(const char* text, int x, int y, CRGB colour, uint16_t glyphSpacing = 1, uint16_t spaceSpacing = 3);

private:
    CRGB* _led_array;
    PixelMapper* _pixel_mapper;
};
