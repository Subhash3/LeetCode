#include <string>
#include <vector>
#include <iostream>

#define ALPHABETS_COUNT 26

using namespace std;

class Solution
{
public:
    int computeRangeSum(int l, int r, vector<int> prefixSum)
    {
        int rangeSum;

        rangeSum = prefixSum[r];
        if (l != 0)
        {
            rangeSum = prefixSum[r] - prefixSum[l - 1];
        }

        return rangeSum;
    }

    int computeBeauty(int left, int right, string s, vector<vector<int>> freqPrefixSums)
    {
        int maxFreq, minFreq, freq, i;
        vector<int> letterFreqPrefixSum;

        maxFreq = -1;
        minFreq = -1;

        for (i = 0; i < ALPHABETS_COUNT; i++)
        {
            letterFreqPrefixSum = freqPrefixSums[i];
            freq = this->computeRangeSum(left, right, letterFreqPrefixSum);
            if (freq == 0)
            {
                continue;
            }
            // printf("\t%c occurs %d times\n", i + 97, freq);
            if (maxFreq == -1 || freq > maxFreq)
            {
                maxFreq = freq;
            }
            if (minFreq == -1 || freq < minFreq)
            {
                minFreq = freq;
            }
        }
        // printf("max: %d, min: %d\n", maxFreq, minFreq);

        return maxFreq - minFreq;
    }

    int beautySum(string s)
    {
        int length, i, j, size, beauty, sum;
        vector<vector<int>> freqPrefixSums;

        printf("Preparin...\n");
        for (i = 0; i < ALPHABETS_COUNT; ++i)
        {
            vector<int> freq;
            freqPrefixSums.push_back(freq);
        }

        length = s.length();
        for (i = 0; i < length; ++i)
        {
            for (j = 0; j < ALPHABETS_COUNT; ++j)
            {
                size = freqPrefixSums[j].size();
                if (s[i] - 97 == j)
                {
                    if (size == 0)
                    {
                        freqPrefixSums[j].push_back(1);
                    }
                    else
                    {
                        freqPrefixSums[j].push_back(freqPrefixSums[j][size - 1] + 1);
                    }
                }
                else
                {

                    if (size == 0)
                    {
                        freqPrefixSums[j].push_back(0);
                    }
                    else
                    {
                        freqPrefixSums[j].push_back(freqPrefixSums[j][size - 1] + 0);
                    }
                }
            }
        }
        printf("Done\n");

        // for (i = 0; i < ALPHABETS_COUNT; ++i)
        // {
        //     // printf("%c: [", i + 97);
        //     fflush(NULL);
        //     for (j = 0; j < length; ++j)
        //     {
        //         // printf("%d, ", freqPrefixSums[i][j]);
        //         fflush(NULL);
        //     }
        //     // printf("\b\b]\n");
        //     fflush(NULL);
        // }

        sum = 0;
        for (i = 0; i < length; ++i)
        {
            for (j = i; j < length; ++j)
            {
                // printf("Substring from %d to %d\n", i, j);
                beauty = this->computeBeauty(i, j, s, freqPrefixSums);
                // printf("Beauty of string from %d to %d: %d\n", i, j, beauty);
                sum += beauty;
            }
        }

        return sum;
    }
};