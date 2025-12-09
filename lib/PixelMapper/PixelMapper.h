#ifndef PIXEL_MAPPER_H
#define PIXEL_MAPPER_H

#include <Arduino.h>

class PixelMapper {
public:
    PixelMapper(uint8_t width, uint8_t height);

    int xyToIndex(int x, int y) const;

private:
    uint8_t _width;
    uint8_t _height;
};

#endif
