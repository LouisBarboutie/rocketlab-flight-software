#include "BinarySearch.hpp"

size_t BinarySearch(const uint16_t *array, const size_t size, const uint16_t value)
{
    // cf. Wikipedia, Binary Search, Procedure for finding the leftmost element

    if (value >= array[size - 1])
        return size - 1;

    if (value <= array[0])
        return 0;

    size_t left{0};
    size_t right{size};

    while (left < right) {
        size_t middle = left + (right - left) / 2;

        if (array[middle] <= value)
            left = middle + 1;
        else
            right = middle;
    }

    return left - 1;
}
