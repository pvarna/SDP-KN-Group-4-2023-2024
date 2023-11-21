#include "catch2/catch_all.hpp"
#include "fact.h"

TEST_CASE("Test fact function")
{
    REQUIRE(fact(5) == 120);
}