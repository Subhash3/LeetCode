#include <bits/stdc++.h>

using namespace std;

#define ALPHABETS_COUNT 26

class Solution
{
public:
    vector<int> getCharFreqs(char a)
    {
        vector<int> freq(ALPHABETS_COUNT);

        freq[a - 'a'] += 1;

        return freq;
    }

    void printVector(vector<int> arr)
    {
        int i, n;

        n = arr.size();
        printf("[");
        fflush(NULL);
        for (i = 0; i < n; i++)
        {
            printf("%d, ", arr[i]);
            fflush(NULL);
        }
        printf("\b\b]\n");

        return;
    }

    vector<int> computeRangeSum(int l, int r, vector<vector<int>> prefixSum)
    {
        vector<int> rangeSum, leftFreqs;
        int i;

        rangeSum = prefixSum[r];
        if (l != 0)
        {
            leftFreqs = prefixSum[l - 1];
            for (i = 0; i < ALPHABETS_COUNT; i++)
            {
                rangeSum[i] -= leftFreqs[i];
            }
        }

        return rangeSum;
    }

    vector<int> findAnagrams(string s, string p)
    {
        vector<int> startIndices, freqs, prevFreqs, rangeSumFreqs, pFreqs;
        vector<vector<int>> prefixSumFreqs;
        int n, m, i, j;
        bool matched;

        n = s.length();
        m = p.length();

        for (i = 0; i < n; i++)
        {
            freqs = getCharFreqs(s[i]);
            if (i == 0)
            {
                prefixSumFreqs.push_back(freqs);
                continue;
            }
            prevFreqs = prefixSumFreqs[i - 1];
            for (j = 0; j < ALPHABETS_COUNT; j++)
            {
                freqs[j] += prevFreqs[j];
            }
            prefixSumFreqs.push_back(freqs);
        }

        pFreqs = vector<int>(ALPHABETS_COUNT);
        for (char ch : p)
        {
            pFreqs[ch - 'a'] += 1;
        }

        for (i = 0; i + m - 1 < n; i++)
        {
            rangeSumFreqs = computeRangeSum(i, i + m - 1, prefixSumFreqs);
            matched = true;
            for (j = 0; j < m; j++)
            {
                if (pFreqs[j] != rangeSumFreqs[j])
                {
                    matched = false;
                    break;
                }
            }
            if (matched)
            {
                startIndices.push_back(i);
            }
        }

        return startIndices;
    }
};