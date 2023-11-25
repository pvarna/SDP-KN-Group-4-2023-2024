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

int prefixWithLength(box<int>* head1, box<int>* head2)
{
    int result = 0;
    while (head1 && head2 && head1->data == head2->data)
    {
        ++result;
        head1 = head1->next;
        head2 = head2->next; 
    }

    return result;
}

box<int>* copyFromIndex(box<int>* head, int index)
{
    while (index > 0)
    {
        head = head->next;
        --index;
    }

    box<int>* result = new box<int>(head->data);
    box<int>* temp = result;

    while (head->next)
    {
        temp->next = new box<int>(head->next->data, nullptr, temp);
        temp = temp->next;
        head = head->next;
    }

    return result;
}

void complete(box<int>*& head1, box<int>* head2, int k)
{
    if (!head1 || !head2)
    {
        return;
    }

    box<int>* initialHead = head1;
    while (head1)
    {
        int prefixLength = prefixWithLength(head1, head2);
        if (prefixLength >= k)
        {
            for (int i = 0; i < prefixLength - 1; ++i)
            {
                head1 = head1->next;
            }

            box<int>* headOfNewList = copyFromIndex(head2, prefixLength);
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
        }
        else
        {
            head1 = head1->next;
        }
    }

    head1 = initialHead;
}

void test(const std::vector<int>& vector1, const std::vector<int>& vector2)
{
    box<int>* list1 = fromVector(vector1);
    box<int>* list2 = fromVector(vector2);

    complete(list1, list2, 2);
    print(list1);

    deallocate(list1);
    deallocate(list2);
}

void test1()
{
    test(std::vector<int>{1, 2, 9, 1, 1, 2}, std::vector<int>{1, 2, 3});
}

void test2()
{
    test(std::vector<int>{1, 2, 9, 1, 1, 2}, std::vector<int>{1, 2, 3, 4, 5});
}

void test3()
{
    test(std::vector<int>{1, 2, 9, 8, 7, 1, 2, 3, 5, 6, 1, 1, 2}, std::vector<int>{1, 2, 3, 4, 5});
}

int main ()
{
    test1();
    test2();
    test3();

    return 0;
}