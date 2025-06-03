#pragma once

#include "SpaceObject.h"

class ImmobileObject : public SpaceObject {
protected:
    float temperature;
    bool hasSolidSurface;

public:
    ImmobileObject(const char* name, float temperature, bool hasSolidSurface);
    void Print() const override;

    const float getTemperature() const { return temperature; }
    const bool getSolidSurface() const { return hasSolidSurface; }
};

class Star : public ImmobileObject {
public:
    Star(const char* name, float temperature);
};

class Planet : public ImmobileObject {
public:
    Planet(const char* name, float temperature, bool hasSolidSurface);
};