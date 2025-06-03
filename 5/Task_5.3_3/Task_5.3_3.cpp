#include <iostream>
#include <forward_list>
#include <list>

using namespace std;

//2.4
list<char> filterCharacters(forward_list<char> L1) {
    int count[256] = { 0 };
    for (char ch : L1) {
        count[(unsigned char)ch]++;
    }
    list<char> L2;
    for (int i = 0; i < 256; ++i) {
        if (count[i] == 2) {
            L2.push_back(static_cast<char>(i));
        }
    }
    return L2;
}


//2.6
double calculateExpression(int n, const list<double>& x) {
    double result = 0.0;
    auto it = x.begin();

    for (int i = 0; i < n - 2; ++i) {
        double xi = *it;
        ++it;
        double xi_plus_1 = *it;

        auto reverseIt = next(x.rbegin(), i);
        double x_n_minus_i = *reverseIt;

        result += (xi + xi_plus_1 + (n - i) * x_n_minus_i);
    }

    auto lastIt = next(x.rbegin(), 1); 
    double x_n = *lastIt;
    double x_n_minus_1 = *next(lastIt); 
    auto secondElement = next(x.begin(), 1); 
    double x2 = *secondElement;

    result += (x_n_minus_1 + x_n + 2 * x2);

    return result;
}

int main() {
    //2.4
    forward_list<char> L1 = { 'a', 'b', 'c', 'a', 'd', 'b', 'e', 'f', 'g', 'g' };
    list<char> L2 = filterCharacters(L1);

    cout << "Symbols met exactly twice: ";
    for (char ch : L2) {
        cout << ch << " ";
    }
    cout << endl;


    //2.6
    int n;
    cout << "Input number of elements: ";
    cin >> n;

    list<double> list;
    cout << "Input " << n << " numbers: ";
    for (int i = 0; i < n; ++i) {
        double value;
        cin >> value;
        list.push_back(value);
    }

    double result = calculateExpression(n, list);
    cout << "Result: " << result << endl;

    return 0;
}