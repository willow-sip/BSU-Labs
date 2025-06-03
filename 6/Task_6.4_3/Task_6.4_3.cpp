#include "SpaceObject.h"
#include "ImmobileObject.h"
#include "MovableObject.h"
#include "List.h"

int main() {
    List spaceObjects;

    SpaceObject* sun = new Star("Sun", 5500);
    SpaceObject* earth = new Planet("Earth", 15.0f, true);
    SpaceObject* ceres = new Asteroid("Ceres", 1.0f, 2.0f, 3.0f, 0.1f, 0.2f, 0.3f, 100.0f);
    SpaceObject* apollo = new SpaceShip("Apollo", 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 30000.0f, 5);
    SpaceObject* falcon = new Rocket("Falcon", 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 500.0f, 120.0f);

    spaceObjects.add(sun);
    spaceObjects.add(earth);
    spaceObjects.add(ceres);
    spaceObjects.add(apollo);
    spaceObjects.add(falcon);

    cout << "Space Objects in the List:" << endl;
    spaceObjects.display();

    spaceObjects.remove(sun);
    cout << "After removing Sun:" << endl;
    spaceObjects.display();


    spaceObjects.clear();

    return 0;
}