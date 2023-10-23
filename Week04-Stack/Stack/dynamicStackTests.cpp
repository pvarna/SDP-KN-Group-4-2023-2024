#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "dynamicStack.h"
#include <string>

TEST_CASE("Testing DynamicStack") 
{
    SECTION("Push and Top") 
    {
        DynamicStack<std::string> stack;

        stack.push("Apple");
        REQUIRE(stack.top() == "Apple");
        stack.push("Banana");
        REQUIRE(stack.top() == "Banana");
    }

    SECTION("Pop") 
    {
        DynamicStack<std::string> stack;

        stack.push("Apple");
        stack.push("Banana");
        stack.pop();
        REQUIRE(stack.top() == "Apple");
        stack.pop();
        REQUIRE(stack.empty());
    }

    SECTION("Empty") 
    {
        DynamicStack<std::string> stack;

        REQUIRE(stack.empty());
        stack.push("Cherry");
        REQUIRE_FALSE(stack.empty());
    }

    SECTION("Pop on Empty Stack") 
    {
        DynamicStack<std::string> stack;

        REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
    }

    SECTION("Top on Empty Stack") 
    {
        DynamicStack<std::string> stack;

        REQUIRE_THROWS_AS(stack.top(), std::out_of_range);
    }

    SECTION("Copy Constructor") 
    {
        DynamicStack<std::string> stack;

        stack.push("Apple");
        stack.push("Banana");

        DynamicStack<std::string> copyStack(stack);

        REQUIRE(copyStack.top() == stack.top());
        stack.pop();
        REQUIRE(copyStack.top() != stack.top());
    }

    SECTION("Assignment Operator") 
    {
        DynamicStack<std::string> stack;

        stack.push("Apple");
        stack.push("Banana");

        DynamicStack<std::string> copyStack;
        copyStack = stack;

        REQUIRE(copyStack.top() == stack.top());
        stack.pop();
        REQUIRE(copyStack.top() != stack.top());
    }
}

