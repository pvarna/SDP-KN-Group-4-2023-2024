#include "task05.h"

void reverseList(Box*& head)
{
    Box* temp = nullptr;
    Box* prev = nullptr;
    Box* current = head;

    while (current != nullptr)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    head = prev;
}