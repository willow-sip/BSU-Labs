#include "DynamicArray.h"

int main() {
    DynamicArray spaceObjects;

    spaceObjects.loadFromFile("space_objects.txt");

    spaceObjects.add(new Star("Sun", 5500));
    spaceObjects.add(new Planet("Earth", 15, true));
    spaceObjects.add(new Asteroid("Ceres", 1.0, 2.0, 3.0, 0.1, 0.2, 0.3, 1000));
    spaceObjects.add(new SpaceShip("Apollo", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20000, 5));
    spaceObjects.add(new Rocket("Falcon", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 500, 300));

    spaceObjects.print();

    spaceObjects.saveToFile("space_objects.txt");

    return 0;
}