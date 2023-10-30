#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "linkedStack.h"
#include <string>

TEST_CASE("Testing LinkedStack") 
{
    SECTION("Push and Top") 
    {
        LinkedStack<int> stack;

        stack.push(1);
        REQUIRE(stack.top() == 1);
        stack.push(2);
        REQUIRE(stack.top() == 2);
    }

    SECTION("Pop") 
    {
        LinkedStack<int> stack;

        stack.push(1);
        stack.push(2);
        stack.pop();
        REQUIRE(stack.top() == 1);
        stack.pop();
        REQUIRE(stack.empty());
    }

    SECTION("Empty") 
    {
        LinkedStack<int> stack;

        REQUIRE(stack.empty());
        stack.push(3);
        REQUIRE_FALSE(stack.empty());
    }

    SECTION("Pop on Empty Stack") 
    {
        LinkedStack<int> stack;

        REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
    }

    SECTION("Top on Empty Stack") 
    {
        LinkedStack<int> stack;

        REQUIRE_THROWS_AS(stack.top(), std::out_of_range);
    }

    SECTION("Copy Constructor") 
    {
        LinkedStack<int> stack;

        stack.push(1);
        stack.push(2);

        LinkedStack<int> copyStack(stack);

        REQUIRE(copyStack.top() == stack.top());
        stack.pop();
        REQUIRE(copyStack.top() != stack.top());
    }

    SECTION("Assignment Operator") 
    {
        LinkedStack<int> stack;

        stack.push(1);
        stack.push(2);

        LinkedStack<int> copyStack;
        copyStack = stack;

        REQUIRE(copyStack.top() == stack.top());
        stack.pop();
        REQUIRE(copyStack.top() != stack.top());
    }
}

