#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int allXor = 0, numXor = 0, i;

        for (i = 0; i < nums.size(); ++i)
        {
            allXor = allXor ^ i;
            numXor = numXor ^ nums[i];
        }

        allXor = allXor ^ i;
        return allXor ^ numXor;
    }
};