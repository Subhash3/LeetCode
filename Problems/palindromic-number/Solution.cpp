#include <vector>

using namespace std;

class Solution
{
public:
    int reverseNumber(int num)
    {
        int reversed = 0, digit;

        while (num > 0)
        {
            digit = num % 10;
            reversed = reversed * 10 + digit;

            num /= 10;
        }

        return reversed;
    }

    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        int reversed = reverseNumber(x);
        return x == reversed;
    }
};