#include <iostream>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main ()
{
    std::cout << fibonacci(4) << std::endl;

    return 0;
}