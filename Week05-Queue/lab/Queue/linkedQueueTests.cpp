#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "linkedQueue.h"
#include <string>

TEST_CASE("Testing LinkedQueue") 
{
    SECTION("Enqueue and Front") 
    {
        LinkedQueue<int> queue;

        queue.enqueue(1);
        REQUIRE(queue.front() == 1);
        queue.enqueue(2);
        REQUIRE(queue.front() == 2);
    }

    SECTION("Dequeue") 
    {
        LinkedQueue<int> queue;

        queue.enqueue(1);
        queue.enqueue(2);
        queue.dequeue();
        REQUIRE(queue.front() == 1);
        queue.dequeue();
        REQUIRE(queue.empty());
    }

    SECTION("Empty") 
    {
        LinkedQueue<int> queue;

        REQUIRE(queue.empty());
        queue.enqueue(3);
        REQUIRE_FALSE(queue.empty());
    }

    SECTION("Dequeue on Empty queue") 
    {
        LinkedQueue<int> queue;

        REQUIRE_THROWS_AS(queue.dequeue(), std::out_of_range);
    }

    SECTION("Front on Empty queue") 
    {
        LinkedQueue<int> queue;

        REQUIRE_THROWS_AS(queue.front(), std::out_of_range);
    }

    SECTION("Copy Constructor") 
    {
        LinkedQueue<int> queue;

        queue.enqueue(1);
        queue.enqueue(2);

        LinkedQueue<int> copyQueue(queue);

        REQUIRE(copyQueue.front() == queue.front());
        queue.dequeue();
        REQUIRE(copyQueue.front() != queue.front());
    }

    SECTION("Assignment Operator") 
    {
        LinkedQueue<int> queue;

        queue.enqueue(1);
        queue.enqueue(2);

        LinkedQueue<int> copyQueue;
        copyQueue = queue;

        REQUIRE(copyQueue.front() == queue.front());
        queue.dequeue();
        REQUIRE(copyQueue.front() != queue.front());
    }
}

