#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include <stack>
#include <string>

template <class T>
class QueueWithTwoStacks
{
private:
    std::stack<T> original;
    std::stack<T> reversed;

public:
    const T& front()
    {
        while (!this->original.empty())
        {
            this->reversed.push(this->original.top());
            this->original.pop();
        }

        return this->reversed.top();
    }
    void dequeue()
    {
        while (!this->original.empty())
        {
            this->reversed.push(this->original.top());
            this->original.pop();
        }

        this->reversed.pop();
    }
    void enqueue(const T& element)
    {
        while (!this->reversed.empty())
        {
            this->original.push(this->reversed.top());
            this->reversed.pop();
        }
        this->original.push(element);
    }
    bool empty() const
    {
        return this->original.empty() && this->reversed.empty();
    }
};

TEST_CASE("Testing DynamicQueue") 
{
    SECTION("Enque and Front") 
    {
        QueueWithTwoStacks<std::string> queue;

        queue.enqueue("Apple");
        REQUIRE(queue.front() == "Apple");
        queue.enqueue("Banana");
        REQUIRE(queue.front() == "Apple");
    }

    SECTION("Front") 
    {
        QueueWithTwoStacks<std::string> queue;

        queue.enqueue("Apple");
        queue.enqueue("Banana");
        queue.dequeue();
        REQUIRE(queue.front() == "Banana");
        queue.dequeue();
        REQUIRE(queue.empty());
    }

    SECTION("Empty") 
    {
        QueueWithTwoStacks<std::string> queue;

        REQUIRE(queue.empty());
        queue.enqueue("Cherry");
        REQUIRE_FALSE(queue.empty());
    }

    // SECTION("Dequeue on Empty Queue") 
    // {
    //     QueueWithTwoStacks<std::string> queue;

    //     REQUIRE_THROWS_AS(queue.dequeue(), std::out_of_range);
    // }

    // SECTION("Front on Empty Queue") 
    // {
    //     QueueWithTwoStacks<std::string> queue;

    //     REQUIRE_THROWS_AS(queue.front(), std::out_of_range);
    // }

    SECTION("Copy Constructor") 
    {
        QueueWithTwoStacks<std::string> queue;

        queue.enqueue("Apple");
        queue.enqueue("Banana");

        QueueWithTwoStacks<std::string> copyQueue(queue);

        REQUIRE(copyQueue.front() == queue.front());
        queue.dequeue();
        REQUIRE(copyQueue.front() != queue.front());
    }

    SECTION("Assignment Operator") 
    {
        QueueWithTwoStacks<std::string> queue;

        queue.enqueue("Apple");
        queue.enqueue("Banana");

        QueueWithTwoStacks<std::string> copyQueue;
        copyQueue = queue;

        REQUIRE(copyQueue.front() == queue.front());
        queue.dequeue();
        REQUIRE(copyQueue.front() != queue.front());
    }
}
