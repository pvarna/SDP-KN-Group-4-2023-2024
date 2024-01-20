#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

int main()
{
    std::ifstream in("input.txt");
    if (!in)
    {
        std::cout << "Problem with opening the file" << std ::endl;
        return 1;
    }

    std::unordered_map<std::string, int> counter;

    std::string line;
    while (std::getline(in, line))
    {
        while (!line.empty())
        {
            int index = line.find(" ");
            std::string currWord = line.substr(0, index);
            line.erase(0, (index == std::string::npos) ? index : index + 1);

            counter[currWord]++;
        }
    }

    std ::cout << "Enter a word: ";

    std::string word;
    std ::cin >> word;

    std ::cout << "This word is in the file " << counter[word] << " times" << std::endl;

    in.close();

    return 0;
}