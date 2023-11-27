#include "fact.h"
#include <stdexcept>

long long fact(int n)
{
    if (n < 0)
    {
        throw std::logic_error("n should be a non-negative number!");
    }
    
    if (n <= 1)
    {
        return 1;
    }

    return n * fact(n - 1);
}