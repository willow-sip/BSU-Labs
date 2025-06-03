#include <iostream>
using namespace std;

template <typename T>
class DoubleLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    DoubleLinkedList(const T& value) {
        head = new Node(value);
        tail = head;
    }

    DoubleLinkedList(const DoubleLinkedList& other) : head(nullptr), tail(nullptr) {
        Node* current = other.head;
        while (current) {
            append(current->data);
            current = current->next;
        }
    }

    DoubleLinkedList(DoubleLinkedList&& other) : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }

    ~DoubleLinkedList() {
        clear();
    }



    DoubleLinkedList& operator=(const DoubleLinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                append(current->data);
                current = current->next;
            }
        }
        return *this;
    }


    void append(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove(const T& value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    Node* find(const T& value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void display() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    double calculateExpression(int n) {
        double result = 1.0;
        Node* left = head;
        Node* right = tail;
        int counter = 0;

        while (left && right) {
            result *= (left->data + right->data);
            left = left->next;
            right = right->prev;
            counter++;
            if (counter == n) {
                break;
            }
        }
        if (left == right && left != nullptr && right != nullptr) {
            result *= left->data;
        }

        return result;
    }
};
