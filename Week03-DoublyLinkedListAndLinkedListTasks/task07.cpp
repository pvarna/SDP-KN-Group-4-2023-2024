#include "task07.h"

Box* middleNode(Box* head)
{
    Box* fast = head;
    Box* slow = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}