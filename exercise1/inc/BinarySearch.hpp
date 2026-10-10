#ifndef __BINARY_SEARCH_HPP__
#define __BINARY_SEARCH_HPP__

#include <cstdint>
#include <cstddef>

/// @brief Perform a binary search that returns the index of the left-closest element.
/// @param array The array to be searched
/// @param size Size of the array
/// @param value Value to search for
/// @return The index of the value if found, else the nearest element lesser than value
/// @note The array is expected to be sorted.
size_t BinarySearch(const uint16_t *array, const size_t size, const uint16_t value);

#endif
