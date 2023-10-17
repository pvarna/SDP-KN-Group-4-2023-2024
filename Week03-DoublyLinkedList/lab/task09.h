#pragma once
#include "sll_utils.h"

struct TripleBox
{
    int value;
    Box* next;
    Box* previous;
    Box* child;
};

struct DoubleBox
{
    int value;
    Box* next;
    Box* previous;
};

DoubleBox* getDecimalValue(TripleBox* head);