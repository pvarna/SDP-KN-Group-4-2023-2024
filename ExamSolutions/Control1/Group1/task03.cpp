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

int longest(box<int>* head)
{
    if (!head)
    {
        return 0;
    }

    int maxLength = 1;

    while (head)
    {
        int currentLength = 1;
        box<int>* start = head;
        while (start->next && start->data < start->next->data)
        {
            ++currentLength;
            start = start->next;
        }

        maxLength = std::max(currentLength, maxLength);
        head = head->next;
    }

    return maxLength;
}

void test(const std::vector<int>& vector)
{
    box<int>* list = fromVector(vector);

    std::cout << longest(list) << std::endl;

    deallocate(list);
}

void test1()
{
    test(std::vector<int>{1, 2, 2, 3, 4, 4});
}

void test2()
{
    test(std::vector<int>{1, 2, 3, 4, 5});
}

void test3()
{
    test(std::vector<int>{1, 1, 1, 1, 1});
}

void test4()
{
    test(std::vector<int>{5, 4, 3, 2, 1});
}

void test5()
{
    test(std::vector<int>{});
}

void test6()
{
    test(std::vector<int>{1, 3, 5, 4, 7, 9, 8, 10});
}

int main ()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}