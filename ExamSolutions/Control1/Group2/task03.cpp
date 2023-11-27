#include <iostream>
#include <vector>
#include <functional>

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

bool sublist(box<int>* head1, box<int>* head2)
{
    if (!head1)
    {
        return true;
    }

    if (!head2)
    {
        return false;
    }

    box<int>* initialHead1 = head1;
    while (head2)
    {
        head1 = initialHead1;
        box<int>* start = head2;
        
        while (head1 && start && head1->data == start->data)
        {
            head1 = head1->next;
            start = start->next;
        }

        bool isSublist = (head1 == nullptr);
        if (isSublist)
        {
            return true;
        }

        head2 = head2->next;
    }

    return false;
}

void test(const std::vector<int>& vector1, const std::vector<int>& vector2)
{
    box<int>* list1 = fromVector(vector1);
    box<int>* list2 = fromVector(vector2);

    std::cout << std::boolalpha << sublist(list1, list2) << std::endl;

    deallocate(list1);
    deallocate(list2);
}

void test1()
{
    test(std::vector<int>{1, 2, 3}, std::vector<int>{0, 1, 2, 3});
}

void test2()
{
    test(std::vector<int>{1, 2, 3}, std::vector<int>{1, 2, 2, 3});
}

void test3()
{
    test(std::vector<int>{1, 2, 3}, std::vector<int>{1, 2, 3});
}

void test4()
{
    test(std::vector<int>{}, std::vector<int>{1, 2, 2, 3});
}

void test5()
{
    test(std::vector<int>{1, 2, 3}, std::vector<int>{});
}

void test6()
{
    test(std::vector<int>{1, 2, 3}, std::vector<int>{1, 2, 2, 3, 1, 3, 1, 2, 1, 2, 3, 3, 3});
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