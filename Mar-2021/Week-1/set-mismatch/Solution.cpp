#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int i, n;
        vector<int> freq;
        vector<int> result = {-1, -1}; // {duplicate, missing}

        n = nums.size();
        freq = vector<int>(n);

        for (i = 0; i < n; i++)
        {
            freq[nums[i] - 1] += 1;
        }
        for (i = 0; i < n; i++)
        {
            printf("%d : %d\n", i + 1, freq[i]);
        }
        printf("\n");

        for (i = 0; i < n; i++)
        {
            if (freq[i] > 1)
            {
                result[0] = i + 1;
            }

            else if (freq[i] == 0)
            {
                result[1] = i + 1;
            }
        }

        return result;
    }
};