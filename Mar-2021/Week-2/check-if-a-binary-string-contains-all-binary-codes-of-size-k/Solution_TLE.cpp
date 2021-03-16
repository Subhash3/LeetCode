#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    unsigned int stringToInt(string str, int left, int right)
    {
        int i, exp, decimal;

        decimal = 0;
        exp = 1;
        for (i = right; i >= left; i--)
        {
            decimal += (str[i] - '0') * exp;
            exp *= 2;
        }

        return decimal;
    }

    bool hasAllCodes(string s, int k)
    {
        int i, decimal, numbersFound, N;
        unordered_set<unsigned int> numbers;

        numbersFound = 0;
        N = s.length();
        for (i = 0; i + k <= N; i++)
        {
            if (numbersFound == (1 << k))
            {
                return true;
            }
            decimal = stringToInt(s, i, i + k - 1);
            if (numbers.find(decimal) == numbers.end())
            {
                numbersFound += 1;
                numbers.insert(decimal);
            }
        }

        return numbersFound == (1 << k);
    }
};