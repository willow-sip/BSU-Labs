#include "Matrix.h"
#include <windows.h>

int main() {
    Matrix A(3, 3);
    Sleep(500);
    Matrix B(3, 3);
    Sleep(1000);
    Matrix C(3, 3);

    A.print();
    B.print();
    C.print();

    Matrix result = A * (B+C);
    result.print();
    return 0;
}