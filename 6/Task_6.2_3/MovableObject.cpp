#include "MovableObject.h"

MovableObject::MovableObject(const char* name, float x, float y, float z, float vx, float vy, float vz)
    : SpaceObject(name), x(x), y(y), z(z), vx(vx), vy(vy), vz(vz) {}

void MovableObject::Print() const {
    cout << "Movable Object: " << name << ", Position: (" << x << ", " << y << ", " << z
        << "), Velocity: (" << vx << ", " << vy << ", " << vz << ")" << endl;
}

Asteroid::Asteroid(const char* name, float x, float y, float z, float vx, float vy, float vz, float maxSize)
    : MovableObject(name, x, y, z, vx, vy, vz), maxSize(maxSize) {}

void Asteroid::Print() const {
    MovableObject::Print();
    cout << "Max Size: " << maxSize << endl;
}

SpaceShip::SpaceShip(const char* name, float x, float y, float z, float vx, float vy, float vz, float maxSpeed, int ammo)
    : MovableObject(name, x, y, z, vx, vy, vz), maxSpeed(maxSpeed), ammo(ammo) {}

void SpaceShip::Print() const {
    MovableObject::Print();
    cout << "Max Speed: " << maxSpeed << ", Ammo: " << ammo << endl;
}

Rocket::Rocket(const char* name, float x, float y, float z, float vx, float vy, float vz, float explosivePower, float fuelTime)
    : MovableObject(name, x, y, z, vx, vy, vz), explosivePower(explosivePower), fuelTime(fuelTime) {}

void Rocket::Print() const {
    MovableObject::Print();
    cout << "Explosive Power: " << explosivePower << ", Fuel Time: " << fuelTime << " seconds" << endl;
}