#include <DrawingEngine.h>
#include <GlyphManager.h>
#include <Config.h>

DrawingEngine::DrawingEngine(CRGB* led_array, PixelMapper* pixel_mapper)
    : _led_array(led_array), _pixel_mapper(pixel_mapper) {}

void DrawingEngine::drawPixel(int x, int y, CRGB colour) {
    int index = _pixel_mapper->xyToIndex(x, y);
    if (index >= 0) {
        _led_array[index] = colour;
    }
}

void DrawingEngine::drawGlyph(const Glyph* glyph, int x, int y, CRGB colour) {
    for (int row{}; row < glyph->height; row++) {

        uint8_t bitshift = glyph->width - 1;
        uint8_t charRowBits = glyph->bitmap[row];

        for (int col{}; col < glyph->width; col++) {
            // We bitshift on 1 n times for column index and use an AND mask on the row bitmap.
            // When passed into a bool, a binary literal with 1+ set bit returns True,
            // and a binary literal with no set bits returns False.

            // e.g 2nd column (col index 1) on a shape of width of 5 on row bitmap 0b11011
            // Would result in:
            // ledOn = 0b11011 & (1 << 5 - 1 - 1)
            // ledOn = 0b11011 % (1 << 3)
            // ledOn = 0b11011 & 0b01000
            // ledOn = 0b01000 (non-zero value, so truthy)
            bool ledOn = charRowBits & (1 << bitshift);

            if (ledOn) {
                drawPixel(x + col, y + row, colour);
            }

            bitshift--;
        }
    }
}

void DrawingEngine::drawText(const char* text, int x, int y, CRGB colour, uint16_t spaceWidth) {
    int cursorX = x;

    while (*text) {
        const Glyph* glyph = nullptr;

        // Handle custom glyphs wrapped in {}
        if (*text == '{') {
            text++; // Point to character after opening brace

            char customCharName[32] = {};
            int customCharNameIndex{};

            while (*text && *text != '}' && customCharNameIndex < 31) {
                customCharName[customCharNameIndex] = *text;
                customCharNameIndex++;
                text++;
            }

            customCharName[customCharNameIndex] = '\0'; // Null terminate string

            if (*text != '}') { // Detects if custom character name is too long or if there is no closing brace
                Serial.printf("Custom character does not have a closing brace for text %s\n", customCharName);
                return;
            }

            if (customCharNameIndex > 0) {
                glyph = getCustomGlyph(customCharName);
            }

        } else { // For characters not wrapped in {}
            uint8_t character = (uint8_t)*text;
            if (character < 128) {
                glyph = asciiCharacterTable[character];
            }
        }

        if (glyph) {
            drawGlyph(glyph, cursorX, y, colour);
            cursorX += glyph->width + spaceWidth;
        }

        text++;
    }
}
