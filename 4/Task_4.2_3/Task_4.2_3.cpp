#include "List.h"

int main() {
    List<char> L1;
    L1.add('a');
    L1.add('b');
    L1.add('c');
    L1.add('a');
    L1.add('d');
    L1.add('b');

    cout << "Original List L1: ";
    L1.display();

    List<char> L2; 
    for (char currentChar = 'a'; currentChar <= 'z'; ++currentChar) {
        int count = L1.countOccurrences(currentChar);
        if (count > 1) {
            L2.add(currentChar);
        }
    }
    cout << "List L2 (characters appearing more than once): ";
    L2.display();

    return 0;
}