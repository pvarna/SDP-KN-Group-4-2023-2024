#include "task02.h"

bool hasCycle(Box* head)
{
    if (head->next == nullptr)
    {
        return false;
    }
    if (head->next == head)
    {
        return true;
    }

    Box* slow = head;
    Box* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

bool contains(const std::vector<Box*> deallocatedNodes, Box* node)
{
    for (Box* current : deallocatedNodes)
    {
        if (current == node)
        {
            return true;
        }
    }

    return false;
}

void deallocateWithCycle(Box* head) 
{
    // Create a vector to keep track of nodes that have been deallocated.
    std::vector<Box*> deallocatedNodes;

    while (head) 
    {
        if (contains(deallocatedNodes, head)) 
        {
            break;
        }

        Box* temp = head;
        head = head->next;

        deallocatedNodes.push_back(temp);

        delete temp;
    }
}