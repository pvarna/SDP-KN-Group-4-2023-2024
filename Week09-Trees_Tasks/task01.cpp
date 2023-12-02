#include <iostream>
#include <limits>

const int MY_INFINITY = std::numeric_limits<int>::max();

struct Box 
{
   int data;
   Box* left;
   Box* right;

   Box(int data, Box* left = nullptr, Box* right = nullptr) 
    : data(data), left(left), right(right) {} 
};

bool isBST(Box* root, int min, int max)
{
    if (!root)
    {
        return true;
    }

    return root->data > min && root->data <= max
        && isBST(root->left, min, root->data) 
        && isBST(root->right, root->data, max);
}

bool isBST(Box* root)
{
    return isBST(root, -MY_INFINITY, MY_INFINITY);
}

int main ()
{
    Box* root1 = new Box(30, new Box(20, new Box(15), new Box(25)),
                            new Box(40, new Box(35), new Box(45)));

    Box* root2 = new Box(30);

    Box* root3 = new Box(30, new Box(15), new Box(35));

    std::cout << std::boolalpha << isBST(root1) << std::endl;
    std::cout << std::boolalpha << isBST(root2) << std::endl;
    std::cout << std::boolalpha << isBST(root3) << std::endl;

    return 0;
}