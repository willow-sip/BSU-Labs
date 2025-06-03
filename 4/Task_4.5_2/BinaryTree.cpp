#include "BinaryTree.h"

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::BinaryTree(T value) : root(value) {}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree& other) : root(other.root) {}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree&& other) : root(other.root) {
    other.root = nullptr;
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree& other) {
    if (this != &other) {
        clear();
        root = other.root;
    }
    return *this;
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree&& other) {
    if (this != &other) {
        clear();
        root = other.root;
        other.root = nullptr;
    }
    return *this;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear();
}



template <typename T>
void BinaryTree<T>::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
void BinaryTree<T>::insert(Node*& node, T& value) {
    if (!node) {
        node = new Node(value);
    }
    else if (value < node->data) {
        insert(node->left, value);
    }
    else {
        insert(node->right, value);
    }
}

template <typename T>
bool BinaryTree<T>::remove(Node*& node, T& value) {
    if (!node) return false;

    if (value < node->data) {
        return remove(node->left, value);
    }
    else if (value > node->data) {
        return remove(node->right, value);
    }
    else {
        if (!node->left) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (!node->right) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node* minNode = node->right;
            while (minNode->left) {
                minNode = minNode->left;
            }
            node->data = minNode->data;
            remove(node->right, minNode->data);
        }
        return true;
    }
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::find(Node* node, T& value) {
    if (!node) return nullptr;
    if (value < node->data) {
        return find(node->left, value);
    }
    else if (value > node->data) {
        return find(node->right, value);
    }
    else {
        return node;
    }
}

template <typename T>
void BinaryTree<T>::print(Node* node) {
    if (node) {
        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }
}

template <typename T>
int BinaryTree<T>::countLeaves(Node* node) {
    if (!node) {
        return 0; 
    }
    if (!node->left && !node->right) {
        return 1;
    }
    return countLeaves(node->left) + countLeaves(node->right);
}




template <typename T>
void BinaryTree<T>::insert(T value) {
    insert(root, value);
}

template <typename T>
bool BinaryTree<T>::remove(T value) {
    return remove(root, value);
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::find(T value) {
    return find(root, value);
}

template <typename T>
void BinaryTree<T>::print() {
    print(root);
    cout << std::endl;
}

template <typename T>
void BinaryTree<T>::clear() {
    clear(root);
    root = nullptr;
}

template <typename T>
int BinaryTree<T>::countLeaves() {
    return countLeaves(root);
}