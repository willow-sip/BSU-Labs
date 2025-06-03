#pragma once

#include "SpaceObject.h"

class MovableObject : public SpaceObject {
protected:
    float x, y, z;
    float vx, vy, vz;

public:
    MovableObject(const char* name, float x, float y, float z, float vx, float vy, float vz);
    void Print() const override;
};

class Asteroid : public MovableObject {
private:
    float maxSize;

public:
    Asteroid(const char* name, float x, float y, float z, float vx, float vy, float vz, float maxSize);
    void Print() const override;
}; 

class SpaceShip : public MovableObject {
private:
    float maxSpeed;
    int ammo;

public:
    SpaceShip(const char* name, float x, float y, float z, float vx, float vy, float vz, float maxSpeed, int ammo);
    void Print() const override;
};

class Rocket : public MovableObject {
private:
    float explosivePower;
    float fuelTime;

public:
    Rocket(const char* name, float x, float y, float z, float vx, float vy, float vz, float explosivePower, float fuelTime);
    void Print() const override;
};
