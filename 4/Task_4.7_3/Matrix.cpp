#include "Matrix.h"

int Matrix::counter = 0;

Matrix::Matrix(size_t rows, size_t cols) : numRows(rows), numCols(cols) {
    this->rows = new Vector[numRows];
    for (size_t i = 0; i < numRows; ++i) {
        this->rows[i] = Vector(numCols);
    }
    counter++;
    name = "Matrix " + to_string(counter);
}

Matrix::Matrix(const Matrix& other) : numRows(other.numRows), numCols(other.numCols) {
    this->rows = new Vector[numRows];
    for (size_t i = 0; i < numRows; ++i) {
        this->rows[i] = other.rows[i];
    }
    name = other.name;
}

Matrix::Matrix(Matrix&& other) : rows(other.rows), numRows(other.numRows), numCols(other.numCols), name(other.name) {
    other.rows = nullptr;
    other.numRows = 0;
    other.numCols = 0;
}

Matrix::~Matrix() {
    delete[] rows;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        delete[] rows;
        numRows = other.numRows;
        numCols = (other.numCols);
        this->rows = new Vector[numRows];
        for (size_t i = 0; i < numRows; ++i) {
            this->rows[i] = other.rows[i];
        }
        name = other.name;
    }
    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) {
    if (this != &other) {
        delete[] rows;
        numRows = other.numRows;
        numCols = (other.numCols);
        this->rows = new Vector[numRows];
        for (size_t i = 0; i < numRows; ++i) {
            this->rows[i] = other.rows[i];
        }
        name = other.name;

        other.rows = nullptr;
        other.numRows = 0;
        other.numCols = 0;
    }
    return *this;
}

void Matrix::setSize(size_t newRows, size_t newCols) {
    delete[] rows;
    numRows = newRows;
    numCols = newCols;
    rows = new Vector[numRows];
    for (size_t i = 0; i < numRows; ++i) {
        rows[i] = Vector(numCols);
    }
}

size_t Matrix::getNumRows() const {
    return numRows;
}
size_t Matrix::getNumCols() const {
    return numCols;
}
string Matrix::getName() const {
    return name;
}
Vector& Matrix::operator[](size_t index) {
    if (index >= numRows) {
        throw out_of_range("Row index out of range");
    }
    return rows[index];
}

const Vector& Matrix::operator[](size_t index) const {
    if (index >= numRows) {
        throw out_of_range("Row index out of range");
    }
    return rows[index];
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (numRows != other.numRows || numCols != other.numCols) {
        throw invalid_argument("Matrix dimensions must match for addition");
    }
    Matrix result(numRows, numCols);
    for (size_t i = 0; i < numRows; ++i) {
        for (size_t j = 0; j < numCols; ++j) {
            result[i][j] = rows[i][j] + other[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (numCols != other.numRows) {
        throw invalid_argument("Matrix dimensions must match for multiplication");
    }
    Matrix result(numRows, other.numCols);
    for (size_t i = 0; i < numRows; ++i) {
        for (size_t j = 0; j < other.numCols; ++j) {
            for (size_t k = 0; k < numCols; ++k) {
                result[i][j] += rows[i][k] * other[k][j];
            }
        }
    }
    return result;
}

void Matrix::print() const {
    cout << name << ":\n";
    for (size_t i = 0; i < numRows; ++i) {
        cout << rows[i] << endl;
    }
}