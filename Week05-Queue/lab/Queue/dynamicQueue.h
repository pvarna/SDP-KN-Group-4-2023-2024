#pragma once

#include <vector>

template <class T>
class DynamicQueue
{
public:
    DynamicQueue() : frontIndex(0), backIndex(0) {}

    const T& front() const
    {
        if (this->empty()) 
        {
            throw std::out_of_range("Queue is empty");
        }
        return this->data[this->frontIndex];
    }

    void dequeue()
    {
        if (this->empty()) 
        {
            throw std::out_of_range("Queue is empty");
        }
        ++this->frontIndex;
    }

    void enqueue(const T& element)
    {
        this->data.push_back(element);
        this->backIndex = this->data.size();
    }

    bool empty() const
    {
        return this->frontIndex == this->backIndex;
    }

private:
    std::vector<T> data;
    size_t frontIndex;
    size_t backIndex; 
};