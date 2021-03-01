#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void printVector(vector<int> arr)
    {
        int i, n;

        n = arr.size();
        for (i = 0; i < n; i++)
        {
            printf("%d, ", arr[i]);
        }
        printf("\b\b\n");

        return;
    }

    int findUnsortedSubarray(vector<int> &nums)
    {
        int minIndex = -1, maxIndex = -1, shortestLen = 0, len, i;
        vector<int> numsCopy;
        bool first = true;

        len = nums.size();
        for (i = 0; i < len; i++)
        {
            numsCopy.push_back(nums[i]);
        }

        sort(nums.begin(), nums.end());
        printVector(nums);
        printVector(numsCopy);
        for (i = 0; i < len; i++)
        {
            printf("%d, %d\n", minIndex, maxIndex);
            if (nums[i] != numsCopy[i])
            {
                printf("i: %d, %d != %d\n", i, nums[i], numsCopy[i]);
                if (first)
                {
                    minIndex = i;
                    first = false;
                }
                maxIndex = i;
            }
        }

        if (minIndex == -1 || maxIndex == -1)
        {
            shortestLen = 0;
        }
        else
        {
            shortestLen = maxIndex - minIndex + 1;
        }

        return shortestLen;
    }
};