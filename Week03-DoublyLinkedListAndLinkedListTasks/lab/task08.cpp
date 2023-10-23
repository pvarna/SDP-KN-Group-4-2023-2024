#include "task08.h"

int getDecimalValue(Box* head) 
{
    int result = 0;

    while (head) 
    {
        result = result * 2 + head->value;
        head = head->next;
    }

    return result;
}