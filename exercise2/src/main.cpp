#include <algorithm>
#include <charconv>
#include <iostream>
#include <sstream>
#include <string>
#include <system_error>

class Shell
{
  public:
    int PromptUserInput(std::istream &istream)
    {
        while (true) {

            std::cout << "Enter a number (0-99999): ";

            std::string string{};
            std::getline(istream >> std::ws, string);

            unsigned int result{};
            char *first = string.data();
            char *last = first + string.size();
            auto [ptr, ec] = std::from_chars(first, last, result);

            if (ptr != last)
                continue;

            if (ec == std::errc())
                return result;
        }
        return 0;
    };
};

class BigNumber
{
  public:
    BigNumber() = default;

    BigNumber(unsigned int number)
    {
        std::string str = std::to_string(number);
        this->A = str;
        std::reverse(str.begin(), str.end());
        this->B = str;
        this->repr = "";
    };

    BigNumber(std::string repr) { this->repr.assign(repr); }

    std::string repr;
    std::string A, B;

    BigNumber &operator+=(const BigNumber &other)
    {
        BigNumber result;
        result.repr.resize(std::max(this->repr.size(), other.repr.size()) + 1);

        int carry = 0;
        for (size_t i = 0; i < result.repr.size(); ++i) {
            int lhs = i >= this->repr.size() ? 0 : this->repr[this->repr.size() - 1 - i] - '0';
            int rhs = i >= other.repr.size() ? 0 : other.repr[other.repr.size() - 1 - i] - '0';
            int sum = lhs + rhs + carry;
            carry = sum / 10;

            char digit = static_cast<char>(sum % 10) + '0';
            result.repr[i] = digit;
        }
        if (result.repr.back() == '0')
            result.repr.pop_back();
        std::reverse(result.repr.begin(), result.repr.end());
        this->repr.assign(result.repr);
        return *this;
    }

    BigNumber &operator*=(const BigNumber &other)
    {
        BigNumber result;
        BigNumber it;
        while (it.repr.compare(other.repr)) {
            result += *this;
            ++it;
        }

        this->repr.assign(result.repr);
        return *this;
    }
    BigNumber &operator++() { return *this += BigNumber("1"); }
};

BigNumber &operator+(BigNumber &lhs, const BigNumber &rhs)
{
    lhs += rhs;
    return lhs;
}

BigNumber &operator*(BigNumber &lhs, const BigNumber &rhs)
{
    lhs *= rhs;
    return lhs;
}

std::ostream &operator<<(std::ostream &os, const BigNumber &num)
{
    os << "PowerNumber(A=" << num.A << ", B=" << num.B << ")";
    return os;
}

BigNumber pow(const BigNumber &base, const BigNumber &exponent)
{
    BigNumber it("0");
    BigNumber result("1");
    while (it.repr.compare(exponent.repr)) {
        result *= base;
        ++it;
	if ((std::atoi(it.repr.data()) / std::atoi(exponent.repr.data())) % 5 == 0) {
	    std::cout << "Next 5% reached. Current size: " << result.repr.size() << std::endl;
}
    }
    return result;
}
int main(void)
{
    Shell shell{};

    std::stringstream sstream{};
    sstream << "123\n";

    int input = shell.PromptUserInput(sstream);

    BigNumber number(input);

    std::cout << number << std::endl;

    BigNumber num1, num2, num3;
    num1.repr = "125";
    num2.repr = "20";

    num3 = num1 + num2;
    std::cout << num3.repr << std::endl;

    BigNumber num4 = num1 * num2;
    std::cout << num4.repr << std::endl;
    std::cout << pow(BigNumber("2"), BigNumber("3")).repr << std::endl;
    std::cout << pow(BigNumber("123"), BigNumber("321")).repr << std::endl;
    std::cout << pow(BigNumber("99999"), BigNumber("99999")).repr << std::endl;

    return 0;
}
