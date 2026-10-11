#include <charconv>
#include <iostream>
#include <istream>

class Shell
{
  public:
    bool PromptUserInput(std::istream &istream, unsigned int &input);
};
