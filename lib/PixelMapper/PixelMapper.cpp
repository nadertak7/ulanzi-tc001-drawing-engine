#include <PixelMapper.h>

PixelMapper::PixelMapper(uint8_t width, uint8_t height)
    : _width(width), _height(height) {}

int PixelMapper::xyToIndex(int x, int y) const {

    // Validate out of bounds x/y coordinates
    if (x < 0 || x >= _width) return -1;
    if (y < 0 || y >= _height) return -1;

    if (y % 2 == 0) {
        // For L->R rows in serpentine pixel formation
        return (_width * y) + x;
    } else {
        // For R->L rows in serpentine pixel formation
        return (_width * y) + (_width - x - 1);
    }
}
