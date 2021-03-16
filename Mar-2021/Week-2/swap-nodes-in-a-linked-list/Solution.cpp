#include <iostream>

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
    ListNode *swapNodes(ListNode *head, int k)
    {
        int n, i, temp;
        ListNode *left = NULL, *right = NULL;

        n = getListSize(head);
        left = head;
        right = head;
        for (i = 0; i < n; i++)
        {
            if (i < k - 1)
            {
                left = left->next;
            }
            if (i < n - k)
            {
                right = right->next;
            }
        }

        temp = left->val;
        left->val = right->val;
        right->val = temp;

        return head;
    }
};