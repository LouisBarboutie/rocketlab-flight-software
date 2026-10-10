#include "BinarySearch.hpp"
#include <cstdint>
#include <vector>
#include <cassert>
#include <iostream>

void Check(std::vector<uint16_t> array, uint16_t soughtValue, uint16_t expectedIndex) {
    uint16_t index = BinarySearch(array.data(), array.size(), soughtValue);
    std::cout << "Index = " << index << std::endl;
    assert(expectedIndex == index);
}

int main(void)
{
    std::vector<uint16_t> array{};
    uint16_t index{0};

    // Returns index of value if exact value is found
    array.assign({1, 2, 3, 4});
    Check(array, 3, 2);

    // Returns left value if exact value is not present
    array.assign({1, 2, 4, 5});
    Check(array, 3, 1);

    // Returns rightmost element if value is more than largest of range
    array.assign({1, 2, 4, 5});
    Check(array, 6, array.size() - 1);

    // Returns leftmost element if value is less than lowest of range
    array.assign({2, 3, 4, 5});
    Check(array, 1, 0);

    return 0;
}
