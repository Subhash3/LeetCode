#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0, i, n = nums.size(), required = 0;

        for (i = 0; i < n; ++i)
        {
            sum += nums[i];
        }

        required = n * (n + 1) / 2;
        return required - sum;
    }
};