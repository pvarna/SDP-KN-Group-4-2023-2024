#include <iostream>
#include <unordered_set>

struct box
{
    int value;
    box* next;

    box(int value, box* next = nullptr)
        : value(value), next(next) {}
};

bool hasCycle(box* head)
{
    std::unordered_set<box*> visited;

    while (head)
    {
        if (visited.find(head) != visited.end())
        {
            return true;
        }

        visited.insert(head);
        head = head->next;
    }

    return false;
}

int main ()
{
    box* box1 = new box(1);
    box* box2 = new box(2);
    box* box3 = new box(3);
    box* box4 = new box(4);

    box1->next = box2;
    box2->next = box3;
    box3->next = box4;
    box4->next = box2;

    return 0;
}