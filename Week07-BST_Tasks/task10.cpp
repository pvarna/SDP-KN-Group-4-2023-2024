#include <iostream>
#include <cmath>

struct Box 
{
   int data;
   Box* left;
   Box* right;

   Box(int data, Box* left = nullptr, Box* right = nullptr) 
    : data(data), left(left), right(right) {} 
};

Box* toTree(const int* sortedData, std::size_t size)
{
    if (!sortedData || size == 0)
    {
        return nullptr;
    }
    if (size == 1)
    {
        return new Box(sortedData[0], nullptr, nullptr);
    }
    if (size % 2 == 1)
    {
        return new Box(sortedData[size / 2], toTree(sortedData, size / 2), toTree(sortedData + (size / 2 + 1), size / 2));
    }
    else
    {
        return new Box(sortedData[size / 2], toTree(sortedData, size / 2), toTree(sortedData + (size / 2 + 1), size / 2 - 1));
    }
}

int weight(Box* root)
{
    if (!root)
    {
        return 0;
    }

    return 1 + weight(root->left) + weight(root->right);
}

bool isPerfectlyBalanced(Box* root)
{
    if (!root)
    {
        return true;
    }

    return isPerfectlyBalanced(root->left) &&
            isPerfectlyBalanced(root->right) &&
            std::abs(weight(root->left) - weight(root->right)) < 2;
}

void deallocate(Box* root)
{
    if (!root)
    {
        return;
    }

    deallocate(root->left);
    deallocate(root->right);
    delete root;
}

int main ()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    Box* tree1 = toTree(arr1, 10);
    Box* tree2 = toTree(arr2, 11);

    std::cout << std::boolalpha << isPerfectlyBalanced(tree1) << std::endl;
    std::cout << std::boolalpha << isPerfectlyBalanced(tree2) << std::endl;

    deallocate(tree1);
    deallocate(tree2);

    return 0;
}