#include "task01.h"

void removeDuplicatesInSorted(Box* head)
{
    Box* temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        if (temp->value == temp->next->value)
        {
            Box* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        else
        {
            temp = temp->next;
        }
    }
}