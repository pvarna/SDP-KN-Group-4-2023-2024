#pragma once

#include "egn.h"

class Person
{
private:
    std::string name;
    int age;
    EGN egn;

public:
    Person(const char* name, int age, const char* egn);

    const char* getName() const;
    int getAge() const;
    const char* getEgn() const;
};