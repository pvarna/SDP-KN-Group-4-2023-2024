#include "catch2/catch_all.hpp"
#include "fact.h"

TEST_CASE("Test fact function with a basic input")
{
    REQUIRE(fact(5) == 120);
}

TEST_CASE("Test fact with 0 and 1")
{
    REQUIRE(fact(0) == 1);
    REQUIRE(fact(1) == 1);
}

TEST_CASE("Test fact with a negative number")
{
    REQUIRE_THROWS_AS(fact(-2), std::logic_error);
}