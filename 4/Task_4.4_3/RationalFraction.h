#include <iostream>
using namespace std;

class RationalFraction {
public:
    int num;
    int den;


	RationalFraction();
	RationalFraction(int numValue, int denValue);
    RationalFraction(RationalFraction& other);
    RationalFraction(RationalFraction&& other);
    RationalFraction& operator=(RationalFraction& other);
    RationalFraction& operator=(RationalFraction&& other) noexcept;
    ~RationalFraction();

    int gcd(int a, int b);
    RationalFraction operator+(RationalFraction& other);
    RationalFraction operator-(RationalFraction& other);
    RationalFraction operator*(RationalFraction& other);
    RationalFraction operator/(RationalFraction& other);
    RationalFraction reduct();
    char comp(RationalFraction& other);


    friend istream& operator>>(istream& is, RationalFraction& fract);
    friend ostream& operator<<(ostream& os, const RationalFraction& fract);
};