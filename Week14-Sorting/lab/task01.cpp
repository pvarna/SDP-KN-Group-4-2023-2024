#include <iostream>

const std::size_t MAX_ARRAY_CAPACITY = 100;

void readArray(int* arr, std::size_t size);

void printArray(const int* arr, std::size_t size);

void quickSort(int* arr, std::size_t size);

int main ()
{
    std::size_t size;
    int numbers[MAX_ARRAY_CAPACITY];

    std::cin >> size;
    readArray(numbers, size);

    quickSort(numbers, size);

    printArray(numbers, size);

    return 0;
}

void readArray(int* arr, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
}

void printArray(const int* arr, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void quickSort(int* arr, std::size_t size)
{
    if (!arr || size == 0)
    {
        return;
    }

    int pivot = arr[0];
    int lower[MAX_ARRAY_CAPACITY], higher[MAX_ARRAY_CAPACITY];
    std::size_t lowerSize = 0, higherSize = 0;

    for (std::size_t i = 1; i < size; ++i)
    {
        if (arr[i] <= pivot)
        {
            lower[lowerSize++] = arr[i];
        }
        else
        {
            higher[higherSize++] = arr[i];
        }
    }

    quickSort(lower, lowerSize);
    quickSort(higher, higherSize);

    std::size_t counter = 0;
    for (std::size_t i = 0; i < lowerSize; ++i)
    {
        arr[counter++] = lower[i];
    }

    arr[counter++] = pivot;

    for (std::size_t i = 0; i < higherSize; ++i)
    {
        arr[counter++] = higher[i];
    }
}