#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Vector {
private:
    int* data; 
    size_t size;

public:
    Vector();                      
    Vector(size_t size);
    Vector(const Vector& other);
    Vector(Vector&& other);

    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);
    ~Vector();

    void setSize(size_t newSize);   
    size_t getSize() const;         
    void fillRandom();     


    int& operator[](size_t index);   
    const int& operator[](size_t index) const; 

    friend istream& operator>>(istream& is, Vector& vec);
    friend ostream& operator<<(ostream& os, const Vector& vec);
};