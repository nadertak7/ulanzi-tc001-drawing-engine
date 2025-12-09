#include <GlyphManager.h>

////////////////////////////////////////////////////
// Initialise character data (bitmap, height, width)
////////////////////////////////////////////////////

// Ascii characters
const uint8_t BITMAP_A[] = {
    0b111,    // X X X
    0b101,    // X . X
    0b111,    // X X X
    0b101,    // X . X
    0b101,    // X . X
};
const uint8_t WIDTH_A = 3;
const uint8_t HEIGHT_A = 5;

// Custom characters

const uint8_t BITMAP_HEART[] = {
    0b01010,    // . X . X .
    0b11111,    // X X X X X
    0b11111,    // X X X X X
    0b01110,    // . X X X .
    0b00100,    // . . X . .
};
const uint8_t WIDTH_HEART = 5;
const uint8_t HEIGHT_HEART = 5;


////////////////////////////////////////////////////
// Initialise glyphs that hold character data
////////////////////////////////////////////////////

// Ascii character glyphs
const Glyph GLYPH_A = {BITMAP_A, WIDTH_A, HEIGHT_A};

// Custom character glyphs
const Glyph GLYPH_HEART = {BITMAP_HEART, WIDTH_HEART, HEIGHT_HEART};
const CustomGlyph CUSTOM_GLYPH_HEART = {"heart", &GLYPH_HEART};

////////////////////////////////////////////////////
// Add pointer to glyphs in relevant table
////////////////////////////////////////////////////

// Ascii table
const Glyph* asciiCharacterTable[128] = {
    ['A'] = &GLYPH_A
};

// Custom character table
const CustomGlyph* customCharacterTable[] = {
    &CUSTOM_GLYPH_HEART,
    nullptr
};
