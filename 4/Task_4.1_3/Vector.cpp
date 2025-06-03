#include "Vector.h"

Vector::Vector() : data(nullptr), size(0) {}

Vector::Vector(size_t size) : size(size) {
    data = new int[size];
    fillRandom();
}

Vector::Vector(const Vector& other) : size(other.size) {
    data = new int[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Vector::Vector(Vector&& other) : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}


Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) {
    if (this != &other) {
        delete[] data; 
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}


Vector::~Vector() {
    delete[] data;
}


void Vector::setSize(size_t newSize) {
    delete[] data;
    size = newSize;
    data = new int[size];
    fillRandom();
}

size_t Vector::getSize() const {
    return size;
}

void Vector::fillRandom() {
    srand(time(0));
    for (size_t i = 0; i < size; ++i) {
        data[i] = rand() % 100; 
    }
}


int& Vector::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const int& Vector::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}


istream& operator>>(istream& is, Vector& vector) {
    for (size_t i = 0; i < vector.size; ++i) {
        is >> vector.data[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const Vector& vector) {
    for (size_t i = 0; i < vector.size; ++i) {
        os << vector.data[i] << " ";
    }
    return os;
}