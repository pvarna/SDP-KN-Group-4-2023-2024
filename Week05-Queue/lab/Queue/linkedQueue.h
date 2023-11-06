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

    Node* frontNode;
    Node* backNode;

    void deallocate()
    {
        while (!this->empty()) 
        {
            this->dequeue();
        }
    }

    void copy(const LinkedQueue<T>& other)
    {
        Node* temp = other.frontNode;

        while (temp)
        {
            this->enqueue(temp->value);
            temp = temp->next;
        }
    }

public:
    LinkedQueue() : frontNode(nullptr), backNode(nullptr) {}

    LinkedQueue(const LinkedQueue<T>& other)
        : LinkedQueue() 
    {
        this->copy(other);
    }

    LinkedQueue& operator = (const LinkedQueue<T>& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    const T& front() const
    {
        if (this->empty()) 
        {
            throw std::out_of_range("Queue is empty");
        }
        return this->frontNode->value;
    }

    void dequeue()
    {
        if (this->empty()) 
        {
            throw std::out_of_range("Queue is empty");
        }

        Node* temp = this->frontNode;
        this->frontNode = this->frontNode->next;
        if (this->frontNode) 
        {
            this->frontNode->previous = nullptr;
        }
        delete temp;
    }

    void enqueue(const T& element)
    {
        Node* newNode = new Node(element, nullptr, this->backNode);
        if (this->empty()) 
        {
            this->frontNode = newNode;
        }
        else 
        {
            this->backNode->next = newNode;
        }
        this->backNode = newNode;
    }

    bool empty() const
    {
        return this->frontNode == nullptr;
    }

    ~LinkedQueue()
    {
        this->deallocate();
    }
};
