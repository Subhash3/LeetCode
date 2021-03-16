#include <string>

using namespace std;

class Solution
{
public:
    bool checkPalindrome(string s, int left, int right)
    {
        int length = left + right + 1;
        int i;

        if (length == 1)
        {
            return true;
        }

        for (i = left; i < length / 2; i++)
        {
            if (s[i] != s[length - i - 1])
            {
                return false;
            }
        }

        return true;
    }

    int removePalindromeSub(string s)
    {
        if (s == "")
        {
            return 0;
        }

        int N;

        N = s.length();
        if (this->checkPalindrome(s, 0, N - 1))
        {
            return 1;
        }
        return 2;
    }
};