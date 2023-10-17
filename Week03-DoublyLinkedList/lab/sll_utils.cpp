#include "sll_utils.h"
#include <cstddef>

bool areEqual(Box* list1, Box* list2)
{
    while (list1 && list2)
    {
        if (list1->value != list2->value)
        {
            return false;
        }

        list1 = list1->next;
        list2 = list2->next;
    }

    return !list1 && !list2;
}

void deallocate(Box* head)
{
    while (head)
    {
        Box* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}