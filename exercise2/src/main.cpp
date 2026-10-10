#include <cstdlib>
#include <iostream>

class Shell
{
  public:
    int PromptUserInput()
    {
        while (!IsValidInput()) {

            std::cout << "Enter a number (0-99999): ";
            std::cin >> this->input;
        }

        return this->input;
    };

  private:
    int input = -1;
    bool IsValidInput() { return (this->input >= 0) && (this->input <= 99999); };
};

class PowerNumber
{
  public:
    PowerNumber(int number)
    {
        this->A = number;
        this->B = Reverse(number);
    };
    int GetA() const { return this->A; };
    int GetB() const { return this->B; };

  private:
    int A, B;
    int Reverse(int number)
    {
        int result = 0;
        while (number > 0) {
            std::div_t div = std::div(number, 10);
            result = result * 10 + div.rem;
            number = div.quot;
        }
        return result;
    };
};

std::ostream &operator<<(std::ostream &os, const PowerNumber &num)
{
    os << "PowerNumber(A=" << num.GetA() << ", B=" << num.GetB() << ")";
    return os;
}

int main(void)
{
    Shell shell{};

    int input = shell.PromptUserInput();
    PowerNumber num(input);

    std::cout << num << std::endl;

    return 0;
}
