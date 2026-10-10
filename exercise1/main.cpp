#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>

constexpr uint8_t PRESSURE_START_kPa = 100;
constexpr uint8_t PRESSURE_STOP_kPa = 1000;
constexpr uint8_t PRESSURE_STEP_kPa = 10;

const uint16_t adcLookupTable[] = {
    1696,  1909,  2118,  2272,  2366,  2448,  2570,  2745,  2931,  3073,  3151,
    3200,  3278,  3411,  3573,  3706,  3777,  3808,  3853,  3955,  4100,  4236,
    4316,  4348,  4382,  4468,  4610,  4762,  4871,  4927,  4971,  5058,  5210,
    5390,  5541,  5639,  5710,  5812,  5979,  6190,  6389,  6534,  6641,  6762,
    6943,  7177,  7414,  7604,  7743,  7877,  8060,  8302,  8560,  8778,  8938,
    9074,  9243,  9470,  9726,  9954,  10119, 10244, 10383, 10577, 10810, 11028,
    11187, 11292, 11394, 11542, 11739, 11937, 12085, 12170, 12237, 12340, 12498,
    12675, 12815, 12893, 12938, 13007, 13135, 13299, 13444, 13531, 13575, 13631,
    13744, 13908, 14073,
};

struct Float {
    uint8_t a;
    uint8_t b;
};


size_t BinarySearch(const uint16_t array, const uint16_t value);

uint16_t Interpolate(const uint16_t x, const uint16_t x0, const uint16_t x1,
                     const uint16_t y0, const uint16_t y1);

void CalculatePressure(const uint16_t adcValue, Float *out);

int main(void)
{
    const uint16_t reading { 4096};
    Float result{};
    CalculatePressure(reading, &result);
    std::cout << "Converted ADC reading of " << reading << " to pressure of " << result << " kPa." << std::endl;
    return 0;
}

void CalculatePressure(const uint16_t adcValue, Float *out)
{
    BinarySearch(adcLookupTable, adcValue);
}
