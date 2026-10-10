#include "CalculatePressure.hpp"
#include <cassert>
#include <cstdint>
#include <iostream>

const uint32_t TOLERANCE = 10; // Pascal

void Check(uint16_t adcValue, uint32_t expectedPressure, PressureReadingStatus expectedStatus)
{
    uint32_t result{};
    PressureReadingStatus status = CalculatePressure(adcValue, &result);
    std::cout << "Calculated pressure of: " << result / 1000.0 << " kPa" << std::endl;
    assert(result <= expectedPressure + TOLERANCE);
    assert(result >= expectedPressure - TOLERANCE);
    assert(status == expectedStatus);
}

int main(void)
{
    Check(3'955, 290'000, PressureReadingStatus::PRS_Ok);
    Check(4096, 299'724, PressureReadingStatus::PRS_Ok);
    Check(0, 100'000, PressureReadingStatus::PRS_OutOfBounds);
    Check(16'000, 1'000'000, PressureReadingStatus::PRS_OutOfBounds);
}
