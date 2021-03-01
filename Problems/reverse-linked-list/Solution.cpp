#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current, *next = NULL, *ptr = head;

        while (ptr != NULL)
        {
            current = new ListNode(ptr->val);
            current->next = next;
            next = current;
            ptr = ptr->next;
        }

        return current;
    }
};