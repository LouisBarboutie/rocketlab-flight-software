#include <cstdint>
#include <iostream>
#include "CalculatePressure.hpp"

void Check(uint16_t adcValue){
    uint32_t result{};
    CalculatePressure(adcValue, &result);
    std::cout << "Calculated pressure of: " << result / 1000.0 << " kPa" << std::endl;
}

int main(void) {
    Check(3'955);
    Check(0);
    Check(4096);
    Check(16'000);
}
