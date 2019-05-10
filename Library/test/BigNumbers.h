#include <deque>
#include <string>


class BigNumbers{
public:
    std::deque<char> number;
    bool negative = false;

    BigNumbers();
    BigNumbers(std::string);

    int const getSize() const;

    BigNumbers operator+(const BigNumbers &rhs);
    BigNumbers operator-(const BigNumbers &rhs);
    BigNumbers operator*(const BigNumbers &rhs);
    BigNumbers operator/(const BigNumbers &rhs);
    BigNumbers operator%(const BigNumbers &rhs);
    friend bool operator>(const BigNumbers& lhs, const BigNumbers& rhs);
    friend bool operator==(const BigNumbers& lhs, const BigNumbers& rhs);

    std::string toString() const;
};
