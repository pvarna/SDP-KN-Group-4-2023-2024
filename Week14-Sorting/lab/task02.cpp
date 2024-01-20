#include <iostream>

struct box
{
    int value;
    box* next;

    box(int value, box* next = nullptr)
        : value(value), next(next) {}
};

void mergeSort(box*& head);

box* getMiddle(box* head);

void print(box* head);

box* mergeSorted(box* first, box* second);

int main ()
{
    box* head = new box(7, new box(2, new box(1, new box(14, new box(52)))));

    // std::cout << getMiddle(head)->value << std::endl;
    mergeSort(head);
    print(head);

    return 0;
}

void mergeSort(box*& head)
{
    if (!head || !head->next)
    {
        return;
    }

    box* second = getMiddle(head);

    box* first = head;
    box* buffer = first;
    while (buffer->next != second)
    {
        buffer = buffer->next;
    }
    buffer->next = nullptr;

    mergeSort(first);
    mergeSort(second);

    // std::cout << "First: ";
    // print(first);
    // std::cout << "Second: ";
    // print(second);

    head = mergeSorted(first, second);
}

box* getMiddle(box* head)
{
    box* slow = head;
    box* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void print(box* head)
{
    while (head)
    {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

box* mergeSorted(box* first, box* second)
{
    if (!first)
    {
        return second;
    }

    if (!second)
    {
        return first;
    }

    std::cout << "RECEIVED: \n";
    print(first);
    print(second);

    box* result;
    if (first->value < second->value)
    {
        result = first;
        first = first->next;
    }
    else
    {
        result = second;
        second = second->next;
    }
    box* buffer = result;

    while (first && second)
    {
        if (first->value < second->value)
        {
            buffer->next = first;
            first = first->next;
        }
        else
        {
            buffer->next = second;
            second = second->next;
        }
        buffer = buffer->next;
    }

    while (first)
    {
        buffer->next = first;
        first = first->next;
        buffer = buffer->next;
    }

    while (second)
    {
        buffer->next = second;
        second = second->next;
        buffer = buffer->next;
    }

    std::cout << "RESULT: \n";
    print(result);

    return result;
}