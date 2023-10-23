#pragma once

template <class T>
class DynamicStack
{
public:
    const T& top() const;
    void pop();
    void push(const T& element);
    bool empty() const; 
};