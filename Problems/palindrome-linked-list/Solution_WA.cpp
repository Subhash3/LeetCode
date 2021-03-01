#include <vector>

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
    long long int reverseNumber(int num)
    {
        long long int reversed = 0;
        int digit;

        while (num > 0)
        {
            digit = num % 10;
            reversed = reversed * 10 + digit;

            num /= 10;
        }

        return reversed;
    }

    long long int parseList(ListNode *head)
    {
        long long int num = 0;
        ListNode *ptr = head;

        while (ptr != NULL)
        {
            num = num * 10 + ptr->val;
            ptr = ptr->next;
        }

        return num;
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
        {
            return true;
        }

        long long int reversed, x;
        x = parseList(head);
        if (x < 0)
        {
            return false;
        }
        reversed = reverseNumber(x);
        return x == reversed;
    }
};