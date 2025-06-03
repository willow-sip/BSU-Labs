#include "SpaceObject.h"

SpaceObject::SpaceObject(const char* name) {
    strncpy_s(this->name, name, sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0';
}

SpaceObject::~SpaceObject() {}

ostream& operator<<(ostream& os, const SpaceObject& obj) {
    obj.Print();
    return os;
}
