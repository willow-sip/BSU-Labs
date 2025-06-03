#include <iostream>
using namespace std;

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void clear(Node* node);
    void insert(Node*& node, T& value);
    bool remove(Node*& node, T& value);
    Node* find(Node* node, T& value);
    void print(Node* node);
    int countLeaves(Node* node);

public:
    BinaryTree();
    BinaryTree(T value);
    BinaryTree(BinaryTree& other);
    BinaryTree(BinaryTree&& other);
    BinaryTree& operator=(BinaryTree& other);
    BinaryTree& operator=(BinaryTree&& other);
    ~BinaryTree();

    void insert(T value);
    bool remove(T value);
    Node* find(T value);
    void print();
    void clear();

    int countLeaves();
};
