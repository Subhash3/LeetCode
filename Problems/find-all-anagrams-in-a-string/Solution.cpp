#include <bits/stdc++.h>

using namespace std;

#define ALPHABETS_COUNT 26

class Solution
{
public:
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

    vector<int> findAnagrams(string s, string p)
    {
        vector<int> startIndices, freqs, pFreqs;
        int n, m, i, j;
        bool matched;

        n = s.length();
        m = p.length();

        if (n < m)
        {
            return startIndices;
        }

        pFreqs = vector<int>(ALPHABETS_COUNT);
        for (char ch : p)
        {
            pFreqs[ch - 'a'] += 1;
        }

        freqs = vector<int>(ALPHABETS_COUNT);
        for (i = 0; i < m; i++)
        {
            freqs[s[i] - 'a'] += 1;
        }

        freqs[s[m - 1] - 'a'] -= 1;
        for (i = 0; i + m - 1 < n; i++)
        {
            freqs[s[i + m - 1] - 'a'] += 1;
            printVector(freqs);
            printVector(pFreqs);

            matched = true;
            for (j = 0; j < ALPHABETS_COUNT; j++)
            {
                if (freqs[j] != pFreqs[j])
                {
                    matched = false;
                    break;
                }
            }
            if (matched)
            {
                printf("matched\n");
                startIndices.push_back(i);
            }
            freqs[s[i] - 'a'] -= 1;
            printf("\n");
        }

        return startIndices;
    }
};