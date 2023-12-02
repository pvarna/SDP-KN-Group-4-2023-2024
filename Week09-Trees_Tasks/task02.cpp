#include <iostream>
#include <vector>

struct Box
{
    int value;
    Box* left;
    Box* right;

    Box(int value, Box* left = nullptr, Box* right = nullptr)
        : value(value), left(left), right(right)
    {}
};

bool getKthSmallestElement(Box* root, int& k, int& result)
{
    if (!root)
    {
        return false;
    }

    if (getKthSmallestElement(root->left, k, result))
    {
        return true;
    }

    if (k == 0)
    {
        result = root->value;
        return true;
    }

    --k;

    if (getKthSmallestElement(root->right, k, result))
    {
        return true;
    }

    return false;
}

int getKthSmallestElement(Box* root, int k)
{
    int result;
    getKthSmallestElement(root, k, result);
    return result;
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
    Box* tree = new Box(20,
                            new Box(10, 
                                        new Box(5),
                                        new Box(15)),
                            new Box(30, 
                                        new Box(25),
                                        new Box(35)));

    for (std::size_t i = 1; i <= 7; ++i)
    {
        std::cout << getKthSmallestElement(tree, i) << std::endl;
    }

    deallocate(tree);

    return 0;
}