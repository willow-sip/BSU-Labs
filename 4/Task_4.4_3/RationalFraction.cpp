#include "RationalFraction.h"

RationalFraction::RationalFraction() : num(0), den(1) {};

RationalFraction::RationalFraction(int numValue, int denValue) : num(numValue), den(denValue) {};

RationalFraction::RationalFraction(RationalFraction& other) : num(other.num), den(other.den) {};

RationalFraction::RationalFraction(RationalFraction&& other) : num(other.num), den(other.den) {
    other.num = other.den = 0;
};

RationalFraction& RationalFraction::operator=(RationalFraction& other) {
    if (this != &other) {
        num = other.num;
        den = other.den;
    }
    return *this;
};
RationalFraction& RationalFraction::operator=(RationalFraction&& other) noexcept {
    if (this != &other) {
        num = other.num;
        den = other.den;
        other.num = 0;
        other.den = 0;
    }
    return *this;
};

RationalFraction::~RationalFraction() {
    num = den = 0;
}

int RationalFraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}



RationalFraction RationalFraction::operator+(RationalFraction& other) {
    int newNum = num * other.den + other.num * den;
    int newDen = den * other.den;
    return RationalFraction(newNum, newDen).reduct(); 
}

RationalFraction RationalFraction::operator-(RationalFraction& other) {
    int newNum = num * other.den - other.num * den;
    int newDen = den * other.den;
    return RationalFraction(newNum, newDen).reduct();
}

RationalFraction RationalFraction::operator*(RationalFraction& other) {
    int newNum = num * other.num;
    int newDen = den * other.den;
    return RationalFraction(newNum, newDen).reduct();
}

RationalFraction RationalFraction::operator/(RationalFraction& other) {
    if (other.num == 0) {
        throw invalid_argument("Cannot divide by zero.");
    }
    int newNum = num * other.den;
    int newDen = den * other.num;
    return RationalFraction(newNum, newDen).reduct(); 
}

RationalFraction RationalFraction::reduct() {
    int divisor = gcd(num, den);
    return RationalFraction(num / divisor, den / divisor);
}

char RationalFraction::comp(RationalFraction& other) {
    if ((num * other.den) == (other.num * den)) {
        return 'e';
    }
    else {
        return (num * other.den > other.num * den) ? 'b' : 's';
    }
}



istream& operator>>(istream& is, RationalFraction& fract) {
    int numValue, denValue;
    char slash;

    if (is >> numValue >> slash >> denValue) {
        if (denValue == 0) {
            cout << "Denominator cannot be zero." << endl;
        }
        else {
            fract = RationalFraction(numValue, denValue);
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const RationalFraction& fract) {
    if (fract.den == 0) {
        os << "Undefined (denominator is zero)";
    }
    else {
        os << fract.num << "/" << fract.den;
    }
    return os;
}
