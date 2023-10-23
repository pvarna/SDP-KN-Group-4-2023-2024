#include "task04.h"
#include <iostream>

void removeElements(Box*& head, int n)
{
    if (head == nullptr)
    {
        return;
    }

    Box* prev = head;
    while (prev != nullptr && prev->value == n)
    {
        Box* toDelete = prev;
        prev = prev->next;
        delete toDelete;
    }
    if (prev == nullptr)
    {
        head = nullptr;
        return;
    }
    Box* curr = prev->next;

    while (curr != nullptr)
    {
        if (curr->value == n)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            curr = curr->next;
            prev = prev->next;
        }
    }
}