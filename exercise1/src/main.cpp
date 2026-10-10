#include "CalculatePressure.hpp"
#include "Interpolate.hpp"
#include "BinarySearch.hpp"

#include <cstddef>
#include <cstdint>
#include <vector>
#include <cassert>
#include <iostream>

const uint32_t TOLERANCE = 10; // Pascal

void CheckBinarySearch(std::vector<uint16_t> array, uint16_t soughtValue, size_t expectedIndex) {
    size_t index = BinarySearch(array.data(), array.size(), soughtValue);
    std::cout << "Index = " << index << std::endl;
    assert(expectedIndex == index);
}


void CheckInterpolation(uint16_t value, uint32_t expected, uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1)
{
    uint32_t result = Interpolate(value, x0, x1, y0, y1);
    std::cout << "Interpolated value " << value << " to " << result << std::endl;
    assert(result == expected);
}
void CheckPressureConversion(uint16_t adcValue, uint32_t expectedPressure, PressureReadingStatus expectedStatus)
{
    uint32_t result{};
    PressureReadingStatus status = CalculatePressure(adcValue, &result);
    std::cout << "Calculated pressure of: " << result / 1000.0 << " kPa" << std::endl;
    assert(result <= expectedPressure + TOLERANCE);
    assert(result >= expectedPressure - TOLERANCE);
    assert(status == expectedStatus);
}

int main(void) {
    /*
     * Test the binary search algorithm 
     */

    std::cout << "*** Test Step: Validate binary search algorithm" << std::endl;

    std::vector<uint16_t> array{};

    // Returns index of value if exact value is found
    array.assign({1, 2, 3, 4});
    CheckBinarySearch(array, 3, 2);

    // Returns left value if exact value is not present
    array.assign({1, 2, 4, 5});
    CheckBinarySearch(array, 3, 1);

    // Returns rightmost element if value is more than largest of range
    array.assign({1, 2, 4, 5});
    CheckBinarySearch(array, 6, array.size() - 1);

    // Returns leftmost element if value is less than lowest of range
    array.assign({2, 3, 4, 5});
    CheckBinarySearch(array, 1, 0);


    /*
     * Test the interpolation
     */ 

    std::cout << "\n*** Test Step: Validate interpolation" << std::endl;

    uint16_t lower = 10;
    uint16_t upper = 20;

    // Smack-dab in the middle
    CheckInterpolation(5, 15, 0, 10, lower, upper);

    // Less then lower bound is clamped
    CheckInterpolation(1, lower, 5, 8, lower, upper);

    // More than upper bound is clamped
    CheckInterpolation(9, upper, 5, 8, lower, upper);

    /*
     * Test the ADC -> Pressure conversion
     */

    std::cout << "\n*** Test Step: Validate pressure conversions" << std::endl;

    CheckPressureConversion(3'955, 290'000, PressureReadingStatus::PRS_Ok);
    CheckPressureConversion(4096, 299'724, PressureReadingStatus::PRS_Ok);
    CheckPressureConversion(0, 100'000, PressureReadingStatus::PRS_OutOfBounds);
    CheckPressureConversion(16'000, 1'000'000, PressureReadingStatus::PRS_OutOfBounds);
}
