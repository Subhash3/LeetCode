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

// O(n) time, O(1) Space
class Solution
{
public:
    int getListSize(ListNode *head)
    {
        ListNode *fast = NULL;
        int count = 0;
        bool even = false;

        fast = head;
        while (true)
        {
            if (fast == NULL)
            {
                // Even no. of nodes
                even = true;
                break;
            }
            if (fast->next == NULL)
            {
                // Odd no. of nodes
                even = false;
                break;
            }
            fast = fast->next->next;
            count += 1;
        }

        return even ? count * 2 : 2 * count + 1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int sizeA, sizeB, difference;
        ListNode *ptr1 = NULL, *ptr2 = NULL;

        sizeA = getListSize(headA);
        sizeB = getListSize(headB);
        difference = abs(sizeA - sizeB);
        if (sizeA >= sizeB)
        {
            ptr1 = headA;
            ptr2 = headB;
        }
        else if (sizeA < sizeB)
        {
            ptr2 = headA;
            ptr1 = headB;
        }

        while (difference > 0)
        {
            ptr1 = ptr1->next;
            difference -= 1;
        }

        while ((ptr1 != NULL) && (ptr2 != NULL) && (ptr1 != ptr2))
        {
            // printf("%d, %d\t %p %p\n", ptr1->val, ptr2->val, ptr1, ptr2);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        if (ptr1 == ptr2)
        {
            if (ptr1 == NULL)
            {
                return NULL;
            }
            return ptr1;
        }

        return NULL;
    }
};