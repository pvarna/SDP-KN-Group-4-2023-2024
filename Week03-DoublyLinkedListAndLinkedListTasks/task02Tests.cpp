#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "task02.h"

TEST_CASE("Task 02")
{
    SECTION("Test case 1")
    {
        Box* box1 = new Box(3);
        Box* box2 = new Box(2);
        Box* box3 = new Box(0);
        Box* box4 = new Box(-4);
        box1->next = box2;
        box2->next = box3;
        box3->next = box4;
        box4->next = box2;

        Box* list = box1;
        REQUIRE(hasCycle(list));

        deallocateWithCycle(list);
    }

    SECTION("Test case 2")
    {
        Box* box1 = new Box(1);
        Box* box2 = new Box(2);
        box1->next = box2;
        box2->next = box1;
        
        Box* list = box1;
        REQUIRE(hasCycle(list));

        deallocateWithCycle(list);
    }

    SECTION("Test case 3")
    {
        Box* list = new Box(1);
        REQUIRE_FALSE(hasCycle(list));

        deallocateWithCycle(list);
    }

    SECTION("Test case 4")
    {
        Box* list = new Box(1, new Box(2, new Box(3, new Box(4))));
        REQUIRE_FALSE(hasCycle(list));

        deallocateWithCycle(list);
    }
}