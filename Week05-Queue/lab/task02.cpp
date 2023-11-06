#include <iostream>
#include <queue>

bool isSorted(std::queue<int> q)
{
    if (q.empty())
    {
        return true;
    }
    
    int temp = q.front();
    q.pop();

    while (!q.empty())
    {
        if (temp >= q.front())
        {
            return false;
        }

        temp = q.front();
        q.pop();
    }

    return true;
}

int main ()
{


    return 0;
}