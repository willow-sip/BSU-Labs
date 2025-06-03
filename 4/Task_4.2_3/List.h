#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    List() : head(nullptr) {}

    List(const T& value) {
        head = new Node(value);
    }

    List(const List& other) : head(nullptr) {
        Node* current = other.head;
        while (current) {
            add(current->data);
            current = current->next;
        }
    }

    List(List&& other) : head(other.head) {
        other.head = nullptr;
    }

    ~List() {
        clear();
    }



    List& operator=(const List& other) {
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

    void initialize(const T& value) {
        if (!head) {
            head = new Node(value);
        }
    }

    void add(const T& value) {
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

    void remove(const T& value) {
        if (!head) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
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
    }

    int countOccurrences(const T& value) const {
        int count = 0;
        Node* current = head;
        while (current) {
            if (current->data == value) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};
