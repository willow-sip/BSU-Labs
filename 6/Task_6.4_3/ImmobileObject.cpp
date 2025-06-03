#include "ImmobileObject.h"

ImmobileObject::ImmobileObject(const char* name, float temperature, bool hasSolidSurface)
    : SpaceObject(name), temperature(temperature), hasSolidSurface(hasSolidSurface) {}

void ImmobileObject::Print() const {
    cout << "Immobile Object: " << name << ", Temperature: " << temperature
        << ", Has Solid Surface: " << (hasSolidSurface ? "Yes" : "No") << endl;
}

Star::Star(const char* name, float temperature)
    : ImmobileObject(name, temperature, false) {}

Planet::Planet(const char* name, float temperature, bool hasSolidSurface)
    : ImmobileObject(name, temperature, hasSolidSurface) {}