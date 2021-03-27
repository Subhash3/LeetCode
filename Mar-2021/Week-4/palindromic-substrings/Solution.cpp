#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int i, j, N, subStringLen, count;
        vector<vector<bool>> lookup;

        N = s.length();
        // printf("N: %d\n", N);

        for (i = 0; i < N; i++)
        {
            vector<bool> row(N);
            fill(row.begin(), row.end(), false);
            lookup.push_back(row);
        }

        for (i = 0; i < N; i++)
        {
            // printf("i: %d\n", i);
            lookup[i][i] = true;
            if (i < N - 1)
            {
                lookup[i][i + 1] = (s[i] == s[i + 1]);
            }
        }

        // printf("Checking all suubstrings of all sizes\n");
        for (subStringLen = 3; subStringLen <= N; subStringLen++)
        {
            // printf("Substrings of length: %d are: \n", subStringLen);
            for (i = 0; i < N - subStringLen + 1; i++)
            {
                // printf("From %d to %d\n", i, i + subStringLen - 1);
                // cout << string(s.begin() + i, s.begin() + i + subStringLen) << endl;
                j = i + subStringLen - 1;
                // printf("i: %d, j: %d\n", i, j);
                lookup[i][j] = ((s[i] == s[j]) && (lookup[i + 1][j - 1]));
            }
        }

        for (i = 0; i < N; i++)
        {
            // printf("[");
            fflush(NULL);
            for (j = 0; j < N; j++)
            {
                // printf("%d, ", lookup[i][j]);
                fflush(NULL);
            }
            // printf("\b\b]\n");
        }

        count = 0;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (lookup[i][j])
                {
                    count += 1;
                }
            }
        }

        return count;
    }
};