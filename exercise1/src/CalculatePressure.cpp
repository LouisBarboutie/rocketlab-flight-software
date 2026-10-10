#include "CalculatePressure.hpp"

#include <cstdint>

#include "BinarySearch.hpp"
#include "Interpolate.hpp"

constexpr uint32_t GetPressureAt(const uint32_t index) { return PRESSURE_START_Pa + PRESSURE_STEP_Pa * index; }

PressureReadingStatus CalculatePressure(const uint16_t adcValue, uint32_t *out)
{
    size_t index = BinarySearch(adcLookupTable, LOOKUP_TABLE_SIZE, adcValue);

    // Clamp the value if ADC reading is out-of-bounds
    if (index == 0) {
        *out = GetPressureAt(0);
        return PressureReadingStatus::PRS_OutOfBounds;
    }

    if (index == LOOKUP_TABLE_SIZE - 1) {
        *out = GetPressureAt(LOOKUP_TABLE_SIZE - 1);
        return PressureReadingStatus::PRS_OutOfBounds;
    }

    // Linearly interpolate the ADC if it is within bounds of the lookup table
    uint32_t p0 = GetPressureAt(static_cast<uint32_t>(index));
    uint32_t p1 = GetPressureAt(static_cast<uint32_t>(index + 1));
    *out = Interpolate(adcValue, adcLookupTable[index], adcLookupTable[index + 1], p0, p1);

    return PressureReadingStatus::PRS_Ok;
}
