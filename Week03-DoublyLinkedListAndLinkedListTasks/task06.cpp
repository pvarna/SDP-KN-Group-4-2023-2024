#include "task06.h"

bool isPalindrome(Box* head)
{
    if (!head || !head->next) 
    {
        return true;
    }

    Box* slow = head;
    Box* fast = head;

    while (!fast && !fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast && !fast->next)
    {
        slow = slow->next;
    }

    Box* prev = nullptr;
    Box* temp = nullptr;

    while (slow && slow->next)
    {
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    if (slow)
    {
        slow->next = prev;
    }
    fast = head;
    while (slow && fast)
    {
        if (slow->value != fast->value)
        {
            return false;
        }

        slow = slow->next;
        fast = fast->next;
    }

    return true;
}