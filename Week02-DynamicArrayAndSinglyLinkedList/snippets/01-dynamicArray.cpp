#include <iostream>
#include <string>
#include <vector>
#include <cassert>

template <class T>
class DynamicArray
{
private:
    static const std::size_t INCREASE_STEP = 2;
    static const std::size_t INITIAL_CAPACITY = 2;

    T* arr;
    std::size_t m_size;
    std::size_t m_capacity;

    void copy(const DynamicArray<T>& other)
    {
        this->arr = new T[other.m_capacity];
        for (std::size_t i = 0; i < other.m_size; ++i)
        {
            this->arr[i] = other.arr[i];
        }

        this->m_size = other.m_size;
        this->m_capacity = other.m_capacity;
    }

    void deallocate()
    {
        delete[] this->arr;
    }

    void resize()
    {
        T* newArr = new T[this->m_capacity * INCREASE_STEP];
        for (std::size_t i = 0; i < this->m_size; ++i)
        {
            newArr[i] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = newArr;
        this->m_capacity += INCREASE_STEP;
    }

public:
    DynamicArray()
        : arr(new T[INITIAL_CAPACITY]), m_size(0), m_capacity(INITIAL_CAPACITY) {}

    DynamicArray(const DynamicArray& other)
    {
        this->copy(other);
    }

    DynamicArray& operator = (const DynamicArray& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    ~DynamicArray()
    {
        this->deallocate();
    }

    T& front()
    {
        assert(this->m_size > 0);
        return this->arr[0];
    }

    const T& front() const
    {
        assert(this->m_size > 0);
        return this->arr[0];
    }

    T& back()
    {
        assert(this->m_size > 0);
        return this->arr[this->m_size - 1];
    }

    const T& back() const
    {
        assert(this->m_size > 0);
        return this->arr[this->m_size - 1];
    }

    T& operator [] (std::size_t index)
	{
		assert(index >= 0 && index < this->m_size);
		return this->arr[index];
	}

	const T& operator [] (std::size_t index) const
	{
		assert(index >= 0 && index < this->m_size);
		return this->arr[index];
	}

    std::size_t size() const
    {
        return this->m_size;
    }

    std::size_t capacity() const
    {
        return this->m_capacity;
    }

    bool empty() const
    {
        return this->m_size == 0;
    }

    void clear()
    {
        this->m_size = 0;
    }

    void push_back(const T& element)
    {
        if (this->m_size == this->m_capacity)
        {
            this->resize();
        }

        this->arr[this->m_size++] = element;
    }

    void pop_back()
    {
        assert(this->m_size > 0);
		--this->m_size;
    }

    class DynamicArrayIterator
    {
    private:
        friend class DynamicArray;
        T* pointer;

        DynamicArrayIterator(T* pointer) : pointer(pointer) {}

    public:
        T& operator * ()
        {
            return *pointer;
        }

        const T& operator * () const
        {
            return *pointer;
        }

        T* operator -> ()
        {
            return pointer;
        }

        const T* operator -> () const
        {
            return pointer;
        }

        DynamicArrayIterator& operator ++ () // ++it
        {
            ++pointer;
            return *this;
        }

        DynamicArrayIterator operator ++ (int) // it++
        {
            DynamicArrayIterator old = *this;
            ++(*this);
            return old;
        }

        DynamicArrayIterator& operator -- ()
        {
            --pointer;
            return *this;
        }

        DynamicArrayIterator operator -- (int)
        {
            DynamicArrayIterator old = *this;
            --(*this);
            return old;
        }

        bool operator == (const DynamicArrayIterator& other) const
		{
			return pointer == other.pointer;
		}

		bool operator != (const DynamicArrayIterator& other) const
		{
			return !(*this == other);
		}

        bool operator < (const DynamicArrayIterator& other) const
		{
			return pointer < other.pointer;
		}

		bool operator > (const DynamicArrayIterator& other) const
		{
			return pointer > other.pointer;
		}

		bool operator <= (const DynamicArrayIterator& other) const
		{
			return pointer <= other.pointer;
		}

		bool operator >= (const DynamicArrayIterator& other) const
		{
			return pointer >= other.pointer;
		}

        DynamicArrayIterator& operator += (int offset)
		{
			pointer += offset;
			return *this;
		}

		DynamicArrayIterator& operator -= (int offset)
		{
			pointer -= offset;
			return *this;
		}

		DynamicArrayIterator operator + (int offset)
		{
			DynamicArrayIterator copy(*this);
			copy += offset;
			return copy;
		}

		DynamicArrayIterator operator - (int offset)
		{
			DynamicArrayIterator copy(*this);
			copy -= offset;
			return copy;
		}

		T& operator [] (int offset) 
		{
			return *(pointer + offset);
		}

		const T& operator [] (int offset) const
		{
			return *(pointer + offset);
		}
    };

    DynamicArrayIterator begin()
    {
        return DynamicArrayIterator(this->arr);
    }

    DynamicArrayIterator end()
    {
        return DynamicArrayIterator(this->arr + this->m_size);
    }

    void insert(DynamicArrayIterator pos, const T& value)
    {
        if (pos == this->end() && this->m_size == this->m_capacity)
        {
            resize();
        }

        for (DynamicArrayIterator it = this->end(); it != pos; --it)
        {
            *it = *(it - 1);
        }
        *pos = value;
        ++this->m_size;
    }

    void erase(DynamicArrayIterator first, DynamicArrayIterator last) // [first, last)
    {
        std::size_t difference = last.pointer - first.pointer;
        assert(difference <= this->m_size);

        this->m_size -= difference;
		for (DynamicArrayIterator it = first; it != this->end(); ++it)
		{
			*it = *(it + difference);
		}
    }

    void erase(DynamicArrayIterator pos)
    {
        this->erase(pos, pos + 1);
    }
};

class Person
{
private:
    std::string name;
    int age;

public:
    Person(const std::string& name = "", int age = 0) : name(name), age(age) {}

    void print() const
    {
        std::cout << "My name is " << this->name << " and I am " << this->age << " years old." << std::endl;
    }
};

int main ()
{
    DynamicArray<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    v.push_back(11);

    for (std::size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    for (DynamicArray<int>::DynamicArrayIterator it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (int currentElement : v)
    {
        std::cout << currentElement << " ";
    }
    std::cout << std::endl;

    DynamicArray<Person> people;

    people.push_back(Person("Pesho", 22));
    people.push_back(Person("Vasko", 21));
    people.push_back(Person("Gosho", 23));

    for (std::size_t i = 0; i < people.size(); ++i)
    {
        people[i].print();
    }

    for (DynamicArray<Person>::DynamicArrayIterator it = people.begin(); it != people.end(); ++it)
    {
        it->print();
    }

    for (const Person& currentPerson: people)
    {
        currentPerson.print();
    }

    DynamicArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    arr.insert(arr.begin() + 1, 12);
    arr[1] = 12;

    for (int el : arr)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}