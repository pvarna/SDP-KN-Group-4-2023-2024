#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "doublyLinkedList.h"
#include <vector>

TEST_CASE("List create/destroy") 
{
	SECTION("Default constructor") 
    {
        DoublyLinkedList<int> instance;
        REQUIRE(instance.size() == 0);
	}

	SECTION("Copy constructor / operator=") 
    {
        DoublyLinkedList<int> instance;
        DoublyLinkedList<int> copy(instance);
        DoublyLinkedList<int> assign;
        assign = instance;
        REQUIRE(instance.size() == 0);
        REQUIRE(copy.size() == 0);
        REQUIRE(assign.size() == 0);
	}

	SECTION("Constructor with count") 
    {
		DoublyLinkedList<int> instance(15);
		REQUIRE(instance.size() == 15);
	}

	SECTION("Constructor with count and value") 
    {
		DoublyLinkedList<int> instance(17, 5);
        REQUIRE(instance.size() == 17);

        REQUIRE(instance.front() == 5);
        REQUIRE(instance.back() == 5);
	}

	SECTION("Copy and assign non-empty list") 
    {
        DoublyLinkedList<int> instance(10);
        REQUIRE(instance.size() == 10);

        DoublyLinkedList<int> copy(instance);
        REQUIRE(copy.size() == 10);

        DoublyLinkedList<int> assign;
        REQUIRE(assign.size() == 0);
		assign = copy;
		REQUIRE(assign.size() == copy.size());
	}

	SECTION("Clear after constructor with count") 
    {
		DoublyLinkedList<int> instance(31);
        REQUIRE(instance.size() == 31);

        instance.clear();
        REQUIRE(instance.size() == 0);
    }
}

TEST_CASE("List back/front modify") 
{
	SECTION("Push_back and pop_back all") 
    {
		DoublyLinkedList<int> instance;
        for (int c = 0; c < 21; c++) 
        {
            instance.push_back(0);
        }
        REQUIRE(instance.size() == 21);

        for (int c = 0; c < 21; c++) 
        {
            instance.pop_back();
        }
        REQUIRE(instance.size() == 0);
	}

	SECTION("Repeated push_back/pop_back") 
    {
		DoublyLinkedList<int> instance;
        for (int c = 0; c < 100; c++) 
        {
            instance.push_back(0);
            instance.pop_back();
        }
        REQUIRE(instance.size() == 0);
	}

	SECTION("Repeated push_back/back") 
    {
		DoublyLinkedList<int> instance;
        int value = 0;
        for (int c = 0; c < 100; c++) 
        {
            instance.push_back(value);
            REQUIRE(instance.back() == value);
            ++value;
        }
        REQUIRE(instance.size() == 100);
	}

	SECTION("Push_front and pop_front all") 
    {
		DoublyLinkedList<int> instance;
        for (int c = 0; c < 21; c++) 
        {
            instance.push_front(0);
        }
        REQUIRE(instance.size() == 21);

        for (int c = 0; c < 21; c++) 
        {
            instance.pop_front();
        }
        REQUIRE(instance.size() == 0);
	}

	SECTION("Repeated push_front/pop_front") 
    {
		DoublyLinkedList<int> instance;
        for (int c = 0; c < 100; c++) 
        {
            instance.push_front(0);
            instance.pop_front();
        }
        REQUIRE(instance.size() == 0);
	}

	SECTION("Repeated push_front/front") 
    {
		DoublyLinkedList<int> instance;
        int value = 0;
        for (int c = 0; c < 100; c++) 
        {
            instance.push_front(value);
            REQUIRE(instance.front() == value);
            ++value;
        }
        REQUIRE(instance.size() == 100);
	}
}

TEST_CASE("List iterator access") 
{
	SECTION("Iterator creation and operators") 
    {
		DoublyLinkedList<int> instance(3, 0);
        typename DoublyLinkedList<int>::Iterator it = instance.begin();
        REQUIRE(*it == 0);
        REQUIRE(it == instance.begin());
        typename DoublyLinkedList<int>::Iterator end = instance.end();
        REQUIRE(end == instance.end());
        REQUIRE(++(--end) == instance.end());
	}

	SECTION("Iterator value modification") 
    {
		DoublyLinkedList<int> instance(3);
        int value = 0;
        
        for (typename DoublyLinkedList<int>::Iterator it = instance.begin(); it != instance.end(); ++it) 
        {
            *it = ++value;
        }

        value = 0;
        for (typename DoublyLinkedList<int>::Iterator it = instance.begin(); it != instance.end(); ++it) 
        {
            REQUIRE(*it == ++value);
        }
	}
	
	SECTION("Iterator insert/erase") 
    {
		DoublyLinkedList<int> instance(1, 0);
        int value = 0;

        instance.insert(instance.begin(), ++value);
        REQUIRE(instance.front() == value);

        instance.insert(instance.end(), ++value);
        REQUIRE(instance.back() == value);

        DoublyLinkedList<int> copy = instance;

        instance.erase(instance.begin());
        REQUIRE(instance.front() == 0);

        instance.erase(--instance.end());
        REQUIRE(instance.back() == 0);
        REQUIRE(instance.size() == 1);

        copy.erase(copy.begin(), copy.end());
        REQUIRE(copy.empty());
    }
}

TEST_CASE("List element operations") 
{
	SECTION("Splice after") 
    {
		DoublyLinkedList<int> source;
        DoublyLinkedList<int> destination;
        std::vector<int*> sourceItems;
        int value = 0;
        const int itemCount = 2;
        
        for (int c = 0; c < itemCount; c++) 
        {
            destination.push_back(value);
            ++value;
        }

        for (int c = 0; c < itemCount; c++) 
        {
            source.push_back(value);
            sourceItems.push_back(&source.back());
            ++value;
        }

        typename DoublyLinkedList<int>::Iterator begin1 = destination.begin();
        destination.splice_after(begin1, source);

        REQUIRE(destination.size() == 4);
        REQUIRE(source.size() == 0);

        typename DoublyLinkedList<int>::Iterator it = destination.begin();
        REQUIRE(&*(++it) == sourceItems[0]);
        REQUIRE(&*(++it) == sourceItems[1]);
	}

	SECTION("Merge") 
    {
		DoublyLinkedList<int> destination;
        DoublyLinkedList<int> source;
        std::vector<int*> sourceItems;
        int value = 0;
        const int itemCount = 10;

        for (int c = 0; c < itemCount; c++) 
        {
            if (c % 2 == 0) 
            {
                destination.push_back(value);
            }
            else 
            {
                source.push_back(value);
                sourceItems.push_back(&source.back());
            }
            ++value;
        }

        destination.merge(source);

        REQUIRE(destination.size() == 10);
        REQUIRE(source.size() == 0);

        typename DoublyLinkedList<int>::Iterator current = destination.begin();
        typename DoublyLinkedList<int>::Iterator next = ++destination.begin();
        for (; next != destination.end(); ++current, ++next) 
        {
            REQUIRE(*current <= *next);
        }

        current = destination.begin();
        int sourceItemIx = 0;
        for (int i = 0; current != destination.end(); ++i, ++current) 
        {
            if (i % 2 == 1) 
            {
                REQUIRE(&(*current) == sourceItems[sourceItemIx]);
                sourceItemIx++;
            }
        }
	}

	SECTION("Unique") 
    {
		DoublyLinkedList<int> instance;
        std::vector<int*> itemsLeft;
        int value = 0;
        const int itemCount = 10;

        for (int c = 0; c < itemCount; c++) 
        {
            instance.push_back(value);

            if (c % 2 == 0) 
            {
                itemsLeft.push_back(&instance.back());
            }
            else 
            {
                ++value;
            }
        }
        
        instance.unique();
        REQUIRE(instance.size() == 5);

        int itemsLeftIx = 0;
        for (typename DoublyLinkedList<int>::Iterator it = instance.begin(); it != instance.end(); ++it) 
        {
            REQUIRE(&(*it) == itemsLeft[itemsLeftIx]);
            ++itemsLeftIx;
        }
	}
}
