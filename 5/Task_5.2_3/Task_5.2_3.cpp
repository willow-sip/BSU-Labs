#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//2.2
vector<double> multiplyMatrixByVector(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    vector<double> c(n, 0.0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i] += A[i][j] * b[j];
        }
    }
    return c;
}

vector<vector<double>> multiplyMatrix(vector<vector<double>> A) {
    int n = A.size();
    vector<vector<double>> result(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * A[k][j];
            }
        }
    }
    return result;
}

int main()
{
    //2.2
    int n;
    cout << "Input matrix size (n): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Input elements of matrix A:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Input elements of vector b:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<vector<double>> squaredA = multiplyMatrix(A);
    vector<double> c = multiplyMatrixByVector(squaredA, b);

    cout << "Vector c = A^2 * b:" << endl;
    for (const double& value : c) {
        cout << value << " ";
    }
    cout << endl;


    //2.1
    const int MAX_NUMBER = pow(10, 7);
    vector<bool> seen(MAX_NUMBER + 1, false);

    int number;
    cout << "Input natural numbers (1 to 10^7). Enter -1 to finish input:" << endl;
    while (cin >> number) {
        if (number == -1) {
            break;
        }
        if (number >= 1 && number <= MAX_NUMBER) {
            seen[number] = true;
        }
    }

    vector<int> missing_numbers;
    for (int i = 1; i <= MAX_NUMBER; ++i) {
        if (!seen[i]) {
            missing_numbers.push_back(i);
        }
    }

    for (const int& num : missing_numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
