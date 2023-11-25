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

box<int>* fromVector(const std::vector<int>& vector, bool makeCyclic)
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

    if (makeCyclic)
    {
        box<int>* tail = temp;

        tail->next = head;
        head->prev = tail;
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

void deallocateCyclic(box<int>* head, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        box<int>* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

box<int>* copy(box<int>*& head, std::size_t size)
{
    if (size == 0)
    {
        return nullptr;
    }

    box<int>* result = new box<int>(head->data);
    box<int>* temp = result;

    head = head->next;
    for (std::size_t i = 1; i < size; ++i)
    {
        temp->next = new box<int>(head->data, nullptr, temp);

        temp = temp->next;
        head = head->next;
    }

    return result;
}

void pick(box<int>*& head1, box<int>* head2)
{
    if (!head1 || !head2)
    {
        return;
    }

    std::size_t index = 1;
    box<int>* initialHead = head1;

    while (head1)
    {
        box<int>* headOfNewList = copy(head2, index);
        box<int>* tailOfNewList = headOfNewList;

        while (tailOfNewList->next)
        {
            tailOfNewList = tailOfNewList->next;
        }

        if (head1->next)
        {
            tailOfNewList->next = head1->next;
            head1->next->prev = tailOfNewList;
        }

        head1->next = headOfNewList;
        headOfNewList->prev = head1;

        head1 = tailOfNewList->next;

        ++index;
    }

    head1 = initialHead;
}

void test(const std::vector<int>& vector1, const std::vector<int>& vector2)
{
    box<int>* list1 = fromVector(vector1, false);
    box<int>* list2 = fromVector(vector2, true);

    pick(list1, list2);

    print(list1);

    deallocate(list1);
    deallocateCyclic(list2, vector2.size());
}

void test1()
{
    test(std::vector<int>{1, 2, 3}, std::vector<int>{4, 5, 6});
}

void test2()
{
    test(std::vector<int>{1, 2, 3}, std::vector<int>{5});
}

int main ()
{
    test1();
    test2();

    return 0;
}