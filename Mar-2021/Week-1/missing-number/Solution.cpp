#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0, n = nums.size(), required = 0;

        for (auto num : nums)
        {
            sum += num;
        }

        required = n * (n + 1) / 2;
        return required - sum;
    }
};