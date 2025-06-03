#include "DynamicArray.h"

void DynamicArray::resize(size_t newCapacity) {
    SpaceObject** newArray = new SpaceObject * [newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}


DynamicArray::DynamicArray() : size(0), capacity(2) {
    array = new SpaceObject * [capacity];
}
DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity) {
    array = new SpaceObject * [capacity];
    for (size_t i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}
DynamicArray::DynamicArray(DynamicArray&& other) noexcept : size(other.size), capacity(other.capacity), array(other.array) {
    other.size = 0;
    other.capacity = 0;
    other.array = nullptr;
}


DynamicArray::~DynamicArray() {
    for (size_t i = 0; i < size; ++i) {
        delete array[i];
    }
    delete[] array;
}



DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete array[i];
        }
        delete[] array;

        size = other.size;
        capacity = other.capacity;
        array = new SpaceObject * [capacity];
        for (size_t i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}
DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete array[i];
        }
        delete[] array;

        size = other.size;
        capacity = other.capacity;
        array = other.array;

        other.size = 0;
        other.capacity = 0;
        other.array = nullptr;
    }
    return *this;
}



void DynamicArray::add(SpaceObject* obj) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    array[size++] = obj;
}

void DynamicArray::remove(size_t index) {
    if (index < size) {
        delete array[index];
        for (size_t i = index; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        --size;
    }
}

void DynamicArray::print() {
    for (size_t i = 0; i < size; ++i) {
        cout << *array[i];
    }
}

void DynamicArray::saveToFile(const char* filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    outFile << size << endl; // Сохраняем количество объектов
    for (size_t i = 0; i < size; ++i) {
        if (dynamic_cast<Star*>(array[i])) {
            Star* star = static_cast<Star*>(array[i]);
            outFile << "Star " << star->getName() << " " << star->getTemperature() << endl;
        }
        else if (dynamic_cast<Planet*>(array[i])) {
            Planet* planet = static_cast<Planet*>(array[i]);
            outFile << "Planet " << planet->getName() << " " << planet->getTemperature() << " " << planet->getSolidSurface() << endl;
        }
        else if (dynamic_cast<Asteroid*>(array[i])) {
            Asteroid* asteroid = static_cast<Asteroid*>(array[i]);
            outFile << "Asteroid " << asteroid->getName() << " " << asteroid->getX() << " " << asteroid->getY() << " " << asteroid->getZ() << " "
                << asteroid->getVx() << " " << asteroid->getVy() << " " << asteroid->getVz() << " " << asteroid->getMaxSize() << endl;
        }
        else if (dynamic_cast<SpaceShip*>(array[i])) {
            SpaceShip* ship = static_cast<SpaceShip*>(array[i]);
            outFile << "SpaceShip " << ship->getName() << " " << ship->getX() << " " << ship->getY() << " " << ship->getZ() << " "
                << ship->getVx() << " " << ship->getVy() << " " << ship->getVz() << " " << ship->getMaxSpeed() << " " << ship->getAmmo() << endl;
        }
        else if (dynamic_cast<Rocket*>(array[i])) {
            Rocket* rocket = static_cast<Rocket*>(array[i]);
            outFile << "Rocket " << rocket->getName() << " " << rocket->getX() << " " << rocket->getY() << " " << rocket->getZ() << " "
                << rocket->getVx() << " " << rocket->getVy() << " " << rocket->getVz() << " " << rocket->getExplosivePower() << " " << rocket->getFuelTime() << endl;
        }
    }
    outFile.close();
}

void DynamicArray::loadFromFile(const char* filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return;
    }

    size_t count;
    inFile >> count;
    inFile.ignore();

    for (size_t i = 0; i < count; ++i) {
        string type;
        inFile >> type;

        if (type == "Star") {
            char name[50];
            float temperature;
            inFile >> name >> temperature;
            add(new Star(name, temperature));
        }
        else if (type == "Planet") {
            char name[50];
            float temperature;
            bool hasSolidSurface;
            inFile >> name >> temperature >> hasSolidSurface;
            add(new Planet(name, temperature, hasSolidSurface));
        }
        else if (type == "Asteroid") {
            char name[50];
            float x, y, z, vx, vy, vz, maxSize;
            inFile >> name >> x >> y >> z >> vx >> vy >> vz >> maxSize;
            add(new Asteroid(name, x, y, z, vx, vy, vz, maxSize));
        }
        else if (type == "SpaceShip") {
            char name[50];
            float x, y, z, vx, vy, vz, maxSpeed;
            int ammo;
            inFile >> name >> x >> y >> z >> vx >> vy >> vz >> maxSpeed >> ammo;
            add(new SpaceShip(name, x, y, z, vx, vy, vz, maxSpeed, ammo));
        }
        else if (type == "Rocket") {
            char name[50];
            float x, y, z, vx, vy, vz, explosivePower, fuelTime;
            inFile >> name >> x >> y >> z >> vx >> vy >> vz >> explosivePower >> fuelTime;
            add(new Rocket(name, x, y, z, vx, vy, vz, explosivePower, fuelTime));
        }
    }
    inFile.close();
}