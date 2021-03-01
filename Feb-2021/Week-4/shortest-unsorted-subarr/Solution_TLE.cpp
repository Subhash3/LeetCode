#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;

        return;
    }

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

    void bubbleSort(vector<int> &arr, int *minIndex, int *maxIndex)
    {
        int len, bubbled = 0, i;
        int min = -1, max = -1;

        len = arr.size();
        while (bubbled < len)
        {
            // printVector(arr);
            for (i = 0; i < len - 1; i++)
            {
                // printf("\t");
                // fflush(NULL);
                // printVector(arr);
                if (arr[i] > arr[i + 1])
                {
                    // printf("i: %d, %d > %d\n", i, arr[i], arr[i + 1]);
                    swap(&arr[i], &arr[i + 1]);
                    if (min == -1 || i < min)
                    {
                        min = i;
                    }
                    if (max == -1 || i + 1 > max)
                    {
                        max = i + 1;
                    }
                }
            }
            bubbled += 1;
        }

        *minIndex = min;
        *maxIndex = max;

        return;
    }

    int findUnsortedSubarray(vector<int> &nums)
    {
        int minIndex, maxIndex, shortestLen;

        bubbleSort(nums, &minIndex, &maxIndex);
        // printf("min: %d, max: %d\n", minIndex, maxIndex);

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