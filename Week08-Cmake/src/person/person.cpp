#include "person.h"

Person::Person(const char* name, int age, const char* egn)
    : name(name), age(age), egn(egn) {}

const char* Person::getName() const
{
    return this->name.c_str();
}

int Person::getAge() const
{
    return this->age;
}

const char* Person::getEgn() const
{
    return this->egn.getEgn();
}