#include <vector>
#include <iostream>

using namespace std;

class BitArray
{
public:
    int bitsNeeded, n;
    vector<int> array;
    int SIZE_OF_INT_IN_BITS = 32;

    // Methods
    int getBitArraySize(int bitsNeeded)
    {

        float length = (float)bitsNeeded / (float)SIZE_OF_INT_IN_BITS;
        float decimalPart = length - (int)length;

        return (decimalPart == 0) ? (int)length : (int)length + 1;
    }

    BitArray(int bitsNeeded)
    {
        this->bitsNeeded = bitsNeeded;
        this->n = this->getBitArraySize(bitsNeeded);
        array = vector<int>(this->n);
    }

    bool setBit(int k)
    {

        if (k >= this->bitsNeeded)
        {
            return false;
        }
        this->array[k / SIZE_OF_INT_IN_BITS] |= (1 << (k % SIZE_OF_INT_IN_BITS));

        return true;
    }

    bool clearBit(int k)
    {
        if (k >= this->bitsNeeded)
        {
            return false;
        }
        this->array[k / SIZE_OF_INT_IN_BITS] &= ~(1 << (k % SIZE_OF_INT_IN_BITS));

        return true;
    }

    bool isBitSet(int k)
    {
        if (k >= this->bitsNeeded)
        {
            return false;
        }
        return ((this->array[k / SIZE_OF_INT_IN_BITS] & (1 << (k % SIZE_OF_INT_IN_BITS))) != 0);
    }

    bool toggleBit(int k)
    {
        if (k >= this->bitsNeeded)
        {
            return false;
        }
        this->array[k / SIZE_OF_INT_IN_BITS] ^= (1 << (k % SIZE_OF_INT_IN_BITS));
        return true;
    }

    void clearAllBits()
    {
        int i, size = this->bitsNeeded;
        for (i = 0; i < size; i++)
        {
            this->clearBit(i);
        }

        return;
    }
    void setAllBits()
    {
        int i, size = this->bitsNeeded;
        for (i = 0; i < size; i++)
        {
            this->setBit(i);
        }

        return;
    }

    void display()
    {
        int i, size = this->bitsNeeded;

        printf("\n");
        for (i = 0; i < size; i++)
        {
            printf((this->isBitSet(i)) ? "\x1b[33m1\x1b[0m" : "0");
            if ((i + 1) % 8 == 0)
            {
                printf(" ");
            }
            fflush(NULL); // flushing must be done 'cuz we're not using \n
        }
        printf("\n");

        return;
    }
};

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int i, n, allXor = 0, numsXor = 0;
        int duplicate = -1, missing = -1;
        BitArray *bitArr = NULL;

        n = nums.size();
        bitArr = new BitArray(n);

        for (i = 0; i < n; i++)
        {
            if (bitArr->isBitSet(nums[i] - 1))
            {
                duplicate = nums[i];
            }
            else
            {
                bitArr->setBit(nums[i] - 1);
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