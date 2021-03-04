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

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length, i;
        ListNode *ptr = head, *prev = head;

        length = this->getListSize(head);

        // Remove first node
        if (length == n)
        {
            head = head->next;
        }

        // printf("Length: %d\n", length);
        for (i = 0; i < length - n; ++i)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = ptr->next;
        // free(ptr);

        return head;
    }
};