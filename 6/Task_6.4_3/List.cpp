#include "List.h"
#include "SpaceObject.h"

List::List() : head(nullptr) {}

List::List(const List& other) : head(nullptr) {
    Node* current = other.head;
    while (current) {
        add(current->data);
        current = current->next;
    }
}

List::List(List&& other) noexcept : head(other.head) {
    other.head = nullptr;
}

List::~List() {
    clear();
}

List& List::operator=(const List& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current) {
            add(current->data);
            current = current->next;
        }
    }
    return *this;
}

List& List::operator=(List&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

void List::add(SpaceObject* value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void List::remove(SpaceObject* value) {
    if (!head) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp->data;
            delete temp;
            return;
        }
        current = current->next;
    }
}

void List::display() const {
    Node* current = head;
    while (current) {
        cout << *current->data << endl; 
        current = current->next;
    }
}

void List::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
}