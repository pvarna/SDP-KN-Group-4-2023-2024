#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "task01.h"

TEST_CASE("Task 01")
{
    SECTION("Test case 1")
    {
        Box* list = new Box(1, new Box(1, new Box(2)));
        removeDuplicatesInSorted(list);

        Box* expected = new Box(1, new Box(2));
        REQUIRE(areEqual(list, expected));

        deallocate(list);
        deallocate(expected);
    }

    SECTION("Test case 2")
    {
        Box* list = new Box(1, new Box(1, new Box(2, new Box(3, new Box(3)))));
        removeDuplicatesInSorted(list);

        Box* expected = new Box(1, new Box(2, new Box(3)));
        REQUIRE(areEqual(list, expected));

        deallocate(list);
        deallocate(expected);
    }
}