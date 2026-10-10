#include "Interpolate.hpp"
#include <cassert>
#include <cstdint>

uint32_t Interpolate(const uint32_t x, const uint32_t x0, const uint32_t x1, const uint32_t y0, const uint32_t y1)
{
    assert(x0 < x1);
    assert(y0 < y1);

    if (x <= x0)
        return y0;

    if (x >= x1)
        return y1;

    return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
}
