#include "bst.h"

void print(const std::vector<int>& v)
{
    for (auto el : v)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int main ()
{
    BST bst;
    bst.insert(18);
    bst.insert(14);
    bst.insert(23);
    bst.insert(10);
    bst.insert(15);
    bst.insert(19);
    bst.insert(50);
    bst.insert(6);
    bst.insert(11);
    bst.insert(17);
    bst.insert(18);
    bst.insert(20);
    bst.insert(63);
    // bst.insert(10);
    // bst.insert(10);
    // bst.insert(10);

    std::vector<int> inorder = bst.inorder();
    print(inorder);

    std::vector<int> preorder = bst.preorder();
    print(preorder);

    std::vector<int> aniOrder = bst.aniOrder();
    print(aniOrder);

    std::vector<int> postorder = bst.postorder();
    print(postorder);

    std::cout << "size: " << bst.size() << std::endl;
    std::cout << "height: " << bst.height() << std::endl;
    std::cout << std::boolalpha << "is balanced: " << bst.isBalanced() << std::endl;
    std::cout << std::boolalpha << "is perfectly balanced: " << bst.isPerfectlyBalanced() << std::endl;
    std::cout << "min: " << bst.min() << std::endl;
    std::cout << "max: " << bst.max() << std::endl;

    std::vector<int> leaves = bst.leaves();
    print(leaves);

    std::vector<int> levelN = bst.atLevel(2);
    print(levelN);

    bst.map([](int x)->int{return 2 * x;});
    std::vector<int> afterMap = bst.aniOrder();
    print(afterMap);

    return 0;
}