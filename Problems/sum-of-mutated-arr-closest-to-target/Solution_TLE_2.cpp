#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    int getAbsDiff(int val, vector<int> arr, int n, int sum, int target)
    {
        int anotherSum, j;
        anotherSum = sum;
        for (j = 0; j < n; ++j)
        {
            if (arr[j] > val)
            {
                anotherSum -= abs(val - arr[j]);
            }
        }
        return abs(anotherSum - target);
    }

    int findBestValue(vector<int> &arr, int target)
    {
        int sum = 0, max = -1, i, n, mid, value, closestDifference = INT32_MAX, difference;
        bool leftDone = false, rightDone = false;

        n = arr.size();
        for (i = 0; i < n; ++i)
        {
            sum += arr[i];
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }

        mid = (1 + max) / 2;
        for (i = 0;; ++i)
        {
            // printf("RightDone: %d, leftDone: %d\n", rightDone, leftDone);
            if ((rightDone && leftDone))
            {
                break;
            }
            if (mid + i > max)
            {
                rightDone = true;
            }
            if (mid - i < 0)
            {
                leftDone = true;
            }
            if (!rightDone)
            {
                // printf("Right\n");
                difference = getAbsDiff(mid + i, arr, n, sum, target);
                // printf("val: %d, diff: %d, minDiff: %d\n", mid + i, difference, closestDifference);
                if (difference < closestDifference)
                {
                    closestDifference = difference;
                    value = mid + i;
                }
                else if (difference == closestDifference)
                {
                    value = (value < mid + i) ? value : mid + i;
                }
                else
                {
                    rightDone = true;
                    // printf("Right done\n");
                }
            }
            if (!leftDone)
            {
                // printf("Left\n");
                difference = getAbsDiff(mid - i, arr, n, sum, target);
                // printf("val: %d, diff: %d, minDiff: %d\n", mid - i, difference, closestDifference);
                if (difference < closestDifference)
                {
                    closestDifference = difference;
                    value = mid - i;
                }
                else if (difference == closestDifference)
                {
                    value = (value < mid - i) ? value : mid - i;
                }
                else
                {
                    // printf("Left done\n");
                    leftDone = true;
                }
            }
        }

        return value;
    }
};