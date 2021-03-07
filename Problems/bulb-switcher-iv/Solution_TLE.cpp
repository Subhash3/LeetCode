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
    int minFlips(string target)
    {
        int n, i, j, steps;
        BitArray *bulbs = NULL;

        n = target.length();
        bulbs = new BitArray(n);
        steps = 0;

        for (i = 0; i < n; i++)
        {
            if (((target[i] == '1') && (bulbs->isBitSet(i))) || ((target[i] == '0') && (!bulbs->isBitSet(i))))
            {
                continue;
            }
            for (j = i; j < n; j++)
            {
                bulbs->toggleBit(j);
            }
            steps += 1;
        }

        return steps;
    }
};