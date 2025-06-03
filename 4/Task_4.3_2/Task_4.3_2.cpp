#include "DoubleLinkedList.h"

int main()
{
    int n, number;
    cout << "Input number of elements: ";
    cin >> n;
    DoubleLinkedList<int> list;

    cout << "Input numbers(divide by space): ";
    for (int i = 0; i < n; ++i) {
        cin >> number;
        list.append(number);
    }

    double result = list.calculateExpression(n);
    cout << "Result: " << result << endl;

    list.clear();
    return 0;
}
