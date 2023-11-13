#pragma once

#include <iostream>

class BST
{
private:
    struct Box
    {
        int data;
        Box* left;
        Box* right;

        Box(int data, Box* left = nullptr, Box* right = nullptr)
            : data(data), left(left), right(right) {}
    };

    Box* root;

    bool find(Box* root, int element) const
    {
        if (!root)
        {
            return false;
        }

        if (root->data == element)
        {
            return true;
        }
        else if (root->data < element)
        {
            return find(root->right, element);
        }

        return find(root->left, element);
    }

    void insert(Box*& root, int element)
    {
        if (!root)
        {
            root = new Box(element);
        }
        else if (element >= root->data)
        {
            insert(root->right, element);
        }
        else
        {
            insert(root->left, element);
        }
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

    Box* copy(Box* root)
    {
        if (!root)
        {
            return root;
        }

        return new Box(root->data, copy(root->left), copy(root->right));
    }

    void erase(Box*& root, int element)
    {
        if (!root)
        {
            return;
        }
        else if (root->data < element)
        {
            erase(root->right, element);
            return;
        }
        else if (root->data > element)
        {
            erase(root->left, element);
            return;
        }
        
        // root->data == element
        Box* toDelete = root;
        if (!root->left && !root->right)
        {
            root = nullptr;
        }
        else if (root->left && !root->right)
        {
            root = root->left;
        }
        else if (!root->left && root->right)
        {
            root = root->right;
        }
        else
        {
            Box* maxLeaf = extractMax(root->left);
            maxLeaf->left = root->left;
            maxLeaf->right = root->right;
            root = maxLeaf;
        }
        delete toDelete;
    }

    Box* extractMax(Box*& root)
    {
        if (root->right)
        {
            return extractMax(root->right);
        }

        Box* result = root;
        root = root->left;
        return result; 
    }

    void print(Box* root) const
    {
        if (!root)
        {
            return;
        }

        print(root->left);
        std::cout << root->data << " ";
        print(root->right);
    }

public:
    BST() : root(nullptr) {}
    BST(const BST& other) : root(this->copy(other.root)) {}
    BST& operator = (const BST& other)
    {
        if (&other != this)
        {
            this->deallocate(this->root);
            this->root = this->copy(other.root);
        }

        return *this;
    }
    ~BST()
    {
        this->deallocate(this->root);
    }

    bool find(int element) const
    {
        return this->find(this->root, element);
    }

    void insert(int element)
    {
        insert(this->root, element);
    }

    void erase(int element)
    {
        this->erase(this->root, element);
    }

    void print() const
    {
        print(this->root);
        std::cout << std::endl;
    }
};