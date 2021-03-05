#include <vector>
#include <iostream>

using namespace std;

#define MODULO 1000000007

class Solution
{
public:
    int computeRangeSum(int l, int r, vector<int> prefixSum)
    {
        int rangeSum;

        rangeSum = prefixSum[r];
        if (l != 0)
        {
            rangeSum = ((prefixSum[r] % MODULO) - (prefixSum[l - 1] % MODULO)) % MODULO;
        }

        return rangeSum;
    }

    int numOfSubarrays(vector<int> &arr)
    {
        int size, i, j, rangeSum, oddArraysCount = 0;
        vector<int> prefixSum;

        size = arr.size();
        for (i = 0; i < size; i++)
        {
            if (i == 0)
            {
                prefixSum.push_back(arr[i]);
            }
            else
            {
                prefixSum.push_back(((prefixSum[i - 1] % MODULO) + (arr[i] % MODULO) % MODULO));
            }
        }

        for (i = 0; i < size; i++)
        {
            for (j = i; j < size; j++)
            {
                rangeSum = this->computeRangeSum(i, j, prefixSum);
                // printf("Array from %d to %d has a sum: %d\n", i, j, rangeSum);
                if (rangeSum & 1)
                {
                    oddArraysCount = ((oddArraysCount % MODULO) + 1) % MODULO;
                }
            }
        }

        return oddArraysCount % MODULO;
    }
};