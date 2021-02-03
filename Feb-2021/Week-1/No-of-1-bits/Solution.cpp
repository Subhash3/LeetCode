#include <cstdint>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int NO_OF_BITS = 32;
        int i, noOfOnes = 0;

        for (i = 0; i < NO_OF_BITS; i++)
        {
            if (n & 1)
            {
                noOfOnes++;
            }

            n = n >> 1;
        }

        return noOfOnes;
    }
};