#include <iostream>
#include <stack>

bool isPalindrome(const std::string& s)
{
    if (s.empty())
    {
        return true;
    }

    std::stack<char> steak;
    int size = s.size();

    for (int i = s.size() - 1; i >= size / 2; --i)
    {
        steak.push(s[i]);
    }

    for (int i = (size - 1) / 2; i >= 0; --i)
    {
        if (steak.top() != s[i])
        {
            return false;
        }
        steak.pop();
    }

    return true;
}

int main ()
{
    std::string s1 = "abcba", s2 = "abba", s3 = "aa", s4 = "a", s5 = "";

    std::cout << std::boolalpha << isPalindrome(s1) << std::endl;
    std::cout << std::boolalpha << isPalindrome(s2) << std::endl;
    std::cout << std::boolalpha << isPalindrome(s3) << std::endl;
    std::cout << std::boolalpha << isPalindrome(s4) << std::endl;
    std::cout << std::boolalpha << isPalindrome(s5) << std::endl;

    return 0;
}