#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

int main ()
{
    std::ifstream in("../data/AirportCodes.txt");

    if (!in)
    {
        std::cout << "Problem while openong the file!" << std::endl;
        return 1;
    }

    std::unordered_map<std::string, std::string> map;

    std::string temp;
    while (std::getline(in, temp))
    {
        std::size_t index = temp.find('=');
        std::string key = temp.substr(0, index);
        std::string value = temp.substr(index + 1);

        map[key] = value;
    }

    std::string code;
    std::cin >> code;

    std::cout << map[code] << std::endl;

    in.close();

    return 0;
}