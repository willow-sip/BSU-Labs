#include "BigInt.h"

int main() {
    BigInt number("178710937610");
    BigInt result = number.power(3);
    cout << "(178710937610)^3 = " << result << endl;
    return 0;
}