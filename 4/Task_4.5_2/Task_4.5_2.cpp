#include "BinaryTree.cpp"

int main() {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "The tree itself: \n";
    tree.print();

    cout << "Number of leaf nodes: " << tree.countLeaves() << endl;

    return 0;
}