#include <iostream>

const std::size_t MAX_SIZE = 128;

void reverse1(int* arr, std::size_t size)
{
    int temp[MAX_SIZE];

    for (std::size_t i = 0; i < size; ++i)
    {
        temp[i] = arr[i];
    }

    for (std::size_t i = 0; i < size; ++i)
    {
        arr[i]  = temp[size - 1 - i];
    }
}

void reverse2(int* arr, std::size_t size)
{
    for (std::size_t i = 0; i < size / 2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void print(const int* arr, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++ i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main ()
{
    int arr[] = {1, 2, 3, 4, 5};

    reverse1(arr, 5);
    print(arr, 5);

    reverse2(arr, 5);
    print(arr, 5);

    return 0;
}