#include <iostream>
#include <vector>

struct Box
{
    int value;
    std::vector<Box*> children;

    Box(int value, const std::vector<Box*>& children)
        : value(value), children(children)
    {}
};

Box* copy(Box* root)
{
    if (!root)
    {
        return nullptr;
    }

    std::vector<Box*> buffer;
    for (std::size_t i = 0; i < root->children.size(); ++i)
    {
        buffer.push_back(copy(root->children[i]));
    }

    return new Box(root->value, buffer);
}

void deallocate(Box* root)
{
    if (!root)
    {
        return;
    }

    for (std::size_t i = 0; i < root->children.size(); ++i)
    {
        deallocate(root->children[i]);
    }
    delete root;
}