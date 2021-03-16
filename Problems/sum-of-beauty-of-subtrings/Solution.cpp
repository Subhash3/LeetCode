#include <string>
#include <vector>
#include <iostream>

#define ALPHABETS_COUNT 26

using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int length, i, j, sum, maxFreq, minFreq;
        vector<int> freqs(ALPHABETS_COUNT);

        length = s.length();
        sum = 0;
        for (i = 0; i < length; i++)
        {
            fill_n(freqs.begin(), ALPHABETS_COUNT, 0);
            for (j = i; j < length; j++)
            {
                freqs[s[j] - 97] += 1;
                maxFreq = -1;
                minFreq = -1;
                for (auto freq : freqs)
                {
                    if (freq == 0)
                    {
                        continue;
                    }
                    if (maxFreq == -1 || freq > maxFreq)
                    {
                        maxFreq = freq;
                    }
                    if (minFreq == -1 || freq < minFreq)
                    {
                        minFreq = freq;
                    }
                }
                sum += (maxFreq - minFreq);
            }
        }

        return sum;
    }
};