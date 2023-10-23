#pragma once

template <class T>
class DoublyLinkedList
{
private:
    struct Box
    {
        T data;
        Box* previous;
        Box* next;

        Box(const T& data, Box* previous = nullptr, Box* next = nullptr)
            : data(data), previous(previous), next(next) {}
    };

    Box* head;
    Box* tail;

    void copy(const DoublyLinkedList<T>& other)
    {
        Box* temp = other.head;

        while (temp)
        {
            this->push_back(temp->data);
            temp = temp->next;
        }
    }

    void deallocate()
    {
        while (!this->empty())
        {
            this->pop_back();
        }
    }

public:
    DoublyLinkedList<T>()
        : head(nullptr), tail(nullptr) {}

    DoublyLinkedList<T>& operator = (const DoublyLinkedList<T>& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    DoublyLinkedList<T>(const DoublyLinkedList<T>& other)
        : head(nullptr), tail(nullptr)
    {
        this->copy(other);
    }

    ~DoublyLinkedList<T>()
    {
        this->deallocate();
    }

    DoublyLinkedList(std::size_t count, const T& value = T())
        : head(nullptr), tail(nullptr)
    {
        for (std::size_t i = 0; i < count; ++i)
        {
            this->push_back(value);
        }
    }

    std::size_t size() const
    {
        Box* temp = this->head;
        std::size_t result = 0;
        
        while (temp)
        {
            ++result;
            temp = temp->next;
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

    bool empty() const
    {
        return this->head == nullptr;
    }

    void push_back(const T& element)
    {
        Box* newBox = new Box(element);

        if (this->empty())
        {
            this->head = this->tail = newBox;
        }
        else
        {
            newBox->previous = this->tail;
            this->tail->next = newBox;
            this->tail = newBox;
        }
    }
    void pop_back()
    {
        if (this->head == this->tail)
        {
            delete this->head;
            this->head = this->tail = nullptr;
            return;
        }

        Box* toDelete = this->tail;
        this->tail = this->tail->previous;
        this->tail->next = nullptr;
        delete toDelete;
    }

    void push_front(const T& element)
    {
        Box* newBox = new Box(element);

        if (this->empty())
        {
            this->head = this->tail = newBox;
        }
        else
        {
            newBox->next = this->head;
            this->head->previous = newBox;
            this->head = newBox;
        }
    }
    void pop_front()
    {
        if (this->head == this->tail)
        {
            delete this->head;
            this->head = this->tail = nullptr;
            return;
        }

        Box* toDelete = this->head;
        this->head = this->head->next;
        this->head->previous = nullptr;
        delete toDelete;
    }

    class Iterator 
    {
    private:
        friend class DoublyLinkedList;

        Box* box;
        Box* last;
        Iterator(Box* box, Box* last)
            : box(box), last(last) {}

    public:
        T& operator * ()
        {
            return this->box->data;
        }
        const T& operator * () const
        {
            return this->box->data;
        }

        T* operator -> ()
        {
            return &this->box->data;
        }
        const T* operator -> () const
        {
            return &this->box->data;
        }

        Iterator& operator ++ ()
        {
            this->box = this->box->next;

            return *this;
        }
        Iterator operator ++ (int)
        {
            Iterator old = *this;

            this->box = this->box->next;

            return old;
        }


        Iterator& operator -- ()
        {
            if (this->box == nullptr)
            {
                this->box = this->last;
            }
            else
            {
                this->box = this->box->previous;
            }

            return *this;
        }
        Iterator operator -- (int)
        {
            Iterator old = *this;

            --(*this);

            return old;
        }

        bool operator == (const Iterator& other) const
        {
            return this->box == other.box;
        }
        bool operator != (const Iterator& other) const
        {
            return this->box != other.box;
        }
    };

    Iterator begin()
    {
        return Iterator(this->head, this->tail);
    }
    Iterator end()
    {
        return Iterator(this->tail->next, this->tail);
    }

    void insert(Iterator pos, const T& value)
    {
        if (pos == this->begin())
        {
            this->push_front(value);
        }
        else if (pos == this->end())
        {
            this->push_back(value);
        }
        else
        {
            Box* newBox = new Box(value, pos.box->previous, pos.box);
            pos.box->previous->next = newBox;
            pos.box->previous = newBox;
        }
    }

    void erase(Iterator first, Iterator last)
    {
        if (first == this->begin())
        {
            while (this->head != last.box)
            {
                this->pop_front();
            }
        }
        else
        {
            Box* firstToDelete = first.box;
            Box* lastToDelete = last.box->previous;

            first.box->previous->next = last.box;
            last.box->previous = first.box->previous;
        }
    }
    void erase(Iterator pos)
    {
        if (pos == this->begin())
        {
            this->pop_front();
        }
        else if (pos.box == this->tail)
        {
            this->pop_back();
        }
        else
        {
            Box* toDelete = pos.box;
            pos.box->previous->next = pos.box->next;
            pos.box->next->previous = pos.box->previous;
            delete toDelete;
        }
    }

    void splice_after(Iterator pos, DoublyLinkedList<T>& other)
    {
        if (other.empty())
        {
            return;
        }

        if (pos == this->begin() && this->empty())
        {
            this->head = other.head;
            this->tail = other.tail;
        }
        else if (pos.box == this->tail)
        {
            this->tail->next = other.head;
            other.head->previous = this->tail;
            this->tail = other.tail;
        }
        else
        {
            other.head->previous = pos.box;
            other.tail->next = pos.box->next;
            pos.box->next->previous = other.tail;
            pos.box->next = other.head;
        }

        other.head = other.tail = nullptr;
    }
    void merge(DoublyLinkedList<T>& other)
    {
        if (this->empty() || other.empty())
        {
            return;
        }

        Box* newHead;
        if (this->head->data < other.head->data)
        {
            newHead = this->head;
            this->head = this->head->next;
        }
        else
        {
            newHead = other.head;
            other.head = other.head->next;
        }

        Box* temp = newHead;
        while (this->head && other.head)
        {
            if (this->head->data < other.head->data)
            {
                temp->next = this->head;
                this->head = this->head->next;
            }
            else
            {
                temp->next = other.head;
                other.head = other.head->next;
            }

            temp->next->previous = temp;
            temp = temp->next;
        }

        while (this->head)
        {
            temp->next = this->head;
            temp->next->previous = temp;
            temp = temp->next;

            this->head = this->head->next;
        }

        while (other.head)
        {
            temp->next = other.head;
            temp->next->previous = temp;
            temp = temp->next;

            other.head = other.head->next;
        }

        this->head = newHead;
        this->tail = temp;

        other.head = other.tail = nullptr;
    }

    void unique() 
    {
        if (this->empty()) 
        {
            return; 
        }

        Box* temp = this->head;

        while (temp->next) 
        {
            if (temp->data == temp->next->data) 
            {
                Box* toDelete = temp->next;
                temp->next = toDelete->next;

                if (temp->next) 
                {
                    temp->next->previous = temp;
                }

                delete toDelete;
            } 
            else 
            {
                temp = temp->next;
            }
        }

        this->tail = temp;
    }
};