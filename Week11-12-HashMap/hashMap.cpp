#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <cstddef>
#include <functional>
#include <unordered_map>

typedef std::pair<std::string, int> MyPair;
typedef std::vector<MyPair> Bucket;

class HashMap
{
private:
    static const std::size_t INITIAL_CAPACITY = 16;
    static const std::size_t INCREASE_STEP = 2;
    static constexpr double LOAD_FACTOR = 0.7;

    std::vector<Bucket> map;
    std::size_t size;

    std::size_t findBucket(const std::string& key) const
    {
        return std::hash<std::string>()(key) % this->map.size();
    }

    double currentLoadFactor() const
    {
        return static_cast<double>(this->size) / this->map.size();
    }

    void resize()
    {
        std::vector<Bucket> oldMap = this->map;
        this->map.clear();
        this->size = 0;
        this->map.resize(oldMap.size() * INCREASE_STEP);

        for (std::size_t i = 0; i < oldMap.size(); ++i)
        {
            for (std::size_t j = 0; j < oldMap[i].size(); ++j)
            {
                this->insert(oldMap[i][j]);
            }
        }

        // for (auto bucket : oldMap)
        // {
        //     for (auto pair : bucket)
        //     {
        //         this->insert(pair);
        //     }
        // }
    }

public:
    HashMap()
        : size(0)
    {
        map.resize(INITIAL_CAPACITY);
    }

    void insert(const MyPair& pair)
    {
        if (this->currentLoadFactor() > LOAD_FACTOR)
        {
            this->resize();
        }

        std::size_t bucketIndex = this->findBucket(pair.first);

        for (MyPair& p : this->map[bucketIndex])
        {
            if (p.first == pair.first)
            {
                p.second = pair.second;
                return;
            }
        }

        this->map[bucketIndex].push_back(pair);
        ++this->size;
    }

    void erase(const std::string& key)
    {
        std::size_t bucketIndex = this->findBucket(key);

        std::size_t bucketSize = this->map[bucketIndex].size();
        for (std::size_t i = 0; i < bucketSize; ++i)
        {
            if (this->map[bucketIndex][i].first == key)
            {
                std::swap(this->map[bucketIndex][i], this->map[bucketIndex][bucketSize - 1]);
                this->map[bucketIndex].pop_back();
                --this->size;
                return;
            }
        }
    }

    bool contains(const std::string& key)
    {
        std::size_t bucketIndex = this->findBucket(key);

        std::size_t bucketSize = this->map[bucketIndex].size();
        for (std::size_t i = 0; i < bucketSize; ++i)
        {
            if (this->map[bucketIndex][i].first == key)
            {
                return true;
            }
        }

        return false;
    }

    int& operator [] (const std::string& str)
    {
        std::size_t bucketIndex = this->findBucket(str);

        for (std::size_t i = 0; i < this->map[bucketIndex].size(); ++i)
        {
            if (this->map[bucketIndex][i].first == str)
            {
                return this->map[bucketIndex][i].second;
            }
        }

        this->map[bucketIndex].push_back(std::make_pair(str, 0));
        ++this->size;

        return this->map[bucketIndex].back().second;
    }

    class iterator 
    {
    private:
        std::vector<Bucket>::iterator currentBucket;
        Bucket::iterator currentElement;
        std::vector<Bucket>::iterator mapEnd;

        void findNextValid()
        {
            while (this->currentBucket != this->mapEnd && this->currentElement == this->currentBucket->end())
            {
                ++this->currentBucket;
                if (this->currentBucket != this->mapEnd)
                {
                    this->currentElement = this->currentBucket->begin();
                }
            }
        }

    public:
        iterator(std::vector<Bucket>::iterator currentBucket, 
                Bucket::iterator currentElement, 
                std::vector<Bucket>::iterator mapEnd)
            : currentBucket(currentBucket), currentElement(currentElement), mapEnd(mapEnd)
        {
            this->findNextValid();
        }

        bool operator == (const iterator& other)
        {
            return this->currentBucket == other.currentBucket && this->currentElement == other.currentElement;
        }

        bool operator != (const iterator& other)
        {
            return !(*this == other);
        }

        iterator& operator ++ ()
        {
            ++this->currentElement;
            this->findNextValid();

            return *this;
        }

        iterator operator ++ (int)
        {
            iterator oldIterator = *this;
            ++(*this);

            return oldIterator;
        }

        std::pair<const std::string, int>& operator * ()
        {
            return reinterpret_cast<std::pair<const std::string, int>&>(*currentElement);
        }

        std::pair<const std::string, int>* operator -> ()
        {
            return &(this->operator * ());
        }
    };

    iterator begin()
    {
        return iterator(this->map.begin(), this->map.front().begin(), this->map.end());
    }

    iterator end()
    {
        return iterator(this->map.end(), this->map.back().end(), this->map.end());
    }

    std::size_t razmer() const
    {
        return this->size;
    }
};

int main ()
{
    HashMap ani;

    ani["nai-dobroto"] = 1;
    ani["ediz_OKG"] = 3;
    ani["alex_SDP"] = 6;
    ani["maria_UP"] = 6;
    ani["edno"] = -1;
    ani["2"] = 2;
    ani["nai-loshoto"] = 0;

    std::cout << ani.razmer() << std::endl;

    for (auto neshto : ani)
    {
        std::cout << "[" << neshto.first << ", " << neshto.second << "]" << std::endl;
    }

    ani.erase("2");
    std::cout << ani.razmer() << std::endl;
    ani.erase("2");
    std::cout << ani.razmer() << std::endl;

    return 0;
}