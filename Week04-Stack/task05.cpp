#include <iostream>
#include <string>
#include <stack>

bool areEqual(const std::string& s, const std::string& t) 
{
    std::stack<char> s_converted, t_converted;

    for (char ch : s) 
    {
        if (ch == '#'  && !s_converted.empty()) 
        {
            s_converted.pop();
        }
        else if (ch != '#') 
        {
            s_converted.push(ch);
        }
    }

    for (char ch : t) 
    {
        if (ch == '#'  && !t_converted.empty()) 
        {
            t_converted.pop();
        }
        else if (ch != '#') 
        {
            t_converted.push(ch);
        }
    }

    while(!s_converted.empty() && !t_converted.empty()) 
    {

        if(s_converted.top() != t_converted.top()) {
            return false;
        }

        s_converted.pop();
        t_converted.pop();

    }

    return s_converted.empty() && t_converted.empty();
}

int main ()
{
    std::string s1 = "ab#c", t1 = "ad#c", s2 = "ab##", t2 = "c#d#", s3 = "a#c", t3 = "b";

    std::cout << std::boolalpha << areEqual(s1, t1) << std::endl;
    std::cout << std::boolalpha << areEqual(s2, t2) << std::endl;
    std::cout << std::boolalpha << !areEqual(s3, t3) << std::endl;

    return 0;
}