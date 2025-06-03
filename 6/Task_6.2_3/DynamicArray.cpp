#include "DynamicArray.h"

void DynamicArray::resize(size_t newCapacity) {
    SpaceObject** newArray = new SpaceObject * [newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}


DynamicArray::DynamicArray() : size(0), capacity(2) {
    array = new SpaceObject * [capacity];
}
DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity) {
    array = new SpaceObject * [capacity];
    for (size_t i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}
DynamicArray::DynamicArray(DynamicArray&& other) noexcept : size(other.size), capacity(other.capacity), array(other.array) {
    other.size = 0;
    other.capacity = 0;
    other.array = nullptr;
}


DynamicArray::~DynamicArray() {
    for (size_t i = 0; i < size; ++i) {
        delete array[i];
    }
    delete[] array;
}



DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete array[i];
        }
        delete[] array;

        size = other.size;
        capacity = other.capacity;
        array = new SpaceObject * [capacity];
        for (size_t i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}
DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete array[i];
        }
        delete[] array;

        size = other.size;
        capacity = other.capacity;
        array = other.array;

        other.size = 0;
        other.capacity = 0;
        other.array = nullptr;
    }
    return *this;
}



void DynamicArray::add(SpaceObject* obj) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    array[size++] = obj;
}

void DynamicArray::remove(size_t index) {
    if (index < size) {
        delete array[index];
        for (size_t i = index; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        --size;
    }
}

void DynamicArray::print() {
    for (size_t i = 0; i < size; ++i) {
        cout << *array[i];
    }
}