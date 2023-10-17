#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "task03.h"

TEST_CASE("Task 03")
{
    SECTION("Test case 1")
    {
        Box* list1box1 = new Box(4);
        Box* list1box2 = new Box(1);

        Box* list2box1 = new Box(5);
        Box* list2box2 = new Box(6);
        Box* list2box3 = new Box(1);

        Box* commonBox1 = new Box(8);
        Box* commonBox2 = new Box(4);
        Box* commonBox3 = new Box(5);
        
        list1box1->next = list1box2;
        list1box2->next = commonBox1;

        list2box1->next = list2box2;
        list2box2->next = list2box3;
        list2box3->next = commonBox1;

        commonBox1->next = commonBox2;
        commonBox2->next = commonBox3;

        Box* list1 = list1box1;
        Box* list2 = list2box1;
        REQUIRE(getIntersectionNode(list1, list2) == commonBox1);

        // Add deallocation
    }

    SECTION("Test case 2")
    {
        Box* list1box1 = new Box(1);
        Box* list1box2 = new Box(9);
        Box* list1box3 = new Box(1);

        Box* list2box1 = new Box(3);

        Box* commonBox1 = new Box(2);
        Box* commonBox2 = new Box(4);
        
        list1box1->next = list1box2;
        list1box2->next = list1box3;
        list1box3->next = commonBox1;

        list2box1->next = commonBox1;

        commonBox1->next = commonBox2;

        Box* list1 = list1box1;
        Box* list2 = list2box1;
        REQUIRE(getIntersectionNode(list1, list2) == commonBox1);

        // Add deallocation
    }

    SECTION("Test case 3")
    {
        Box* list1 = new Box(2, new Box(4, new Box(6)));
        Box* list2 = new Box(1, new Box(5));
        REQUIRE(getIntersectionNode(list1, list2) == nullptr);

        // Add deallocation
    }
}