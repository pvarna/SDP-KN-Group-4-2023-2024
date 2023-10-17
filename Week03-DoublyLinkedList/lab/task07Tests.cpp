#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "task07.h"

TEST_CASE("Task 07")
{
    SECTION("Test case 1")
    {
        Box* list = new Box(1, new Box(2, new Box(3, new Box(4, new Box(5)))));
        REQUIRE(middleNode(list) == list->next->next);

        deallocate(list);
    }

    SECTION("Test case 2")
    {
        Box* list = new Box(1, new Box(2, new Box(3, new Box(4, new Box(5, new Box(6))))));
        REQUIRE(middleNode(list) == list->next->next->next);

        deallocate(list);
    }
}