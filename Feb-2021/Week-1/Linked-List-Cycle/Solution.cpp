/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slowPtr, *fastPtr;
        bool foundCycle = true;

        slowPtr = head;
        fastPtr = head;
        while (true)
        {
            if (slowPtr == NULL || fastPtr == NULL)
            {
                foundCycle = false;
                break;
            }
            slowPtr = slowPtr->next;
            if (fastPtr->next == NULL)
            {
                foundCycle = false;
                break;
            }
            fastPtr = fastPtr->next->next;

            if (slowPtr == fastPtr)
            {
                break;
            }
        }

        return foundCycle;
    }
};