#ifndef __INTERPOLATE_HPP__
#define __INTERPOLATE_HPP__

#include <cstdint>

/// @brief Linearly interpolate a value from the range [x0, x1] to [y0, y1]
/// @param x Value to interpolate
/// @param x0 Input range lower bound
/// @oaram x1 Input range upper bound
/// @param y0 Output range lower bound
/// @param y1 Output range upper bound
/// @note It is expected that x0 < x1 and that y0 < y1
uint32_t Interpolate(const uint32_t x, const uint32_t x0, const uint32_t x1, const uint32_t y0, const uint32_t y1);

#endif
