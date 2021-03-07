#include <string>

using namespace std;

class Solution
{
public:
    int minFlips(string target)
    {
        int n, i, steps = 0;
        char bit = '0';

        n = target.size();
        for (i = 0; i < n; i++)
        {
            if (bit != target[i])
            {
                bit = target[i];
                steps += 1;
            }
        }

        return steps;
    }
};