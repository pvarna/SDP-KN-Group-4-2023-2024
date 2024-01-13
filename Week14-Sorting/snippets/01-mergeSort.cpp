#include <iostream>

const std::size_t MAX_ARRAY_CAPACITY = 100;

void readArray(int* arr, std::size_t size);

void printArray(const int* arr, std::size_t size);

void mergeSort(int* arr, std::size_t size);

int* mergeSorted(int* arr1, std::size_t size1, int* arr2, std::size_t size2);

int main ()
{
    std::size_t size;
    int numbers[MAX_ARRAY_CAPACITY];

    std::cin >> size;
    readArray(numbers, size);

    mergeSort(numbers, size);

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

void mergeSort(int* arr, std::size_t size)
{
    if(!arr || size < 2)
    {
        return;
    }

    std::size_t mid = size / 2;

    int* arr1 = arr;
    std::size_t size1 = size / 2;
    int* arr2 = arr + mid;
    std::size_t size2 = (size % 2 == 0) ? size / 2 : size / 2 + 1;

    mergeSort(arr1, size1);
    mergeSort(arr2, size2);
    int* result = mergeSorted(arr1, size1, arr2, size2);

    std::size_t counter = 0;
    for (std::size_t i = 0; i < size; ++i)
    {
        arr[counter] = result[counter];
        ++counter;
    }

    delete[] result;
}

int* mergeSorted(int* arr1, std::size_t size1, int* arr2, std::size_t size2)
{
    int* result = new int[size1 + size2];
    
    std::size_t resultCounter = 0;
    std::size_t arr1Counter = 0;
    std::size_t arr2Counter = 0;

    while (arr1Counter < size1 && arr2Counter < size2)
    {
        if (arr1[arr1Counter] < arr2[arr2Counter])
        {
            result[resultCounter++] = arr1[arr1Counter++];
        }
        else
        {
            result[resultCounter++] = arr2[arr2Counter++];
        }
    }

    while (arr1Counter < size1)
    {
        result[resultCounter++] = arr1[arr1Counter++];
    }

    while (arr2Counter < size2)
    {
        result[resultCounter++] = arr2[arr2Counter++];
    }

    return result;
}