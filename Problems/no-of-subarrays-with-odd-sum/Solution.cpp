#include <vector>
#include <iostream>

using namespace std;

#define MODULO 1000000007

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int size, i, prevSum = 0, ans = 0;
        int oddPrefixSums = 0, evenPrefixSums = 1; // Includes 0;

        size = arr.size();
        for (i = 0; i < size; i++)
        {
            prevSum = (prevSum % MODULO + arr[i] % MODULO) % MODULO;
            if (prevSum & 1)
            {
                oddPrefixSums = (oddPrefixSums % MODULO + 1) % MODULO;
                ans = (ans % MODULO + evenPrefixSums % MODULO) % MODULO;
            }
            else
            {
                evenPrefixSums = (evenPrefixSums % MODULO + 1) % MODULO;
                ans = (ans % MODULO + oddPrefixSums % MODULO) % MODULO;
            }
        }

        return ans % MODULO;
    }
};