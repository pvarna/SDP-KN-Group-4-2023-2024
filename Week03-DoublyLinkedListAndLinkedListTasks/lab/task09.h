#pragma once
#include "sll_utils.h"

struct TripleBox
{
    int value;
    TripleBox* next;
    TripleBox* previous;
    TripleBox* child;

    TripleBox(int value, TripleBox* next = nullptr, TripleBox* previous = nullptr, TripleBox* child = nullptr)
        : value(value), next(next), previous(previous), child(child) {}
};

struct DoubleBox
{
    int value;
    DoubleBox* next;
    DoubleBox* previous;

    DoubleBox(int value, DoubleBox* next = nullptr, DoubleBox* previous = nullptr)
        : value(value), next(next), previous(previous) {}
};

DoubleBox* flatten(TripleBox* head);