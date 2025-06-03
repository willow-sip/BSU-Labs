#include "ImmobileObject.h"
#include "MovableObject.h"
#include "DynamicArray.h"

int main() {
    DynamicArray array;

    array.add(new Star("Sun", 5500));
    array.add(new Planet("Earth", 15, true));
    array.add(new Asteroid("Ceres", 1, 2, 3, 0, 0, 0, 100));

    cout << "Array contents:" << endl;
    array.print();

    array.remove(1);

    cout << "After removing Earth:" << endl;
    array.print();

    return 0;
}