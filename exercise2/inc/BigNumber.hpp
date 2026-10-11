#include <algorithm>
#include <string>

class BigNumber
{
  private:
    std::string repr;

  public:
    BigNumber() = default;

    BigNumber(unsigned int number)
    {
        std::string str = std::to_string(number);
        *this = BigNumber(str);
    };

    BigNumber(std::string repr)
    {
        std::reverse(repr.begin(), repr.end());
        this->repr.assign(repr);
    }

    // Friend operators to access the repr string
    friend std::ostream &operator<<(std::ostream &os, const BigNumber &num);
    friend BigNumber pow(const BigNumber &base, const BigNumber &exponent);

    BigNumber &operator+=(const BigNumber &other)
    {
        // Alocate enough space to hold the final result plus the eventual extra carry digit
        BigNumber result;
        result.repr.resize(std::max(this->repr.size(), other.repr.size()) + 1);

        // Digit-by-digit sum with carry. Note that the representation is stored in reverse.
        int carry = 0;
        for (size_t i = 0; i < result.repr.size(); ++i) {
            int lhs = i >= this->repr.size() ? 0 : this->repr[i] - '0';
            int rhs = i >= other.repr.size() ? 0 : other.repr[i] - '0';
            int sum = lhs + rhs + carry;
            carry = sum / 10;

            char digit = static_cast<char>(sum % 10) + '0';
            result.repr[i] = digit;
        }

        // Remove the extra digit if the last addition did not produce a carry
        if (result.repr.back() == '0')
            result.repr.pop_back();

        this->repr.assign(result.repr);

        return *this;
    }

    BigNumber &operator*=(const BigNumber &other)
    {
        // Multiplication is just repeated addition.
        // This can probably be sped up by caching parts of the multiplication, I am just too lazy
        // eg. n*x = (n/2) * (2x)

        if (this->repr.find_first_not_of("0") == std::string::npos ||
            other.repr.find_first_not_of("0") == std::string::npos) {
            this->repr.assign("0");
            return *this;
        }

        BigNumber result("0");
        BigNumber it("0");
        while (it.repr.compare(other.repr)) {
            result += *this;
            ++it;
        }

        this->repr.assign(result.repr);
        return *this;
    }

    BigNumber &operator++() { return *this += BigNumber("1"); }

    bool operator==(const BigNumber &other) { return this->repr.compare(other.repr); }
};

inline BigNumber operator+(BigNumber lhs, const BigNumber &rhs)
{
    lhs += rhs;
    return lhs;
}

inline BigNumber operator*(BigNumber lhs, const BigNumber &rhs)
{
    lhs *= rhs;
    return lhs;
}

inline BigNumber pow(const BigNumber &base, const BigNumber &exponent)
{
    // Exponentiation is just repeated multiplication.
    // This can probably be sped up by caching parts of the exponentiation, I am just too lazy
    // eg. x^n = (x^2)^(n/2)
    BigNumber it("0");
    BigNumber result("1");
    while (it.repr.compare(exponent.repr)) {
        result *= base;
        ++it;
    }
    return result;
}

inline std::ostream &operator<<(std::ostream &os, const BigNumber &num)
{
    std::string tmp(num.repr);
    std::reverse(tmp.begin(), tmp.end());
    return os << tmp;
}
