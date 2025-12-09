#include <DrawingEngine.h>

DrawingEngine::DrawingEngine(CRGB* led_array, PixelMapper* pixel_mapper)
    : _led_array(led_array), _pixel_mapper(pixel_mapper) {}

void DrawingEngine::drawPixel(int x, int y, CRGB colour) {
    int index = _pixel_mapper->xyToIndex(x, y);
    if (index >= 0) {
        _led_array[index] = colour;
    }
}

void DrawingEngine::drawGlyph(const Glyph* glyph, int x, int y, CRGB colour) {
    for(int row = 0; row < glyph->height; row++) {
        // Retrieve bitmap for row n
        uint8_t charRowBits = glyph->bitmap[row];

        for(int col = 0; col < glyph->width; col++) {
            // We bitshift on 1 n times based on column index and use an AND mask on the row bitmap.
            // When passed into a bool, a binary literal with 1+ set bit returns True,
            // and a binary literal with no set bits returns False.

            // e.g 2nd column (col index 1) on a shape of width of 5 where row is
            // 0b11011
            // Would result in
            // ledOn = 0b11011 & (1 << 5 - 1 - 1)
            // ledOn = 0b11011 % (1 << 3)
            // ledOn = 0b11011 & 0b01000
            // ledOn = 0b01000 (non-zero value, so truthy)
            bool ledOn = charRowBits & (1 << (glyph->width - 1 - col));

            if(ledOn) {
                drawPixel(x + col, y + row, colour);
            }
        }
    }
}
