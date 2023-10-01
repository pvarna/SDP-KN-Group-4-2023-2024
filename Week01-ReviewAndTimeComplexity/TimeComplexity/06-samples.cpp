#include <iostream>

void f1(std::size_t n)
{
    for (std::size_t i = 0; i < n; ++i)
    {
        for (std::size_t j = i; j < n; ++j)
        {
            std::cout << i << " - " << j << std::endl;
        }
    }
}

std::size_t f2(std::size_t n)
{
    std::size_t result = 0;

    for (std::size_t i = 0; i < n; ++i)
    {
        result += i;
    }

    for (std::size_t i = 0; i < n; ++i)
    {
        for (std::size_t j = 0; j < n; ++j)
        {
            result += i;
        }
    }

    result += 5;
    result *= 3;
    result -= 2;

    return result;
}

void f3(int* arr, std::size_t n) {
    for (std::size_t i = 0; i < n - 1; i++) 
    {
        for (std::size_t j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool f4(std::size_t n)
{
	while (n > 1)
	{
		if (n % 2 == 1)
        {
			return false;
        }

		n /= 2;
	}

	return true;
}

void f5(std::size_t n)
{
    for (std::size_t i = 1; i <= n; i++)
    {
        for (std::size_t j = 1; j <= n; j += i)
        {
            std::cout << "kaka Presi" << std::endl;
        }
    }
}

void removeAt1(int* arr, std::size_t& size, std::size_t index)
{
    if (index >= size)
    {
        return;
    }

    for (std::size_t i = index; i < size - 1; ++i)
    {
        arr[index] = arr[index + 1];
    }

    --size;
}

void removeAt2(int* arr, std::size_t size, std::size_t index)
{
    if (index >= size)
    {
        return;
    }

    std::swap(arr[index], arr[size - 1]);

    --size;
}

int main ()
{

}