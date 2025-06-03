#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

class BigInt {
private:
    static const int BASE = 10;
    int* digits;
    size_t size;

public:
    BigInt();
    BigInt(const string& number);
    BigInt(const BigInt& other);
    BigInt(BigInt&& other);
    ~BigInt();

    BigInt& operator=(const BigInt& other);
    BigInt& operator=(BigInt&& other);

    friend ostream& operator<<(ostream& os, const BigInt& bigInt);
    friend istream& operator>>(istream& is, BigInt& bigInt);

    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    BigInt operator+(const BigInt& other) const;
    BigInt operator*(int singleDigit) const;
    BigInt operator*(const BigInt& other) const;

    BigInt power(int exponent) const;
};