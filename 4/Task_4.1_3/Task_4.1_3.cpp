#include "Vector.h"

void makeNewArray(Vector& array) {
    Vector temp(array.getSize());
    size_t tempIndex = 0;

    for (size_t i = 0; i < array.getSize(); ++i) {
        bool isDuplicate = false;
        for (size_t j = 0; j < array.getSize(); ++j) {
            if (array[i] == temp[j] && i != j) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            temp[tempIndex++] = array[i];
        }
    }

    array.setSize(tempIndex);
    for (size_t i = 0; i < tempIndex; ++i) {
        array[i] = temp[i];
    }

    for (size_t i = 0; i < array.getSize() - 1; ++i) {
        for (size_t j = i + 1; j < array.getSize(); ++j) {
            if (array[i] < array[j]) {
                int tempValue = array[i];
                array[i] = array[j];
                array[j] = tempValue;
            }
        }
    }
}

int main() {
    int size;
    cout << "Input array's size: ";
    cin >> size;

    Vector array(size);
    cout << "Input " << size << " natural numbers: ";
    cin >> array;
    cout << "Array before changes: " << array << endl;

    makeNewArray(array);

    cout << "New array after changes: " << array;

    return 0;
}