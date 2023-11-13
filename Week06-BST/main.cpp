#include "bst.h"

int main ()
{
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(8);
    bst.insert(12);
    bst.insert(18);
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.insert(9);
    bst.insert(11);
    bst.insert(14);
    bst.insert(16);
    bst.insert(20);

    bst.erase(10);

    bst.print();

    return 0;
}