#include "catch2/catch_all.hpp"
#include "person.h"

TEST_CASE("Test getters")
{
    Person pesho("Pesho", 23, "0000000000");

    REQUIRE(std::string(pesho.getName()) == std::string("Pesho"));
    REQUIRE(pesho.getAge() == 23);
    REQUIRE(std::string(pesho.getEgn()) == std::string("0000000000"));
}