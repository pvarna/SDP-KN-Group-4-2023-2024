#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "task04.h"

TEST_CASE("Task 04")
{
    SECTION("Test case 1")
    {
        Box* list = new Box(1, new Box(2, new Box(6, new Box(3, new Box(4, new Box(5, new Box(6)))))));
        removeElements(list, 6);

        Box* expected = new Box(1, new Box(2, new Box(3, new Box(4, new Box(5)))));
        REQUIRE(areEqual(list, expected));

        deallocate(list);
        deallocate(expected);
    }

    SECTION("Test case 2")
    {
        Box* list = new Box(7, new Box(7, new Box(7, new Box(7))));
        removeElements(list, 7);

        REQUIRE(list == nullptr);
        deallocate(list);
    }
}