#include <iostream>

bool find(const int* arr, std::size_t left, std::size_t right, int x)
{
    if (left >= right)
    {
        return false;
    }

    std::size_t mid = (left + right) / 2;

    if (arr[mid] == x)
    {
        return true;
    }
    else if (arr[mid] < x)
    {
        return find(arr, mid + 1, right, x);
    }
    
    return find(arr, left, mid, x);
}

bool find(const int* arr, std::size_t size, int x)
{
    return find(arr, 0, size, x);
}

int main ()
{
    int arr[] = {1, 2, 3, 4, 5};

    std::cout << std::boolalpha << find(arr, 5, 4) << std::endl;
    std::cout << std::boolalpha << find(arr, 5, 6) << std::endl;

    return 0;
}