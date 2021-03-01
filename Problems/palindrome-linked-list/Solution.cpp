#include <stack>

using namespace std;

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
    ListNode *reverseListCopy(ListNode *head)
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

    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
        {
            return true;
        }

        ListNode *reversedHead, *ptr1, *ptr2;
        int a, b;

        reversedHead = reverseListCopy(head);
        ptr1 = head;
        ptr2 = reversedHead;

        while (ptr1 != NULL)
        {
            a = ptr1->val;
            b = ptr2->val;
            if (a != b)
            {
                return false;
            }

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return true;
    }
};