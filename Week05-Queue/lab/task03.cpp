#include <iostream>
#include <string>
#include <queue>

int firstUniqChar(const std::string& s) 
{
    const int ALPHABET_COUNT = 26; // Assuming lowercase English letters
    int count[ALPHABET_COUNT] = {0};
    std::queue<char> charQueue;

    for (char c : s) 
    {
        count[c - 'a']++;
        charQueue.push(c);
    }

    // Iterate through the queue to find the first character with a count of 1
    int index = 0;
    while (!charQueue.empty()) 
    {
        char c = charQueue.front();
        if (count[c - 'a'] == 1) 
        {
            return index;
        }
        charQueue.pop();
        index++;
    }

    return -1;
}

int main() 
{
    std::string s1 = "abracadab";
    std::string s2 = "aabb";

    std::cout << firstUniqChar(s1) << std::endl;
    std::cout << firstUniqChar(s2) << std::endl;

    return 0;
}
