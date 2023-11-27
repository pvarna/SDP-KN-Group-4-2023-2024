#include <iostream>
#include "fact.h"
#include "person.h"

int main()
{
    std::cout << "Hello, this is the beginning of my project!" << std::endl;
    std::cout << "Let's call out fibonacci solver: " << std::endl;

    std::cout << "fact(" << 5 << ") = " << fact(5) << std::endl;

    Person pesho("Pesho", 22, "9999999999");
    std::cout << pesho.getName() << std::endl;
    std::cout << pesho.getAge() << std::endl;
    std::cout << pesho.getEgn() << std::endl;

    return 0;
}
