#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int i, n, allXor = 0, numsXor = 0;
        int duplicate = -1, missing = -1;
        vector<int> freq;

        n = nums.size();
        freq = vector<int>(n);

        for (i = 0; i < n; i++)
        {
            freq[nums[i] - 1] += 1;
            if (freq[nums[i] - 1] > 1)
            {
                duplicate = nums[i];
            }
            numsXor ^= (nums[i]);
            allXor ^= (i + 1);
        }
        // Eliminate duplicate from numsXor
        numsXor ^= duplicate;
        missing = numsXor ^ allXor;

        return {duplicate, missing};
    }
};

/*
    Don't worry about the duplicate for now.
    let n = 4 => arr = [1, 2, 3, 4]
    Let 3 be the missing number
    nums = [1, 2, 4]

    missing can be calculated as follows
    (Xor of original arr) XOR (Xor of nums arr)

    a = XOR of original array = 1 ^ 2 ^ 3 ^ 4 ---(1)
    b = XOR of given array    = 1 ^ 2 ^ 4     ---(2)

    a XOR b = (1 ^ 2 ^ 3 ^ 4) ^ (1 ^ 2 ^ 4)   ---(3)

    This eliminates duplicates and leaves us with the missing number which is 3.

    But inorder to find the missing, we need to find the duplicate.
    This can be done in O(N) complexity with a hashmap.
    For the given example, duplicate = 2

    This time Xor of given array contains the duplicate.
    => b = XOR of given array    = 1 ^ 2 ^ 2 ^ 4.
    But we want it without duplicate. Hence, just XOR it with the duplicate since it eliminates one instance of that duplicate.
    => b = b XOR duplicate
    => b = (1 ^ 2 ^ 2 ^ 4) XOR (2)
    => b = (1 ^ 2 ^ 4)

    Now we just have to do (3) to get the missing element.
*/