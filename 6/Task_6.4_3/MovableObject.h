#pragma once

#include "SpaceObject.h"

class MovableObject : public SpaceObject {
protected:
    float x, y, z;
    float vx, vy, vz;

public:
    MovableObject(const char* name, float x, float y, float z, float vx, float vy, float vz);
    void Print() const override;

    const float getX() const { return x; }
    const float getY() const { return y; }
    const float getZ() const { return z; }

    const float getVx() const { return vx; }
    const float getVy() const { return vy; }
    const float getVz() const { return vz; }
};

class Asteroid : public MovableObject {
private:
    float maxSize;

public:
    Asteroid(const char* name, float x, float y, float z, float vx, float vy, float vz, float maxSize);
    void Print() const override;

    const float getMaxSize() const { return maxSize; }
};

class SpaceShip : public MovableObject {
private:
    float maxSpeed;
    int ammo;

public:
    SpaceShip(const char* name, float x, float y, float z, float vx, float vy, float vz, float maxSpeed, int ammo);
    void Print() const override;

    const float getMaxSpeed() const { return maxSpeed; }
    const int getAmmo() const { return ammo; }
};

class Rocket : public MovableObject {
private:
    float explosivePower;
    float fuelTime;

public:
    Rocket(const char* name, float x, float y, float z, float vx, float vy, float vz, float explosivePower, float fuelTime);
    void Print() const override;

    const float getExplosivePower() const { return explosivePower; }
    const float getFuelTime() const { return fuelTime; }
};