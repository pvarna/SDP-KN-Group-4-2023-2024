#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

struct Box
{
    std::string value;
    std::vector<Box*> children;

    Box(const std::string& value, const std::vector<Box*>& children = std::vector<Box*>())
        : value(value), children(children)
    {}
};

void insertNewChild(const std::string& newChild, std::vector<Box*>& currentLevel, std::vector<Box*>& lastLevel, std::size_t& currentBrotherhoodIndex)
{
    if (newChild == "*")
    {
        ++currentBrotherhoodIndex;
    }
    else
    {
        Box* newBox = new Box(newChild);
        lastLevel[currentBrotherhoodIndex]->children.push_back(newBox);
        currentLevel.push_back(newBox);
    }
}

Box* constructFromFile(const char* fileName)
{
    std::ifstream in(fileName);

    if (!in.is_open())
    {
        std::cout << "Problem while opening the file" << std::endl;
        return nullptr;
    }

    std::string rootLine;
    std::getline(in, rootLine);

    Box* root = new Box(rootLine);

    std::vector<Box*> lastLevel;
    lastLevel.push_back(root);

    while (!in.eof())
    {
        std::vector<Box*> currentLevel;
        std::string currentLine;

        std::getline(in, currentLine);
        std::size_t currentBrotherhoodIndex = 0;
        std::size_t pos = 0;

        while ((pos = currentLine.find(' ')) != std::string::npos)
        {
            std::string newChild = currentLine.substr(0, pos);
            insertNewChild(newChild, currentLevel, lastLevel, currentBrotherhoodIndex);
            currentLine.erase(0, pos + 1);
        }

        insertNewChild(currentLine, currentLevel, lastLevel, currentBrotherhoodIndex);

        lastLevel = currentLevel;
    }

    in.close();
    return root;
}

std::vector<std::vector<std::string>> getTreePerLevel(Box* root)
{
    std::vector<std::vector<std::string>> result;
    std::queue<Box*> queue;

    if (!root)
    {
        return result;
    }

    std::vector<std::string> currentLevel;
    queue.push(root);
    std::size_t elementsAtCurrentLevel = 1, elementsAtNextLevel = 0;

    while (!queue.empty())
    {
        Box* currentBox = queue.front();
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

std::string getSentenceFromLastElement(Box* root)
{
    std::vector<std::vector<std::string>> treeByLevels = getTreePerLevel(root);
    std::string result = "";

    for (std::size_t i = 0; i < treeByLevels.size(); ++i)
    {
        result += treeByLevels[i][treeByLevels[i].size() - 1];
        result += " ";
    }

    return result;
}

int main() 
{
    Box* treeRoot = constructFromFile("tree.txt");

    std::string sentence = getSentenceFromLastElement(treeRoot);
    std::cout << sentence << std::endl;

    deallocate(treeRoot);

    return 0;
}