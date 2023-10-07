#pragma once

template <class T>
class SinglyLinkedList
{
public:
    SinglyLinkedList<T>();
    SinglyLinkedList<T>& operator = (const SinglyLinkedList<T>& other);
    SinglyLinkedList<T>(const SinglyLinkedList<T>& other);
    ~SinglyLinkedList<T>();

    SinglyLinkedList(std::size_t count, const T& value = T());

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

		iterator& operator ++ ();
		iterator operator ++ (int);

		iterator& operator -- ();
		iterator operator -- (int);

		bool operator == (const iterator& other) const;
		bool operator != (const iterator& other) const;
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