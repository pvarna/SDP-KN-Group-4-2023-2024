#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <functional>

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

    void inorder(Box* root, std::vector<int>& current) const
    {
        if (!root)
        {
            return;
        }

        inorder(root->left, current);
        current.push_back(root->data);
        inorder(root->right, current);
    }

    void preorder(Box* root, std::vector<int>& current) const
    {
        if (!root)
        {
            return;
        }

        current.push_back(root->data);
        preorder(root->left, current);
        preorder(root->right, current);
    }

    void aniOrder(Box* root, std::vector<int>& current) const
    {
        if (!root)
        {
            return;
        }

        aniOrder(root->right, current);
        current.push_back(root->data);
        aniOrder(root->left, current);
    }

    void postorder(Box* root, std::vector<int>& current) const
    {
        if (!root)
        {
            return;
        }

        postorder(root->left, current);
        postorder(root->right, current);
        current.push_back(root->data);
    }

    int size(Box* root) const
    {
        if (!root)
        {
            return 0;
        }

        return 1 + size(root->left) + size(root->right);
    }

    int height(Box* root) const
    {
        if (!root)
        {
            return 0;
        }

        return 1 + std::max(this->height(root->left), this->height(root->right));
    }

    bool isBalanced(Box* root) const
    {
        if (!root)
        {
            return true;
        }

        return isBalanced(root->left) &&
               isBalanced(root->right) &&
               (std::abs(this->height(root->left) - this->height(root->right)) < 2);
    }

    bool isPerfectlyBalanced(Box* root) const
    {
        if (!root)
        {
            return true;
        }

        return isPerfectlyBalanced(root->left) &&
               isPerfectlyBalanced(root->right) &&
               (std::abs(this->size(root->left) - this->size(root->right)) < 2);
    }

    void leaves(Box* root, std::vector<int>& current) const
    {
        if (!root)
        {
            return;
        }

        if (!root->left && !root->right)
        {
            current.push_back(root->data);
        }

        leaves(root->left, current);
        leaves(root->right, current);
    }

    void atLevel(Box* root, std::size_t n, std::vector<int>& current) const
    {
        if (!root)
        {
            return;
        }

        if (n == 0)
        {
            current.push_back(root->data);
            return;
        }

        atLevel(root->left, n - 1, current);
        atLevel(root->right, n - 1, current);
    }

    void aniMap(Box* root, std::function<int(int)> f)
    {
        if (!root)
        {
            return;
        }

        aniMap(root->right, f);
        root->data = f(root->data);
        aniMap(root->left, f);
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

    std::vector<int> inorder() const
    {
        std::vector<int> result;

        inorder(this->root, result);

        return result;
    }

    std::vector<int> preorder() const
    {
        std::vector<int> result;

        preorder(this->root, result);

        return result;
    }

    std::vector<int> aniOrder() const
    {
        std::vector<int> result;

        aniOrder(this->root, result);

        return result;
    }

    std::vector<int> postorder() const
    {
        std::vector<int> result;

        postorder(this->root, result);

        return result;
    }

    int size() const
    {
        return this->size(this->root);
    }

    int height() const
    {
        return this->height(this->root);
    }

    bool isBalanced() const
    {
        return this->isBalanced(this->root);
    }

    bool isPerfectlyBalanced() const
    {
        return this->isPerfectlyBalanced(this->root);
    }

    int min() const
    {
        if (!this->root)
        {
            throw std::logic_error("Empty BST");
        }
        Box* temp = this->root;

        while (temp->left)
        {
            temp = temp->left;
        }

        return temp->data;
    }

    int max() const
    {
        if (!this->root)
        {
            throw std::logic_error("Empty BST");
        }
        Box* temp = this->root;

        while (temp->right)
        {
            temp = temp->right;
        }

        return temp->data;
    }

    std::vector<int> leaves() const
    {
        std::vector<int> result;

        this->leaves(this->root, result);
    
        return result;
    }

    std::vector<int> atLevel(std::size_t n) const
    {
        std::vector<int> result;

        this->atLevel(this->root, n, result);
    
        return result;
    }

    void map(std::function<int(int)> f)
    {
        aniMap(this->root, f);
    }
};