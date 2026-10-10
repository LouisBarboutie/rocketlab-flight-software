#include "CalculatePressure.hpp"

#include <cstdint>

#include "BinarySearch.hpp"
#include "Interpolate.hpp"

void CalculatePressure(const uint16_t adcValue, float *out)
{
    size_t index = BinarySearch(adcLookupTable, LOOKUP_TABLE_SIZE, adcValue);

    if (index == 0) {
        *out = pressureLookupTable[0];
        return;
    }

    if (index == LOOKUP_TABLE_SIZE - 1) {
        *out = pressureLookupTable[LOOKUP_TABLE_SIZE - 1];
        return;
    }

    *out = Interpolate(adcValue, adcLookupTable[index], adcLookupTable[index + 1], pressureLookupTable[index],
                       pressureLookupTable[index + 1]);
}
