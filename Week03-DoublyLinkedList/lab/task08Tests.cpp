#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "task08.h"

TEST_CASE("Task 08")
{
    SECTION("Test case 1")
    {
        Box* list = new Box(1, new Box(0, new Box(1)));
        REQUIRE(getDecimalValue(list) == 5);

        deallocate(list);
    }

    SECTION("Test case 2")
    {
        Box* list = new Box(0);
        REQUIRE(getDecimalValue(list) == 0);

        deallocate(list);
    }
}