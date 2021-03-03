#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findBestValue(vector<int> &arr, int target)
    {
        int sum = 0, max = -1, i, n, j, val, value, anotherSum, closestDifference = INT32_MAX;
        unordered_map<int, int> valueToDifferenceMap;

        n = arr.size();
        for (i = 0; i < n; ++i)
        {
            sum += arr[i];
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }

        for (val = 1; val <= max; ++val)
        {
            anotherSum = sum;
            for (j = 0; j < n; ++j)
            {
                if (arr[j] > val)
                {
                    anotherSum -= abs(val - arr[j]);
                }
            }
            valueToDifferenceMap[val] = abs(anotherSum - target);
        }

        for (auto it : valueToDifferenceMap)
        {
            printf("{%d: %d}\n", it.first, it.second);
            if (it.second < closestDifference)
            {
                closestDifference = it.second;
                value = it.first;
            }
            else if (it.second == closestDifference)
            {
                value = (value < it.first) ? value : it.first;
            }
        }

        return value;
    }
};