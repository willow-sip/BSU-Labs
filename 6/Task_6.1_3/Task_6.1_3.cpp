#include "ImmobileObject.h"
#include "MovableObject.h"

int main() {
    Star sun("Sun", 5500);
    Planet earth("Earth", 15, true);
    Asteroid asteroid("Asteroid 1", 10, 20, 30, 1, 1, 1, 5);
    SpaceShip ship("Spaceship", 0, 0, 0, 0, 0, 0, 100, 10);
    Rocket rocket("Rocket 1", 1, 1, 1, 0.5, 0.5, 0.5, 50, 30);

    SpaceObject* objects[] = { &sun, &earth, &asteroid, &ship, &rocket};

    for (SpaceObject* obj : objects) {
        cout << *obj << endl;
    }

    return 0;
}