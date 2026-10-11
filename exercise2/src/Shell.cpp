#include "Shell.hpp"
#include <charconv>
#include <iostream>

bool Shell::PromptUserInput(std::istream &istream, unsigned int &input)
{
    std::cout << "Enter a number (0-99999): ";

    std::string string{};
    std::getline(istream >> std::ws, string);

    unsigned int result{};
    char *first = string.data();
    char *last = first + string.size();
    auto [ptr, ec] = std::from_chars(first, last, result);

    // input is cluttered with unwanted chars
    if (ptr != last)
        return false;

    // input was cleanly extracted
    if (ec == std::errc() && result <= 99'999) {
        input = result;
        return true;
    }

    return false;
};
