#include <iostream>
#include <vector>
#include <queue>

struct Box
{
    int value;
    std::vector<Box*> children;

    Box(int value, const std::vector<Box*>& children)
        : value(value), children(children)
    {}
};

int getHeight(Box* root)
{
    if (!root)
    {
        return 0;
    }

    int buffer = 0;
    for (std::size_t i = 0; i < root->children.size(); ++i)
    {
        buffer = std::max(buffer, getHeight(root->children[i]));
    }

    return 1 + buffer;
}

std::vector<std::vector<int>> getTreePerLevel(Box* root)
{
    std::vector<std::vector<int>> result;
    std::queue<Box*> queue;

    if (!root)
    {
        return result;
    }

    std::vector<int> currentLevel;
    queue.push(root);
    std::size_t elementsAtCurrentLevel = 1, elementsAtNextLevel = 0;

    while (!queue.empty())
    {
        Box* currentBox = queue.front();
        std::cout << "Current value: " << currentBox->value << std::endl;
        currentLevel.push_back(currentBox->value);
        queue.pop();
        --elementsAtCurrentLevel;

        for (std::size_t i = 0; i < currentBox->children.size(); ++i)
        {
            ++elementsAtNextLevel;
            queue.push(currentBox->children[i]);
        }

        if (elementsAtCurrentLevel == 0)
        {
            result.push_back(currentLevel);
            currentLevel.clear();
            elementsAtCurrentLevel = elementsAtNextLevel;
            elementsAtNextLevel = 0;
        }
    }

    return result;
}

Box* createTree(int value, int arity, int depth) 
{
    if (depth <= 0) {
        return nullptr;
    }

    Box* root = new Box(value, std::vector<Box*>());

    for (int i = 0; i < arity; ++i) 
    {
        int childValue = value * 10 + i + 1; // Just an example for child values
        Box* child = createTree(childValue, arity, depth - 1);
        if (child)
        {
            root->children.push_back(child);
        }
    }

    return root;
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

// Usage example for arity 2, depth 2
int main() 
{
    int rootValue = 1; // Example root value
    int arity = 4;
    int depth = 3;

    Box* treeRoot = createTree(rootValue, arity, depth);
    std::cout << "Suzdadohme durvoto" << std::endl;
    
    std::vector<std::vector<int>> levels = getTreePerLevel(treeRoot);

    for (std::size_t i = 0; i < levels.size(); ++i)
    {
        std::cout << "Level " << i << ": ";
        for (std::size_t j = 0; j < levels[i].size(); ++j)
        {
            std::cout << levels[i][j] << " ";
        }
        std::cout << std::endl;
    }

    deallocate(treeRoot);

    return 0;
}