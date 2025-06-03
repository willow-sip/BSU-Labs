#include <iostream>
using namespace std;

int someFunction() {
    int a = 10;
    double b = 3.14; 
    const int MAX_VALUE = 100; 
    const double PI = 3.14159;

    cout << "Hello, World!" << endl;
    cout << "a: " << a << ", b: " << b << endl;

    for (int i = 0; i < MAX_VALUE; i++) {
        if (i % 10 == 0) {
            cout << "i: " << i << endl;
        }
    }

    double area = PI * b * b; 
    cout << "Area of circle: " << area << endl;

    return 0;
}