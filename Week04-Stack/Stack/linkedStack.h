#pragma once

template <class T>
class LinkedStack
{
private:
    struct Node
    {
        T value;
        Node* next;
    };
    
public:
    const T& top() const;
    void pop();
    void push(const T& element);
    bool empty() const; 
};