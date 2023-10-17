#pragma once

template <class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList<T>();
    DoublyLinkedList<T>& operator = (const DoublyLinkedList<T>& other);
    DoublyLinkedList<T>(const DoublyLinkedList<T>& other);
    ~DoublyLinkedList<T>();

    DoublyLinkedList(std::size_t count, const T& value = T());

    std::size_t size() const;

    T& front();
    const T& front() const;
    
    T& back();
    const T& back() const;

    void clear();
    bool empty() const;

    void push_back(const T& element);
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

    void splice_after(Iterator pos, DoublyLinkedList<T>& other);
    void merge(DoublyLinkedList<T>& other);
    void unique();
};