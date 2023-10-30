#include <iostream>
#include <string>
#include <stack>

std::string removeDuplicates(const std::string& s) 
{
    std::stack<char> converter;

    for (int i = s.length() - 1; i >= 0; --i) 
    {
        if (converter.empty()) 
        {
            converter.push(s[i]);
        }
        else if( converter.top() == s[i]) 
        {
            converter.pop();
        }
        else 
        {
            converter.push(s[i]);
        }

    }

    std::string converted_string;

    while (!converter.empty()) 
    {
        converted_string.push_back(converter.top());
        converter.pop();

    }

    return converted_string;
}

int main ()
{
    std::cout << std::boolalpha << (removeDuplicates("abbaca") == "ca") << std::endl;
    std::cout << std::boolalpha << (removeDuplicates("azxxzy") == "ay") << std::endl;

    return 0;
}