#include "task03.h"
#include <iostream>
#include <cmath>

int getSize(Box* list)
{
    int size = 0;
    while (list != nullptr)
    {
        list = list->next;
        ++size;
    }

    return size;
}

Box* getIntersectionNode(Box* head1, Box* head2)
{
    int size1 = getSize(head1);
    int size2 = getSize(head2);

    Box* minList = head1;
    Box* maxList = head2;

    if (size1 > size2)
    {
        std::swap(minList, maxList);
    }

    std::size_t difference = std::abs(size1 - size2);

    for (std::size_t i = 0; i < difference; ++i)
    {
        maxList = maxList->next;
    }

    while (minList != nullptr && maxList != nullptr)
    {
        if (minList == maxList)
        {
            return minList;
        }
        minList = minList->next;
        maxList = maxList->next;
    }

    return nullptr;
}