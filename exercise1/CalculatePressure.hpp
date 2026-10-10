#ifndef __CALCULATE_PRESSURE_HPP__
#define __CALCULATE_PRESSURE_HPP__

#include <cstdint>
#include <cstdlib>

constexpr uint32_t PRESSURE_START_Pa = 100'000;
constexpr uint32_t PRESSURE_STOP_Pa = 1'000'000;
constexpr uint32_t PRESSURE_STEP_Pa = 10'000;

constexpr size_t LOOKUP_TABLE_SIZE = 91;

const uint16_t adcLookupTable[LOOKUP_TABLE_SIZE] = {
    1696,  1909,  2118,  2272,  2366,  2448,  2570,  2745,  2931,  3073,  3151,  3200,  3278,  3411,  3573,  3706,
    3777,  3808,  3853,  3955,  4100,  4236,  4316,  4348,  4382,  4468,  4610,  4762,  4871,  4927,  4971,  5058,
    5210,  5390,  5541,  5639,  5710,  5812,  5979,  6190,  6389,  6534,  6641,  6762,  6943,  7177,  7414,  7604,
    7743,  7877,  8060,  8302,  8560,  8778,  8938,  9074,  9243,  9470,  9726,  9954,  10119, 10244, 10383, 10577,
    10810, 11028, 11187, 11292, 11394, 11542, 11739, 11937, 12085, 12170, 12237, 12340, 12498, 12675, 12815, 12893,
    12938, 13007, 13135, 13299, 13444, 13531, 13575, 13631, 13744, 13908, 14073,
};

enum PressureReadingStatus {
    PRS_Ok = 0,
    PRS_OutOfBounds = 1,
};

/// @brief Calculates the pressure in Pa with a resolution of 1 Pa from the given ADC value.
/// @param adcValue The reading from the ADC to be mapped to a pressure reading
/// @param out Stores the result of the conversion
/// @return Status of the conversion, if the ADC value is outside of the calibrated range
PressureReadingStatus CalculatePressure(const uint16_t adcValue, uint32_t *out);

#endif
