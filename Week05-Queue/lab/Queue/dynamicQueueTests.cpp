#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "dynamicQueue.h"
#include <string>

TEST_CASE("Testing DynamicQueue") 
{
    SECTION("Enque and Front") 
    {
        DynamicQueue<std::string> queue;

        queue.enqueue("Apple");
        REQUIRE(queue.front() == "Apple");
        queue.enqueue("Banana");
        REQUIRE(queue.front() == "Apple");
    }

    SECTION("Front") 
    {
        DynamicQueue<std::string> queue;

        queue.enqueue("Apple");
        queue.enqueue("Banana");
        queue.dequeue();
        REQUIRE(queue.front() == "Banana");
        queue.dequeue();
        REQUIRE(queue.empty());
    }

    SECTION("Empty") 
    {
        DynamicQueue<std::string> queue;

        REQUIRE(queue.empty());
        queue.enqueue("Cherry");
        REQUIRE_FALSE(queue.empty());
    }

    SECTION("Dequeue on Empty Queue") 
    {
        DynamicQueue<std::string> queue;

        REQUIRE_THROWS_AS(queue.dequeue(), std::out_of_range);
    }

    SECTION("Front on Empty Queue") 
    {
        DynamicQueue<std::string> queue;

        REQUIRE_THROWS_AS(queue.front(), std::out_of_range);
    }

    SECTION("Copy Constructor") 
    {
        DynamicQueue<std::string> queue;

        queue.enqueue("Apple");
        queue.enqueue("Banana");

        DynamicQueue<std::string> copyQueue(queue);

        REQUIRE(copyQueue.front() == queue.front());
        queue.dequeue();
        REQUIRE(copyQueue.front() != queue.front());
    }

    SECTION("Assignment Operator") 
    {
        DynamicQueue<std::string> queue;

        queue.enqueue("Apple");
        queue.enqueue("Banana");

        DynamicQueue<std::string> copyQueue;
        copyQueue = queue;

        REQUIRE(copyQueue.front() == queue.front());
        queue.dequeue();
        REQUIRE(copyQueue.front() != queue.front());
    }
}

