#pragma once

struct Box
{
    int value;
    Box* next;

    Box(int value, Box* next = nullptr)
        : value(value), next(next) {}
};

bool areEqual(Box* list1, Box* list2);

void deallocate(Box* head);