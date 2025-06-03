#include "BigInt.h"

BigInt::BigInt() : size(1) {
    digits = new int[size];
    digits[0] = 0;
}

BigInt::BigInt(const string& number) {
    size = number.length();
    digits = new int[size];

    for (size_t i = 0; i < size; ++i) {
        if (isdigit(number[size - 1 - i])) {
            digits[i] = number[size - 1 - i] - '0';
        }
        else {
            throw invalid_argument("Error character read");
        }
    }
}

BigInt::BigInt(const BigInt& other) : size(other.size) {
    digits = new int[size];
    for (size_t i = 0; i < size; ++i) {
        digits[i] = other.digits[i];
    }
}

BigInt::BigInt(BigInt&& other) : digits(other.digits), size(other.size) {
    other.digits = nullptr;
    other.size = 0;
}

BigInt::~BigInt() {
    delete[] digits;
}


BigInt& BigInt::operator=(const BigInt& other) {
    if (this != &other) {
        delete[] digits;
        size = other.size;
        digits = new int[size];
        for (size_t i = 0; i < size; ++i) {
            digits[i] = other.digits[i];
        }
    }
    return *this;
}

BigInt& BigInt::operator=(BigInt&& other) {
    if (this != &other) {
        delete[] digits;
        digits = other.digits;
        size = other.size;
        other.digits = nullptr;
        other.size = 0;
    }
    return *this;
}



ostream& operator<<(ostream& os, const BigInt& bigInt) {
    for (size_t i = bigInt.size; i > 0; --i) {
        os << bigInt.digits[i - 1];
    }
    return os;
}
istream& operator>>(istream& is, BigInt& bigInt) {
    string number;
    is >> number;
    bigInt = BigInt(number);
    return is;
}



int& BigInt::operator[](size_t index) {
    return digits[index];
}
const int& BigInt::operator[](size_t index) const {
    return digits[index];
}



BigInt BigInt::operator+(const BigInt& other) const {
    size_t maxSize = (size > other.size) ? size : other.size;
    BigInt result;
    result.size = maxSize + 1;
    result.digits = new int[result.size]();

    int carry = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        int sum = carry;
        if (i < size) sum += digits[i];
        if (i < other.size) sum += other.digits[i];
        result.digits[i] = sum % BASE;
        carry = sum / BASE;
    }
    if (carry) result.digits[maxSize] = carry;

    while (result.size > 1 && result.digits[result.size - 1] == 0) {
        result.size--;
    }
    return result;
}

BigInt BigInt::operator*(int singleDigit) const {
    BigInt result;
    result.size = size + 1;
    result.digits = new int[result.size]();

    int carry = 0;
    for (size_t i = 0; i < size; ++i) {
        int product = digits[i] * singleDigit + carry;
        result.digits[i] = product % BASE;
        carry = product / BASE;
    }
    if (carry) result.digits[size] = carry;

    while (result.size > 1 && result.digits[result.size - 1] == 0) {
        result.size--;
    }
    return result;
}

BigInt BigInt::operator*(const BigInt& other) const {
    BigInt result;
    result.size = size + other.size;
    result.digits = new int[result.size]();

    for (size_t i = 0; i < size; ++i) {
        int carry = 0;
        for (size_t j = 0; j < other.size; ++j) {
            int product = digits[i] * other.digits[j] + result.digits[i + j] + carry;
            result.digits[i + j] = product % BASE;
            carry = product / BASE;
        }
        result.digits[i + other.size] += carry;
    }

    while (result.size > 1 && result.digits[result.size - 1] == 0) {
        result.size--;
    }
    return result;
}

BigInt BigInt::power(int exponent) const {
    BigInt result("1");
    BigInt base = *this;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        exponent /= 2;
    }
    return result;
}