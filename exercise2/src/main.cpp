#include "BigNumber.hpp"
#include "Shell.hpp"

#include <cassert>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

int main(void)
{
    std::cout << "*** Test Section: Validate user input" << std::endl;

    Shell shell{};

    std::cout << "*** Test step: Invalid user input is rejected" << std::endl;

    std::stringstream sstream{};

    std::vector<std::string> invalid_inputs = {"1 23", "abc", "12a", "", " ", "123456"};

    for (const auto &line : invalid_inputs) {
        unsigned int input{};
        std::stringstream sstream{};
        sstream << line;
        bool result = shell.PromptUserInput(sstream, input);
        std::cout << std::quoted(line) << " -> " << input << std::endl;
        assert(result == false);
    }

    std::cout << "*** Test step: Valid user input is accepted" << std::endl;

    std::vector<std::string> valid_inputs = {"123", "00123", "99999"};

    for (const auto &line : valid_inputs) {
        unsigned int input{};
        std::stringstream sstream{};
        sstream << line;
        bool result = shell.PromptUserInput(sstream, input);
        std::cout << std::quoted(line) << " -> " << input << std::endl;
        assert(result == true);
        assert(static_cast<unsigned int>(std::atoi(line.data())) == input);
    }

    std::cout << "*** Test Section: Validate big number arithmetic" << std::endl;

    // Used to extract the numerical value of a BigNumber
    std::stringstream value;

    std::cout << "*** Test step: Big numbers can be printed" << std::endl;

    BigNumber number("12345");
    std::cout << number << std::endl;

    std::cout << "*** Test step: Big numbers can be added" << std::endl;

    value.str(std::string());
    value << BigNumber("125") + BigNumber(20);
    std::cout << value.str() << std::endl;
    assert(145 == std::atoi(value.str().c_str()));

    // Edge case: add 0
    value.str(std::string());
    value << BigNumber("125") + BigNumber(0);
    std::cout << value.str() << std::endl;
    assert(125 == std::atoi(value.str().c_str()));

    std::cout << "*** Test step: Big numbers can be multiplied" << std::endl;

    value.str(std::string());
    value << BigNumber("25") * BigNumber("100");
    std::cout << value.str() << std::endl;
    assert(2500 == std::atoi(value.str().data()));

    // Edge case: multiply by 1
    value.str(std::string());
    value << BigNumber("25") * BigNumber("1");
    std::cout << value.str() << std::endl;
    assert(25 == std::atoi(value.str().data()));

    // Edge case: multiply by 0
    value.str(std::string());
    value << BigNumber("25") * BigNumber("0");
    std::cout << value.str() << std::endl;
    assert(0 == std::atoi(value.str().data()));

    std::cout << "*** Test step: Big numbers can be exponentiated" << std::endl;

    value.str(std::string());
    value << pow(BigNumber("2"), BigNumber("3"));
    std::cout << value.str() << std::endl;
    assert(8 == std::atoi(value.str().data()));

    // Edge case: exponent is 0
    value.str(std::string());
    value << pow(BigNumber("2"), BigNumber("0"));
    std::cout << value.str() << std::endl;
    assert(1 == std::atoi(value.str().c_str()));

    // Edge case: exponent is 1
    value.str(std::string());
    value << pow(BigNumber("2"), BigNumber("1"));
    std::cout << value.str() << std::endl;
    assert(2 == std::atoi(value.str().c_str()));

    // Edge case: base is 0
    value.str(std::string());
    value << pow(BigNumber("0"), BigNumber("1"));
    std::cout << value.str() << std::endl;
    assert(0 == std::atoi(value.str().c_str()));

    // Validate given solution
    value.str(std::string());
    value << pow(BigNumber("123"), BigNumber("321"));
    std::cout << value.str() << std::endl;
    std::string expected =
        "72367033806371673149109894141163778628811792657571658906010558390395870363798401744095280686155507736404921657"
        "07028496172182896059297790954263709889769722310262262856678765409132782545399159514020570141296136418873240893"
        "61978905536997158369515699998004319577692170067433210262575179327641646623194879149625333027413682072111894946"
        "15326552790667720411285474162636765168907211924134973374304496019635376665858559941735703924836467756917247995"
        "46958348746779152458215374452210759786527779813608007416148528042427407693108399448711171956224970254036285571"
        "29111322659662357543553535167033390430015061185207603595777378694720186179421205908731707108050786963717389063"
        "75721785723";
    assert(expected.compare(value.str()) == 0);
}
