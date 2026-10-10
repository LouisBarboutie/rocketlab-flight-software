#include "Interpolate.hpp"

float Interpolate(const uint16_t x, const uint16_t x0, const uint16_t x1, const uint16_t y0, const uint16_t y1) {
    if (x <= x0)
	return y0;

    if (x >= x1)
	return y1;

    return y0 + (x - x0) * (y1 - y0) / float(x1 - x0);
}
