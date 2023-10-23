#include "task09.h"
#include <iostream>

// Helper function to append a DoubleBox to the end of a DoubleBox list.
void appendDoubleBox(DoubleBox*& head, DoubleBox*& tail, int value) 
{
    DoubleBox* newBox = new DoubleBox(value);

    if (!head) 
    {
        head = tail = newBox;
    } 
    else 
    {
        tail->next = newBox;
        newBox->previous = tail;
        tail = newBox;
    }
}

void flatten(TripleBox* head, DoubleBox*& flattenedHead, DoubleBox*& flattenedTail) 
{
    if (!head) return;

    // Append the current TripleBox node to the flattened list.
    appendDoubleBox(flattenedHead, flattenedTail, head->value);

    // Recursively flatten the child list (if it exists).
    if (head->child) 
    {
        flatten(head->child, flattenedHead, flattenedTail);
    }

    // Recursively flatten the next list.
    flatten(head->next, flattenedHead, flattenedTail);
}

DoubleBox* flatten(TripleBox* head)
{
    DoubleBox* flattenedHead = nullptr;
    DoubleBox* flattenedTail = nullptr;

    flatten(head, flattenedHead, flattenedTail);

    return flattenedHead;
}