#pragma once

template <class T>
class DynamicQueue
{
public:
    const T& front() const;
    void dequeue();
    void enqueue(const T& element);
    bool empty() const;
};
