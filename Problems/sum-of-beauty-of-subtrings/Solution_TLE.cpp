#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    int computeBeauty(string str, int left, int right)
    {
        int mostFreq = -1, leastFreq = -1, i;
        char ch;
        unordered_map<char, int> freqs;

        // cout << "Sub String: (" << left << ", " << right << ") " << str.substr(left, right + 1) << endl;
        for (i = left; i <= right; ++i)
        {
            ch = str[i];
            if (freqs.find(ch) == freqs.end())
            {
                freqs[ch] = 1;
            }
            else
            {
                freqs[ch] += 1;
            }
        }

        for (auto it : freqs)
        {
            // printf("(%c: %d)\n", it.first, it.second);

            if (mostFreq == -1 || it.second > mostFreq)
            {
                mostFreq = it.second;
            }
            if (leastFreq == -1 || it.second < leastFreq)
            {
                leastFreq = it.second;
            }
        }
        // printf("MostFreqs: %d, leastFreq: %d\n", mostFreq, leastFreq);

        return mostFreq - leastFreq;
    }

    int beautySum(string s)
    {
        int i, j, len, beautySum, b;

        len = s.length();
        beautySum = 0;
        for (i = 0; i < len; i++)
        {
            for (j = i + 2; j < len; j++)
            {
                b = this->computeBeauty(s, i, j);
                // printf("beauty: %d, sum: %d\n", b, beautySum);
                beautySum += b;
                // printf("beauty: %d, sum: %d\n", b, beautySum);
            }
        }

        return beautySum;
    }
};