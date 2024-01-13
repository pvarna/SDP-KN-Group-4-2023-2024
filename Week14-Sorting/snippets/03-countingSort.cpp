#include <iostream>

const std::size_t MAX_ARRAY_CAPACITY = 100;

void readArray(int* arr, std::size_t size);

void printArray(const int* arr, std::size_t size);

void countingSort(int* arr, std::size_t size);

int findMax(const int* arr, std::size_t size);

int main ()
{
    std::size_t size;
    int numbers[MAX_ARRAY_CAPACITY];

    std::cin >> size;
    readArray(numbers, size);

    countingSort(numbers, size);

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

void countingSort(int* arr, std::size_t size)
{
    if (!arr || size == 0)
    {
        return;
    }

    int maxNumber = arr[findMax(arr, size)];

    int countArr[MAX_ARRAY_CAPACITY];
    for (std::size_t i = 0; i <= maxNumber; ++i)
    {
        countArr[i] = 0;
    }

    for (std::size_t i = 0; i < size; ++i)
    {
        ++countArr[arr[i]];
    }

    std::size_t counter = 0;
    for (std::size_t i = 0; i <= maxNumber; ++i)
    {
        for (std::size_t j = 0; j < countArr[i]; ++j)
        {
            arr[counter++] = i;
        }
    }
}

int findMax(const int* arr, std::size_t size)
{
    if (!arr || size == 0)
    {
        return -1;
    }

    int maxIndex = 0;

    for (std::size_t i = 1; i < size; ++i)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }

    return maxIndex;
}