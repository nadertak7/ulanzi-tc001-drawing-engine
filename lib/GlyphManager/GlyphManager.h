#pragma once

#include <Arduino.h>

struct Glyph {
    const uint8_t *bitmap;
    uint8_t width;
    uint8_t height;
};

extern const Glyph* asciiCharacterTable[128];

struct CustomGlyph {
    const char* name;
    const Glyph* characterGlyph;
};

extern const CustomGlyph* customCharacterTable[];
