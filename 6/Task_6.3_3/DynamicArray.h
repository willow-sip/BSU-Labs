#pragma once
#include "SpaceObject.h"
#include "ImmobileObject.h"
#include "MovableObject.h"
#include <fstream>

class DynamicArray {
private:
    SpaceObject** array;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity);

public:
    DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray(DynamicArray&& other) noexcept;

    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray& operator=(DynamicArray&& other) noexcept;

    void add(SpaceObject* obj);
    void remove(size_t index);
    void print();
    void saveToFile(const char* filename);
    void loadFromFile(const char* filename);
};