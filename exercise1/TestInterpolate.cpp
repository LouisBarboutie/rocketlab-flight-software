#include "Interpolate.hpp"
#include <cassert>
#include <cstdint>
#include <iostream>

void Check(uint16_t value, float expected, uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1)
{
    float result = Interpolate(value, x0, x1, y0, y1);
    std::cout << "Interpolated value " << value << " to " << result << std::endl;
    assert(result == expected);
}

int main(void)
{
    uint16_t lower = 10;
    uint16_t upper = 20;

    // Smack-dab in the middle
    Check(5, 15.0, 0, 10, lower, upper);

    // Less then lower bound is clamped
    Check(1, (float)lower, 5, 8, lower, upper);

    // More than upper bound is clamped
    Check(9, (float)upper, 5, 8, lower, upper);
}
