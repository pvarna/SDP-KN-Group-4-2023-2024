#include <iostream>
#include <string>
#include <stack>
#include <cctype>

bool isNumber(const std::string& str)
{
    return str[0] == '-' || isdigit(str[0]);
}

int getNumberFromString(const std::string& str)
{
    std::size_t startIndex = (str[0] == '-');

    int number = 0;
    for (std::size_t i = startIndex; i < str.length(); ++i)
    {
        number = (number * 10) + (str[i] - '0');
    }

    return startIndex ? -number : number;
}

int getResult(const std::vector<std::string>& operations)
{
    std::stack<int> stack;

    for (std::vector<std::string>::const_iterator it = operations.begin(); it != operations.end(); ++it)
    {
        std::string currentOperation = *it;

        if (isNumber(currentOperation))
        {
            stack.push(getNumberFromString(*it));
        }
        else if (currentOperation == "+")
        {
            int firstNumber = stack.top();
            stack.pop();
            int secondNumber = stack.top();
            stack.push(firstNumber);
            stack.push(firstNumber + secondNumber);
        }
        else if (currentOperation == "D")
        {
            stack.push(stack.top() * 2);
        }
        else if (currentOperation == "C")
        {
            stack.pop();
        }
    }

    int result = 0;

    while (!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }

    return result;
}

int main ()
{
    std::vector<std::string> operations1;
    operations1.push_back("5");
    operations1.push_back("2");
    operations1.push_back("C");
    operations1.push_back("D");
    operations1.push_back("+");

    std::cout << std::boolalpha << (getResult(operations1) == 30) << std::endl;

    std::vector<std::string> operations2;
    operations2.push_back("5");
    operations2.push_back("-2");
    operations2.push_back("4");
    operations2.push_back("C");
    operations2.push_back("D");
    operations2.push_back("9");
    operations2.push_back("+");
    operations2.push_back("+");

    std::cout << std::boolalpha << (getResult(operations2) == 27) << std::endl;

    return 0;
}