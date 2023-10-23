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

    // while (!empty) pop_front()

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

    // for (...other) push_back

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
        : head(nullptr), tail(nullptr)
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

    bool empty() const
    {
        return this->head == nullptr;
    }

    void print() const
    {
        Box* temp = this->head;
        while (temp)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }

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
    void pop_back()
    {
        if (this->head == this->tail)
        {
            delete this->head;
            this->head = this->tail = nullptr;
            return;
        }

        Box* temp = this->head;
        while (temp->next != this->tail)
        {
            temp = temp->next;
        }

        delete this->tail;
        this->tail = temp;
        temp->next = nullptr;
    }

    void push_front(const T& element)
    {
        Box* newBox = new Box(element);
        if (this->head == nullptr)
        {
            this->head = this->tail = newBox;
        }
        else
        {
            newBox->next = this->head;
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
        delete toDelete;
    }

    class Iterator 
    {
    private:
        friend class SinglyLinkedList;
        Box* box;

    public:
        Iterator(Box* box): box(box) {}

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

        // ++i
        Iterator& operator ++ ()
        {
            this->box = this->box->next;

            return *this;
        }

        // i++
        Iterator operator ++ (int)
        {
            Iterator old = *this;

            ++(*this);

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
        return Iterator(this->head);
    }
    Iterator end()
    {
        return Iterator(this->tail->next);
    }

    void insert_after(Iterator pos, const T& value)
    {
        if (pos.box == this->tail)
        {
            this->push_back(value);
            return;
        }

        Box* newElement = new Box(value);

        newElement->next = pos.box->next;
        pos.box->next = newElement;
    }

    void erase(Iterator first, Iterator last)
    {
        if (first == this->begin())
        {
            while (this->head != last.box)
            {
                this->pop_front();
            }
            return;
        }
        
        Box* temp = this->head;
        while (temp->next != first.box)
        {
            temp = temp->next;
        }
        if (last == this->end())
        {
            this->tail = temp;
        }

        Box* toDelete;
        while (first != last)
        {
            toDelete = first.box;
            first++;
            delete toDelete;
        }

        temp->next = last.box;
    }
    void erase(Iterator pos)
    {
        if (pos.box == this->head)
        {
            this->pop_front();
            return;
        }

        Box* temp = this->head;
        while (temp->next != pos.box)
        {
            temp = temp->next;
        }
        if (pos.box == this->tail)
        {
            this->tail = temp;
        }
        temp->next = pos.box->next;
        delete pos.box;
    }

    void splice_after(Iterator pos, SinglyLinkedList<T>& other) 
    {
        if (other.empty()) 
        {
            return;
        }

        if (this->empty()) 
        {
            this->head = other.head;
            this->tail = other.tail;
        }
        else 
        {
            other.tail->next = pos.box->next;
            pos.box->next = other.head;

            if (pos.box == this->tail) 
            {
                this->tail = other.tail;
            }
        }

        other.head = other.tail = nullptr;
    }

    void merge(SinglyLinkedList& other) 
    {
        if (this->empty()) 
        {
            this->head = other.head;
            this->tail = other.tail;

            other.head = other.tail = nullptr;
            return;
        }

        if (other.empty()) 
        {
            return;
        }
        
        Box* newHead;
        Iterator current(nullptr);
        
        Iterator it(this->head);
        Iterator otherIt(other.head);

        if (*it <= *otherIt) 
        {
            newHead = this->head;
            current.box = newHead;
            ++it;
        }
        else 
        {
            newHead = other.head;
            current.box = newHead;
            ++otherIt;
        }

        while (it != this->end() && otherIt != other.end()) 
        {
            if (*it <= *otherIt) 
            {
                current.box->next = it.box;
                ++current;
                ++it;
            }

            else 
            {
                current.box->next = otherIt.box;
                ++current;
                ++otherIt;
            }
        }

        if (it != this->end()) 
        {
            current.box->next = it.box;
        }
        else 
        {
            current.box->next = otherIt.box;
            this->tail = other.tail;
        }

        this->head = newHead;
        other.head = other.tail = nullptr;

    }

    void unique() 
    {
        if (this->empty()) 
        {
            return;
        }

        Iterator current(head);
        Iterator next(head->next);

        while (true) 
        {
            while (next != this->end() && *next == *current) 
            {
                Iterator toDelete = next;
                ++next;
                erase(toDelete);
            }

            if (next == this->end()) 
            {
                return;
            }

            current = next;
            ++next;
        }
    }
};