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

void split(box<int>*& head1, box<int>*& head2, std::function<bool(int)> p)
{
    box<int>* headOfNewList = nullptr;
    box<int>* tailOfNewList = nullptr;

    box<int>* initialHead1 = head1;

    while (head1)
    {
        if (p(head1->data))
        {
            box<int>* toDelete = head1;

            if (!head1->prev && !head1->next)
            {
                head1 = nullptr;
            }
            else if (head1->prev && head1->next)
            {
                head1->prev->next = head1->next;
                head1->next->prev = head1->prev;
                head1 = head1->next;
            }
            else if (!head1->prev && head1->next)
            {
                head1->next->prev = nullptr;
                head1 = head1->next;
                initialHead1 = head1;
            }
            else // head1->prev && !head1->next
            {
                head1->prev->next = nullptr;
                head1 = nullptr;
            }

            box<int>* toAdd = new box<int>(toDelete->data);
            if (!headOfNewList)
            {
                headOfNewList = toAdd;
                tailOfNewList = toAdd;
            }
            else
            {
                tailOfNewList->next = toAdd;
                toAdd->prev = tailOfNewList;
                tailOfNewList = toAdd;
            }

            delete toDelete;
        }
        else
        {
            head1 = head1->next;
        }
    }

    head1 = initialHead1;

    if (!head2)
    {
        head2 = headOfNewList;
    }
    else
    {
        box<int>* tailOfHead2 = head2;
        while (tailOfHead2->next)
        {
            tailOfHead2 = tailOfHead2->next;
        }

        tailOfHead2->next = headOfNewList;
        headOfNewList->prev = tailOfHead2;
        
    }
}

void test(const std::vector<int>& vector1, const std::vector<int>& vector2)
{
    box<int>* list1 = fromVector(vector1);
    box<int>* list2 = fromVector(vector2);

    split(list1, list2, [](int x){ return x % 2 == 0; });
    print(list1);
    print(list2);

    deallocate(list1);
    deallocate(list2);
}

void test1()
{
    test(std::vector<int>{0, 1, 2, 3, 4, 5, 6}, std::vector<int>{10, 100, 1000});
}

void test2()
{
    test(std::vector<int>{0, 1, 2, 3, 4, 5, 6}, std::vector<int>{});
}

int main ()
{
    test1();
    test2();

    return 0;
}