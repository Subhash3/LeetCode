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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
        {
            return true;
        }

        stack<int> nodeStack;
        int top;
        ListNode *ptr = head;

        while (ptr != NULL)
        {
            nodeStack.push(ptr->val);
            ptr = ptr->next;
        }

        ptr = head;
        while (ptr != NULL)
        {
            top = nodeStack.top();
            nodeStack.pop();

            if (top != ptr->val)
            {
                return false;
            }

            ptr = ptr->next;
        }

        return true;
    }
};