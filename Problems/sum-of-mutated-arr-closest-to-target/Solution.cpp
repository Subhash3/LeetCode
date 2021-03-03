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

    int getSlope(int val, vector<int> arr, int n, int sum, int target)
    {
        int y1, y2, m;

        y1 = getAbsDiff(val, arr, n, sum, target);
        y2 = getAbsDiff(val + 1, arr, n, sum, target);
        m = (y2 - y1);

        return m;
    }

    void updateMinValue(int x, vector<int> arr, int n, int sum, int target, int *closestDifference, int *value)
    {
        int difference;

        difference = getAbsDiff(x, arr, n, sum, target);
        if (difference < *closestDifference)
        {
            *closestDifference = difference;
            *value = x;
        }
        else if (difference == *closestDifference)
        {
            *value = (*value < x) ? *value : x;
        }

        return;
    }

    int findBestValue(vector<int> &arr, int target)
    {
        int sum = 0, max = -1, i, n, mid, value = -1, closestDifference = INT32_MAX;
        int left, right, m;

        n = arr.size();
        for (i = 0; i < n; ++i)
        {
            sum += arr[i];
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }

        left = 0;
        right = max;

        updateMinValue(right, arr, n, sum, target, &closestDifference, &value);
        updateMinValue(left, arr, n, sum, target, &closestDifference, &value);
        mid = (left + right) / 2;
        while (true)
        {
            if (left > right || right - left == 1)
            {
                break;
            }
            printf("left: %d, right: %d, mid: %d, value: %d\n", left, right, mid, value);
            updateMinValue(mid, arr, n, sum, target, &closestDifference, &value);
            m = getSlope(mid, arr, n, sum, target);
            if (m > 0)
            {
                right = mid;
            }
            else if (m < 0)
            {
                left = mid;
            }
            else
            {
                // printf("Slope = 0. m: %d\n", m);
                value = mid;
                break;
            }
            mid = (left + right) / 2;
        }

        return value;
    }
};