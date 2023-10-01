#include <iostream>

bool find(const int* arr, std::size_t size, int x)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }

    return false;
}

int main ()
{
    int arr[] = {1, 2, 3, 4, 5};

    std::cout << std::boolalpha << find(arr, 5, 4) << std::endl;
    std::cout << std::boolalpha << find(arr, 5, 6) << std::endl;

    return 0;
}