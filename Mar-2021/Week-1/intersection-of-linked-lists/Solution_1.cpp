#include <iostream>
#include <set>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        set<ListNode *> visitedCells;
        ListNode *ptrA = headA, *ptrB = headB;

        while (true)
        {
            if (ptrA == NULL && ptrB == NULL)
            {
                return NULL;
            }
            if (ptrA != NULL)
            {
                if (visitedCells.find(ptrA) != visitedCells.end())
                {
                    return ptrA;
                }
                visitedCells.insert(ptrA);
                ptrA = ptrA->next;
            }
            if (ptrB != NULL)
            {
                if (visitedCells.find(ptrB) != visitedCells.end())
                {
                    return ptrB;
                }
                visitedCells.insert(ptrB);
                ptrB = ptrB->next;
            }
        }

        return NULL;
    }
};