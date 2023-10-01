#include <iostream>

const int* getMiddleElement(const int* arr, std::size_t size)
{
    if (size == 0)
    {
        return nullptr;
    }

    return arr + size / 2;
}

int main ()
{
    int arr[] = {1, 2, 3, 4, 5};

    std::cout << *getMiddleElement(arr, 5) << std::endl;

    return 0;
}