#pragma once

template <class T>
class SinglyLinkedList
{
private:
    struct Box
    {
        T data;
        Box* next;

        Box(const T& data, Box* next = nullptr): data(data), next(next) {}
    };

    Box* head;
    Box* tail;

    void deallocate()
    {
        Box* temp = head;
        while (temp != nullptr)
        {
            Box* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }

        this->head = this->tail = nullptr;
    }

    void copy(const SinglyLinkedList<T>& other)
    {
        if (other.head == nullptr)
        {
            this->head = this->tail = nullptr;
            return;
        }

        this->head = new Box(other.head->data);
        Box* temp = this->head;
        Box* tempOther = other.head;
        while (tempOther->next != other.tail)
        {
            temp->next = new Box(tempOther->next->data);
            temp = temp->next;
            tempOther = tempOther->next;
        }
        this->tail = new Box(other.tail->data);
        temp->next = this->tail;
    }

public:
    SinglyLinkedList<T>()
      : head(nullptr), tail(nullptr) {}

    SinglyLinkedList<T>& operator = (const SinglyLinkedList<T>& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    SinglyLinkedList<T>(const SinglyLinkedList<T>& other)
    {
        this->copy(other);
    }

    ~SinglyLinkedList<T>() 
    {
        this->deallocate();
    };

    SinglyLinkedList(std::size_t count, const T& value = T())
    {
        for (std::size_t i = 0; i < count; ++i)
        {
            this->push_back(value);
        }
    }

    std::size_t size() const
    {
        if (head == nullptr)
        {
            return 0;
        }
        std::size_t result = 1;

        Box* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            ++result;
        }

        return result;
    }

    T& front()
    {
        return this->head->data;
    }
    const T& front() const
    {
        return this->head->data;
    }
    T& back()
    {
        return this->tail->data;
    }
    const T& back() const
    {
        return this->tail->data;
    }

    void clear()
    {
        this->deallocate();
    }
    bool empty() const;

    void push_back(const T& element)
    {
        if (this->head == nullptr)
        {
            this->head = new Box(element);
            this->tail = this->head;
        }
        else
        {
            this->tail->next = new Box(element);
            this->tail = this->tail->next;
        }
    }
    void pop_back();

    void push_front(const T& element);
    void pop_front();

    class Iterator 
    {
    public:
        T& operator * ();
        const T& operator * () const;

        T* operator -> ();
        const T* operator -> () const;

        Iterator& operator ++ ();
        Iterator operator ++ (int);

        Iterator& operator -- ();
        Iterator operator -- (int);

        bool operator == (const Iterator& other) const;
        bool operator != (const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();

    void insert(Iterator pos, const T& value);

    void erase(Iterator first, Iterator last);
    void erase(Iterator pos);

    void splice_after(Iterator pos, SinglyLinkedList& other);
    void merge(SinglyLinkedList& other);
    void unique();
};