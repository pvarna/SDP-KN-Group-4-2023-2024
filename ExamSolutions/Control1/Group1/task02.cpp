#include <iostream>
#include <vector>

template <typename T>
struct box 
{
    T data; 
    box *next, *prev;

    box(const T& data, box* next = nullptr, box* prev = nullptr)
        : data(data), next(next), prev(prev) {}
};

box<int>* fromVector(const std::vector<int>& vector)
{
    if (vector.empty())
    {
        return nullptr;
    }

    box<int>* head = new box<int>(vector[0]);
    box<int>* temp = head;

    for (std::size_t i = 1; i < vector.size(); ++i)
    {
        temp->next = new box<int>(vector[i], nullptr, temp);
        temp = temp->next;
    }

    return head;
}

void print(box<int>* head)
{
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void deallocate(box<int>* head)
{
    while (head)
    {
        box<int>* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

void remove_disorder(box<int>* head)
{
    if (!head || !head->next)
    {
        return;
    }

    box<int>* first = head;
    box<int>* second = head->next;

    while (second)
    {
        if (first->data >= second->data)
        {
            box<int>* toDelete = second;
            first->next = second->next;
            if (second->next)
            {
                second->next->prev = first;
            }
            second = second->next;
            
            delete toDelete;
        }
        else
        {
            first = first->next;
            second = second->next;
        }
    }
}

void test(const std::vector<int>& vector)
{
    box<int>* list = fromVector(vector);

    remove_disorder(list);
    print(list);

    deallocate(list);
}

void test1()
{
    test(std::vector<int>{0, 1, 0, 1, 2});
}

void test2()
{
    test(std::vector<int>{0, 1, 0, -1, -2,  1, 2, 1});
}

void test3()
{
    test(std::vector<int>{5, 4, 3, 2, 1});
}

void test4()
{
    test(std::vector<int>{5, 5, 5, 5, 5});
}

int main ()
{
    test1();
    test2();
    test3();
    test4();

    return 0;
}