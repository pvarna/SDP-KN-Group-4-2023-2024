#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>

int main ()
{
    std::ifstream in("../data/AreaCodes.txt");

    if (!in)
    {
        std::cout << "Problem while openong the file!" << std::endl;
        return 1;
    }

    std::unordered_map<std::string, std::string> map1;
    std::unordered_map<std::string, std::vector<std::string>> map2;

    std::string temp;
    while (std::getline(in, temp))
    {
        std::size_t index = temp.find('-');
        std::string key = temp.substr(0, index);
        std::string value = temp.substr(index + 1);

        map1[key] = value;
        map2[value].push_back(key);
    }

    std::string number;
    std::cin >> number;

    std::cout << map1[number] << std::endl;

    std::string state;
    std::cin >> state;

    for (auto el : map2[state])
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    in.close();

    return 0;
}