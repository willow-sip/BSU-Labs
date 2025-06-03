#pragma once

#include <iostream>
#include <cstring>
using namespace std;

class SpaceObject {
protected:
    char name[50];

public:
    SpaceObject(const char* name);
    virtual ~SpaceObject();
    virtual void Print() const = 0;

    friend ostream& operator<<(ostream& os, const SpaceObject& obj);
};