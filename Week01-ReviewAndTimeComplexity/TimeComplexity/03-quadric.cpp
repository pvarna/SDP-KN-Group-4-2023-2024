#include <iostream>

void printAllPairs(std::size_t n)
{
    for (std::size_t i = 1; i <= n; ++i)
    {
        for (std::size_t j = 1; j <= n; ++j)
        {
            std::cout << "<" << i << ", " << j << ">" << std::endl;
        }
    }
}

int main ()
{
    printAllPairs(4);

    return 0;
}