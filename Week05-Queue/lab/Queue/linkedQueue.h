#pragma once

template <class T>
class LinkedQueue
{
private:
    struct Node
    {
        T value;
        Node* next;
        Node* previous;

        Node(const T& value, Node* next = nullptr, Node* previous = nullptr)
            : value(value), next(next), previous(previous) {}
    };
public:
    const T& front() const;
    void dequeue();
    void enqueue(const T& element);
    bool empty() const;
};