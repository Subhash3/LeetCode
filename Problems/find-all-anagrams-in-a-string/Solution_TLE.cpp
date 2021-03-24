#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_map<char, int> getCharFreqs(string str, int l, int r)
    {
        unordered_map<char, int> freq;
        int i;

        for (i = l; i <= r; i++)
        {
            freq[str[i]] += 1;
        }

        return freq;
    }

    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> charToFreqMapOfP, freqs;
        vector<int> startIndices;
        int n, m, i;

        n = s.length();
        m = p.length();
        charToFreqMapOfP = getCharFreqs(p, 0, m - 1);

        for (i = 0; i + m - 1 < n; i++)
        {
            freqs = getCharFreqs(s, i, i + m - 1);
            if (freqs == charToFreqMapOfP)
            {
                startIndices.push_back(i);
            }
        }

        return startIndices;
    }
};