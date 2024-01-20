#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

struct ProductInfo
{
    int percent;
    std::string nameCode;
};

int main()
{
    int codes;
    std::cin >> codes;

    std::unordered_map<std::string, std::vector<ProductInfo>> map;

    for (int i = 0; i < codes; i++)
    {
        int percent;
        std::string nameCode;
        int cnt;

        std ::cin >> percent >> nameCode >> cnt;

        for (int j = 0; j < cnt; j++)
        {
            std::string product;
            std::cin >> product;
            map[product].push_back({percent, nameCode});
        }
    }

    int wants;
    std::cin >> wants;
    for (int i = 0; i < wants; i++)
    {
        std::string wantedProduct;
        std::cin >> wantedProduct;

        if (!map[wantedProduct].empty())
        {
            for (auto el : map[wantedProduct])
            {
                std::cout << el.percent << "% " << el.nameCode << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "no-promo" << std ::endl;
        }
    }

    return 0;
}