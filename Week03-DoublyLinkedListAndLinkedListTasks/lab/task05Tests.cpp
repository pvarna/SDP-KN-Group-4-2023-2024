#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "task05.h"

TEST_CASE("Task 05")
{
    SECTION("Test case 1")
    {
        Box* list = new Box(1, new Box(2, new Box(3, new Box(4, new Box(5)))));
        reverseList(list);

        Box* expected = new Box(5, new Box(4, new Box(3, new Box(2, new Box(1)))));
        REQUIRE(areEqual(list, expected));

        deallocate(list);
        deallocate(expected);
    }

    SECTION("Test case 2")
    {
        Box* list = new Box(1, new Box(2));
        reverseList(list);

        Box* expected = new Box(2, new Box(1));
        REQUIRE(areEqual(list, expected));

        deallocate(list);
        deallocate(expected);
    }
}