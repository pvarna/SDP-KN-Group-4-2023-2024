#pragma once

template <class T>
class LinkedStack
{
private:
    struct Node
    {
        T value;
        Node* next;

        Node(const T& value, Node* next = nullptr)
            : value(value), next(next) {}
    };

    Node* head;

    Node* copy(Node* other)
    {
        if (!other)
        {
            return nullptr;
        }

        Node* result = new Node(other->value);
        Node* temp = result;
    
        while(other->next)
        {
            temp->next = new Node(other->next->value);

            temp = temp->next;
            other = other->next;
        }

        return result;
    }

    void copy(const LinkedStack<T>& other)
    {
        this->head = copy(other.head);
    }

    void deallocate()
    {
        while (!this->empty())
        {
            this->pop();
        }
    }
    
public:
    LinkedStack() : head(nullptr) {}
    LinkedStack(const LinkedStack<T>& other)
    {
        this->copy(other);
    }
    LinkedStack& operator = (const LinkedStack<T>& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }
    ~LinkedStack()
    {
        this->deallocate();
    }

    const T& top() const
    {
        if (this->empty())
        {
            throw std::out_of_range("Empty stack");
        }

        return this->head->value;
    }

    void pop()
    {
        if (this->empty())
        {
            throw std::out_of_range("Empty stack");
        }

        if (!this->head->next)
        {
            delete this->head;
            this->head = nullptr;
        }
        else
        {
            Node* toDelete = this->head;
            this->head = this->head->next;
            delete toDelete;
        }
    }

    void push(const T& element)
    {
        if (this->empty())
        {
            this->head = new Node(element);
        }
        else
        {
            Node* newNode = new Node(element, this->head);
            this->head = newNode;
        }
    }

    bool empty() const
    {
        return !this->head;
    }
};