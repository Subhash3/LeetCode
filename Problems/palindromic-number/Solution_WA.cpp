#include <math.h>

class Solution
{
public:
    int getNumberOfDigits(int num)
    {
        int digits = 0;

        while (num > 0)
        {
            digits++;
            num = num / 10;
        }

        return digits;
    }

    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        int n, i, firstDigit, lastDigit, fromLast = 1, e;

        n = getNumberOfDigits(x);

        while (x >= 10)
        {
            lastDigit = x % 10;
            e = pow(10, n - fromLast);
            firstDigit = (x / e) % 10;

            if (firstDigit != lastDigit)
            {
                return false;
            }

            x = (x - firstDigit) / 10;
            n -= 1;

            x = x - (lastDigit * e / 10);
            n -= 1;
            fromLast += 1;
        }

        return true;
    }
};