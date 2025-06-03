#include "Vector.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Matrix {
private:
    Vector* rows;
    size_t numRows;
    size_t numCols;
    string name;
    static int counter; 

public:
    Matrix(size_t rows, size_t cols);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);
    ~Matrix();

    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other);

    void setSize(size_t newRows, size_t newCols);
    size_t getNumRows() const;
    size_t getNumCols() const;
    string getName() const;

    Vector& operator[](size_t index);
    const Vector& operator[](size_t index) const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    void print() const;
};