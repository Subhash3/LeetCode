#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getDigitArr(int num)
    {
        vector<int> digits;

        while (num > 0)
        {
            digits.push_back(num % 10);
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

        int length, i;
        vector<int> digits;

        digits = getDigitArr(x);
        length = digits.size();

        for (i = 0; i < length / 2; i++)
        {
            if (digits[i] != digits[length - i - 1])
            {
                return false;
            }
        }

        return true;
    }
};