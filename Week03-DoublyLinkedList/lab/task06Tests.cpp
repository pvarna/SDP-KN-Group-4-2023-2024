#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "task06.h"

TEST_CASE("Task 06")
{
    SECTION("Test case 1")
    {
        Box* list = new Box(1, new Box(2, new Box(2, new Box(1))));
        REQUIRE(isPalindrome(list));

        deallocate(list);
    }

    SECTION("Test case 2")
    {
        Box* list = new Box(1, new Box(2));
        REQUIRE_FALSE(isPalindrome(list));

        deallocate(list);
    }
}