#pragma once
#include <iostream>
using namespace std;

class SpaceObject;

class List {
private:
    struct Node {
        SpaceObject* data;
        Node* next;

        Node(SpaceObject* value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    List();
    List(const List& other);
    List(List&& other) noexcept;
    ~List();

    List& operator=(const List& other);
    List& operator=(List&& other) noexcept;

    void add(SpaceObject* value);
    void remove(SpaceObject* value);
    void display() const;
    void clear();
};